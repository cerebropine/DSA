#include<bits/stdc++.h>
using namespace std;
class Solution{
    void combutil(vector<int> &candidates,int target,int l,vector<int>& v,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(v);
        }
        for(int i=l;i<candidates.size();i++)
        {

            if(candidates[i]<=target){
            v.push_back(candidates[i]);
            combutil(candidates,target-candidates[i],i,v,ans);
            v.pop_back();
            }
        }
    }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates,int target){
            vector<int>vec;
            vector<vector<int>> ans;
            combutil(candidates,target,0,vec,ans);
            return ans;
        }
};

int main(){
    vector<int> can={2,3,6,7};
    int target=7;
    Solution sol;
    sol.combinationSum(can,target);
    return 0;

}