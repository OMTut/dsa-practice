/**********************************************************************
 * Given a 1-indexed array of integers numbers that is already sorted 
 * in non-decreasing order, find two numbers such that they add up to
 *  a specific target number. Let these two numbers be numbers[index1]
 *  and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one
 as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. 
You may not use the same element twice.

Your solution must use only constant extra space.
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>&nums, int target) {
   vector<int> result;
   int right = nums.size() - 1;
   int left = 0;
   
   while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == target) {
         result.push_back(left+1);
         result.push_back(right+1);
         break;
      } else if (sum > target) {
         right--;
      } else {
         left++;
      }
   }

   return result;
}

void testSubarray(vector<int>& nums, int target, vector<int>& answer) {
   //print out the vector
   cout << "Vector: ";
   for (int num : nums) {
       cout << num << " ";
   }
   cout << endl;

   //test
   vector<int> testAnswer = twoSum(nums, target);
   if (testAnswer == answer) {
       cout << "Test Passed: " << endl;
   } else {
       cout << "Test failed: " << endl;
   }
}

int main() {

   int target = 9;
   vector<int> vec1 = {2,7,11,15};
   vector<int> answerVec1 = {1,2};
   testSubarray(vec1, target, answerVec1);

   target = 6;
   vector<int> vec2 = {2,3,4};
   vector<int> answerVec2 = {1,3};
   testSubarray(vec2, target, answerVec2);

   target = -1;
   vector<int> vec3 = {-1,0};
   vector<int> answerVec3 = {1,2};
   testSubarray(vec3, target, answerVec3);

   return 0;
}