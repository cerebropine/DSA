#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void rightrotate(vector<int>& nums,int i,int j){
        int last=nums.at(j);
        for(int k=j;k>i;k--)
        {
            nums.at(k)=nums.at(k-1);
        }
        nums.at(i)=last;
        
    }
    void leftrotate(vector<int>& nums,int i,int j){
        int first=nums.at(i);
        for(int k=i;k<j;k++)
        {
            nums.at(k)=nums.at(k+1);
        }
        nums.at(j)=first;
        
    }
    
    void permutations(vector<int>& nums, int i){
        if(i==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            rightrotate(nums,i,j);
            permutations(nums,i+1);
            leftrotate(nums,i,j);
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