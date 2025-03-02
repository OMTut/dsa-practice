/********************************************************************
 * Given a string original and a string check, find the starting index of all substrings of original that is an anagram of check. The output must be sorted in ascending order.

Parameters
original: A string
check: A string
Result
A list of integers representing the starting indices of all anagrams of check.
Examples
Example 1
Input: original = "cbaebabacd", check = "abc"

Output: [0, 6]

Explanation: The substring from 0 to 2, "cba", is an anagram of "abc", and so is the substring from 6 to 8, "bac".

Example 2
Input: original = "abab", check = "ab"

Output: [0, 1, 2]

Explanation: All substrings with length 2 from "abab" are anagrams of "ab".

Constraints
1 <= len(original), len(check) <= 10^5
Each string consists of only lowercase characters in the standard English alphabet.

thoughts: time: O(n)
 */
#include <vector>
#include <string>
using namespace std;

vector<int> find_all_anagrams(string& original, string& check) {
   // get sizes and see if check length is the window size
   int original_length = original.length();
   int check_length = check.length();
   if (check_length > original_length) { return {}; };

   vector<int> result;

   // stores frequency of each char in check and current window
   vector<int> check_counter(26,0);
   vector<int> window(26,0);

   //get first window
   for (int i = 0; i < check_length; i++) {
      check_counter[check[i] - 'a']++;
      window[original[i] - 'a']++;
   }
   if (window == check_counter) result.emplace_back(0);

   //get the rest
   for (int i = check_length; i < original_length; i++) {
      window[original[i - check_length] - 'a']--;
      window[original[i] - 'a']++;
      if (window == check_counter) {
         result.emplace_back(i - check_length + 1);
      }
   }
   return result;

}

