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


int lengthOfLongestSubstring(string str){
	int currSize = 0, prevSize = 0, stringSize = str.length();

    unsigned int charCheckn;
    vector<bool> char_set(128);

 	if( stringSize <= 1) {
       return stringSize;
	}

   fill(char_set.begin(), char_set.end(), false);

   size_t i = 0, subIdx = 0; 

   do{
      charCheckn = str.at(i); 
      
      if(char_set[charCheckn] ){            //if char is in str
                                            //keep the bigest value
        currSize = max(currSize,  prevSize);
        prevSize = currSize;

        while(char_set[charCheckn]){
           char_set[ str[subIdx++] ] = false;
        }

        currSize   = i - subIdx + 1;
        char_set[charCheckn] = true;

        continue;                         //halt loop
      }

      char_set[charCheckn] = true;
      currSize++;

   }while( ++i < stringSize );

   return max( currSize, prevSize);
}


