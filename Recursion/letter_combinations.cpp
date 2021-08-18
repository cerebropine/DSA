#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>result;
    void letCombo(string &digits,vector<vector<char>>& digitMap,vector<char>& chararr,int sz){
      if(sz==digits.size()){
          string out="";
          for(char ch : chararr){
              out+=ch;
          }
          result.push_back(out);
          return;
      }
      for(int i=0;i<digitMap.at(digits.at(sz)-'0').size();i++){
          chararr.at(sz)=digitMap.at(digits.at(sz)-'0').at(i);
          letCombo(digits,digitMap,chararr,sz+1);
      }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            vector<string> res;
            return res;
        }
        
        vector<vector<char>> digitMap{{},{},{'a','b','c'},{'d','e','f'},
                                       {'g','h','i'},{'j','k','l'},
                                       {'m','n','o'},{'p','q','r','s'},
                                       {'t','u','v'},{'w','x','y','z'}};
        vector<char> chararr(digits.size());
        letCombo(digits,digitMap,chararr,0);
        return result;
    }
};


int main(){
    string inp="23";
    Solution sol;
    vector<string> res=sol.letterCombinations(inp);
    return 0;
}