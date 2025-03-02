/******************************************************************
 * Given an array (list) nums consisted of only non-negative integers,
 * find the largest sum among all subarrays of length k in nums.
 * 
 * For example, if the input is nums = [1, 2, 3, 7, 4, 1], k = 3,
 * then the output would be 14 as the largest length 3 subarray sum is
 * given by [3, 7, 4] which sums to 14.
 */
#include <vector>
using namespace std;

int subarray_sum_fixed(vector<int> nums, int k) {
   int window_sum = 0;
   
   //get first window sum
   for (int i = 0; i < k; i++) {
      window_sum += nums[i];
   }

   int largest = window_sum;
   //start sliding the window
   for (int right = k; right < nums.size(); right++) {
      int left = right - k;
      window_sum -= nums[left];
      window_sum += nums[right];
      largest = max(largest, window_sum);
   }
   return largest;

}