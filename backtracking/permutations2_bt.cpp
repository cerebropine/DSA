
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void swap(vector<int>& nums,int i, int j){
        int temp=nums.at(i);
        nums.at(i)=nums.at(j);
        nums.at(j)=temp;
    }
     void permuteHelper(vector<int>& nums,int i) {
        if(i==nums.size()-1){
            result.push_back(nums);
            return;
        }
        /*1 <= nums.length <= 8
        -10 <= nums[i] <= 10
        */
       int freq[20]={0};
       for(int j=i;j<nums.size();j++){
           if(freq[nums.at(j)+10]==0){
              swap(nums,i,j);
              permuteHelper(nums,i+1);
              swap(nums,i,j);
           }
          freq[nums.at(j)+10]++;
       }
       
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permuteHelper(nums,0);
        return result;
        
    }
};

int main(){
    vector<int> nums = {1,1,2};
    Solution sol;
    sol.permuteUnique(nums);
    return 1;
}