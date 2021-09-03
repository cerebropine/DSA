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
    vector<vector<int>> combine(int n, int k) {
        set_temp(k);
        comb(n,k,temp,0,0);
        return result;
    }
};
int main(){
    Solution sol;
    int n,k;
    cin>>n>>k;
    vector<vector<int>> finalres=sol.combine(n,k);
    return 0;
}