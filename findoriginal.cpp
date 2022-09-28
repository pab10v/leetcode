/*
An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
 

Constraints:

1 <= changed.length <= 105
0 <= changed[i] <= 105

*/

#include <iostream>
//#include <iterator>

#include <map>
#include<algorithm>

#include <vector>
using namespace std;

vector<int> findOriginal(vector<int>& changed)
{
	map<int, int> Freqs;
    size_t listSize = changed.size();	
	vector<int> result;

    bool traverse = (listSize > 1) && ( (listSize % 2)==0 ) ? true: false;  
    
    if(traverse){

	    sort(changed.begin(), changed.end());
        for (auto val:changed) Freqs[val]++;
   
        for (auto val:changed) {
           try{
                if ( Freqs[2 * val] && Freqs[val] ) {
                    result.push_back(val);
                    Freqs[val]--;
                    Freqs[2 * val]--;
                 }

            } catch (const std::out_of_range& oor) {  //cout << oor.what() << '\n';
                result.clear();
                break; //the loop
            } 
        }

       for(auto val=Freqs.cbegin(); val != Freqs.cend(); val++)
          if( val->second ) return {}; 
    }    
	return result;

}

//drive code
int main()
{ 
	vector<int> changed = {0,0,0,1,1,2}; 
	vector<int> result = findOriginal(changed);

	// Print the resultult list
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}
