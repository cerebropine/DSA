#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        string S;
        helper(s,S,0,0);
        return res;
    }
    void helper(string S,string s,int i,int count){
        if(i>12) return;
        if(i>S.length()-1){
            if(count==3 && s.length()-3==S.length())
                res.push_back(s);
            return;
        }
        if(s.empty()){
            
        }
        else{
            s=s+".";
            count++;
        }
        if(i<S.length()){
            if(stoi(string()+S[i])<=255)
               helper(S,s+to_string(stoi(string()+S[i])),i+1,count);
            else return;
        }
        if(i+1<S.length()){
             if(stoi(string()+S[i]+S[i+1])<=255)
                helper(S,s+to_string(stoi(string()+S[i]+S[i+1])),i+2,count);
            else return;
        }
        if(i+2<S.length()){      
            if(stoi(string()+S[i]+S[i+1]+S[i+2])<=255)
                helper(S,s+to_string(stoi(string()+S[i]+S[i+1]+S[i+2])),i+3,count);
            else return;
        }
        
    }
};

int main(){
    Solution sol;
    sol.restoreIpAddresses("010010");

}