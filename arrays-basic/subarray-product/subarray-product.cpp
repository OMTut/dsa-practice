/***************************************************************************
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */
#include <vector>
#include <iostream>
using namespace std;

int findSubarrayProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(nums[i], maxProduct * nums[i]);
        minProduct = min(nums[i], minProduct * nums[i]);

        result = max(result, maxProduct);
    }

    return result;
}

void testSubarray(vector<int>& nums, int answer) {
    //print out the vector
    cout << "Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    //test
    int testAnswer = findSubarrayProduct(nums);
    if (testAnswer == answer) {
        cout << "Test Passed: " << testAnswer << " = " << answer << endl;
    } else {
        cout << "Test failed: " << testAnswer << " = " << answer << endl;
    }
}

int main() {

    vector<int> vec1 = {2,3,-2,4};
    int answerVec1 = 6;
    testSubarray(vec1, answerVec1);

    vector<int> vec2 = {-2,0,-1};
    int answerVec2 = 0;
    testSubarray(vec2, answerVec2);

    return 0;
}