/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/




int lengthOfLongestSubstring(string s) {
  int start = 0, end = 0;

  set<char> window;
  int result = 0;

  for(int i = 0; i < s.length(); i++){
      if(!window.count(s[i])) {
          window.insert(s[i]);
          result = max(result, i-start+1);
      }
      else {
          while(window.count(s[i])) {
              window.erase( s[start] );
              start++;
          }
          window.insert(s[i]);
      }
  }
  return result;
}
