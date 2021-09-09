#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    void permutations(vector<int>& nums, int i){
        if(i==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            int temp=nums.at(i);
            nums.at(i)=nums.at(j);
            nums.at(j)=temp;
            permutations(nums,i+1);
            temp=nums.at(i);
            nums.at(i)=nums.at(j);
            nums.at(j)=temp;
        }
        
      
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums,0);
        return result;
        
    }
};

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> Output= {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    Solution sol;
    sol.permute(nums);
    return 1;
}