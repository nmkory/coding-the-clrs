// Author: Nicholas Kory, SID# 100319778, nkory@ucmerced.edu
// CSE 100 Spring Semester 2019
#include <iostream>
#include <tuple>

using namespace std;

//returns tuple <index for max left, index for max right, sum max cross array>
tuple <int,int,int32_t> findMaxCrossingSubarray(int32_t* array, int low,
                                                int mid, int high)
{
  int max_left = mid;
  int max_right = mid;
  int32_t left_sum = INT32_MIN;
  int32_t right_sum = INT32_MIN;
  int32_t sum = 0;

  //find sum for left part of cross
  for (int i = mid; i >= low; i--)
  {
    //track running left sum
    sum = sum + array[i];

    //if the new sum is greater than old, update with value and index
    if (sum > left_sum)
    {
      left_sum = sum;
      max_left = i;
    }  //left value and index updated
  } //the left sum and index have been found

  //reset sum
  sum = 0;

  //find sum for right part of cross
  for (int j = mid + 1; j <= high; j++)
  {
    //track running right sum
    sum = sum + array[j];

    //if the new sum is greater than old, update with value and index
    if (sum > right_sum)
    {
      right_sum = sum;
      max_right = j;
    }  //right value and index updated
  } //the right sum and index have been found

  //add the left and right for total value
  return (make_tuple (max_left, max_right, left_sum + right_sum));
}  //findMaxCrossingSubarray()


//returns tuple <index for max left, index for max right, sum max subarray>
tuple <int,int,int32_t> findMaximumSubarray(int32_t* array, int low, int high)
{
  //base case: only one element, return the value of that one element
  if (high == low)
    return (make_tuple (low, high, array[low]));

  //need to recurse down and check the cross subarray for this array
  else
  {
    int mid = ((low + high) / 2);

    tuple <int, int, int32_t> left =
      findMaximumSubarray(array, low, mid);

    tuple <int, int, int32_t> right =
      findMaximumSubarray(array, mid + 1, high);

    tuple <int32_t, int32_t, int32_t> cross =
      findMaxCrossingSubarray(array, low, mid, high);

    //if the left-hand side has the greatest sum
    if (get<2>(left) >= get<2>(right) && get<2>(left) >= get<2>(cross))
      return left;

    //else if the right-hand side has the greatest sum
    else if (get<2>(right) >= get<2>(left) && get<2>(right) >= get<2>(cross))
      return right;

    //else it must be the max cross subarray
    else
      return cross;
  }  //end of recursions and checking subarray
}  //findMaximumSubarray()


int main(int argc, char* argv[])
{
  int length;
  int32_t* array;

  //first cin is the length of the array to be sorted
  cin >> length;
  array = new int32_t [length];

  //load the array of deltas from input, do not sort
  for (int i = 0; i < length; i++)
    cin >> array[i];

  //divide and conquer for max subarray indicies and value
  tuple <int, int, int32_t> maxSubarray =
    findMaximumSubarray(array, 0, length - 1);

  cout << get<2>(maxSubarray);

  //free allocated space
  delete[] array;

  return 0;
}  //main()
