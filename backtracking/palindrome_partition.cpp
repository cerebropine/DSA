#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> currentList;
        dfs(s, 0, currentList);
        return result;

        
    }
    void dfs(string& s, int start,vector<string>&currentList){
        if(start>=s.length()) result.push_back(currentList);
        for(int end=start;end<s.length();end++){
            if(isPalindrome(s,start,end)){
               currentList.push_back(s.substr(start,end-start+1));
               dfs(s,end+1,currentList);
               currentList.pop_back();
            }
            
        }
    }
    bool isPalindrome(string s, int low, int high){
        while(low<high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    sol.partition("aab");
    return 0;
}