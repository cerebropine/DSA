#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums.at(0);
        int candidate=nums.at(0);
        
        int votes=1;
        for(int i=1;i<nums.size();i++){
            if(!votes){
                candidate=nums[i];
            }
            if(candidate==nums[i]){
                votes++;
            }
            else{
                votes--;
            }
        }
        return candidate;
    }
};

int main(){
    vector<int> arr={3,2,3};
    Solution sol;
    cout<<sol.majorityElement(arr)<<endl;
}