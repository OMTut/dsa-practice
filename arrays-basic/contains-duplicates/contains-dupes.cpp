/*******************************************************************
 * Given an integer array nums, return true if any value appears at 
 * least twice in the array, and return false if every element is 
 * distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool containsDupes(vector<int>& nums) {
   //order doesn't matter. using unordered map for o(1) access
   unordered_map<int, int> numsMap;
   //look for num in numsMap, return true if found
   for (int num : nums) {
      if (numsMap.find(num) != numsMap.end()) { return true; }
      
      //if not found, put it in the map
      numsMap[num] = 1; // 1 is arbitary
   }

   return false;
}

void testContainsDupes(vector<int>& nums) {
   cout << "Vector: { ";
   for (int num : nums) {
      cout << num << " ";
   }
   cout << " }" << endl;
   cout << "Contains Dupes: ";
   if (containsDupes(nums)) {
      cout << "true";
   } else {
      cout << "false";
   }
   cout << endl;
}


int main() {
   vector<int> vec1 = {1,2,3,1};
   vector<int> vec2 = {1,2,3,4};
   vector<int> vec3 = {1,1,1,3,3,4,3,2,4,2};

   testContainsDupes(vec1);
   testContainsDupes(vec2);
   testContainsDupes(vec3);
}