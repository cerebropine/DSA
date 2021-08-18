#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    void powerset(vector<int>& nums,vector<int>& res,int i,int sz) {
        if(i==nums.size()){
            result.push_back(res);
            return;
        }
        res.at(sz)=nums.at(i);
        powerset(nums,res,i+1,sz+1);
        res.at(sz)=-11;
        powerset(nums,res,i+1,sz);
        }
    vector<vector<int>> subsets(vector<int> & nums){
        vector<int> res={-11,-11,-11};
        powerset(nums,res,0,0);
        for(int i=0;i<result.size();i++){
            for(int j=result.at(i).size()-1;j>=0;j--){
                if(result.at(i).at(j)==-11) result.at(i).pop_back();
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    vector<vector<int>> out=sol.subsets(nums);

}