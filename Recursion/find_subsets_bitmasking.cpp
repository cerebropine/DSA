#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:     
        vector<vector<int>> subsets(vector<int> & nums){
         vector<vector<int>>result;
         int n=nums.size();
         for(int i=0;i<pow(2,n);i++){
             bitset<12>b(i);
             vector<int>res;
             for(int j=0;j<b.size();j++)
             {
                 if(b[j]==1 && j<n) res.push_back(nums.at(j));
             }
             result.push_back(res);
         }
         return result;
        }

};

int main(){
    Solution sol;
    vector<int> res={2,3,4};
    vector<vector<int>> out=sol.subsets(res);
    return 0;
}