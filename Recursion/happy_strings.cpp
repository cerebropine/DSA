#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    void generate_strings(int n,vector<string>& str_store,int i,string& str){
        
        if(str.length()==n){
            result.push_back(str);
            return;
        } 
        else{
            for(int k=0;k<str_store.size();k++){
                string lastchar(1,str.back());
                if(str_store.at(k)==lastchar) continue;
                str+=str_store.at(k);
                generate_strings(n,str_store,(i+1)%3,str);
                str.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
       vector<string>str_store={"a","b","c"};
       string str="";
       generate_strings(n,str_store,-1,str);
       if(k<=result.size())
        return result.at(k-1);
       else return "";
    }
};
int main(){
    Solution sol;
    cout<<sol.getHappyString(1,3)<<endl;
    return 0;
}