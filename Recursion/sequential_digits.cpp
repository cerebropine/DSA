#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sequence(int low ,int high, string str,int l,vector<int>& result){
        str+=to_string(l);
        int val=stoi(str);
        if(val<=high && val>=low) result.push_back(val);
        if(l==9 || val> high) return;
        sequence(low,high,str,l+1,result);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<=9;i++){
            string str;
            sequence(low,high,str,i,result);
        }
        sort(result.begin(),result.end());
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> res=sol.sequentialDigits(100,300);
    return 0;
}