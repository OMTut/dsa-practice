/***************************************************************************
 * Given an integer array `nums`, find the subarray with the largest sum, and return _its sum_.
 * Example 1:**
   **Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]
   **Output:** 6
   **Explanation:** The subarray [4,-1,2,1] has the largest sum 6.
   **Example 2:**
   **Input:** nums = [1]
   **Output:** 1
   **Explanation:** The subarray [1] has the largest sum 1.
   **Example 3:**
   **Input:** nums = [5,4,-1,7,8]
   **Output:** 23
   **Explanation:** The subarray [5,4,-1,7,8] has the largest sum 23.

   Notes on this: This is using Kadane's algorithm to find the maximum sum of
                  a contiguous subarray. O(n)
 */
#include <vector>
#include <iostream>
using namespace std;

int findSubarraySum(vector<int>& nums) {
    if (nums.size() == 1) { return nums[0]; }
    
    // track largestSum and currentSum;
    int largestSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum += nums[i]);
        largestSum = max(largestSum, currentSum);
    }

    return largestSum;
}

void testSubarray(vector<int>& nums, int answer) {
    //print out the vector
    cout << "Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    //test
    int testAnswer = findSubarraySum(nums);
    if (testAnswer == answer) {
        cout << "Test Passed: " << testAnswer << " = " << answer << endl;
    } else {
        cout << "Test failed: " << testAnswer << " = " << answer << endl;
    }
}

int main() {

    vector<int> vec1 = {1,2,3,4,5};
    int answerVec1 = 15;
    testSubarray(vec1, answerVec1);

    vector<int> vec2 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int answerVec2 = 6;
    testSubarray(vec2, answerVec2);

    vector<int> vec3 = {1};
    int answerVec3 = 1;
    testSubarray(vec3, answerVec3);

    return 0;
}