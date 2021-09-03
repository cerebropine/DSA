#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void set_temp(int k){
        for(int i=0;i<k;i++) temp.push_back(0);
    }
    void comb(int n,int k,vector<int>& temp,int i,int sz){
        if(n<0) return;
        if(i==k){
            //for(int j=0;j<k;j++) cout<<temp.at(j)<<" ";
            
            result.push_back(temp);
            return;
        }
        temp.at(sz)=n;
        comb(n-1,k,temp,i+1,sz+1);
        comb(n-1,k,temp,i,sz);
       
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set_temp(k);
        comb(9,k,temp,0,0);
        vector<vector<int>> finalres;
        for(int i=0;i<result.size();i++)
        {
            if(accumulate(result.at(i).begin(), result.at(i).end(), 0)==n){
                finalres.push_back(result.at(i));
            }
        }
        return finalres;
        
    }
};