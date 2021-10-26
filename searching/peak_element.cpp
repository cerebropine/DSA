#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int n=nums.size();
        int m;
        if(nums.size()==1)
            return 0;
        while(l<=h){
            m=(l+h)/2;
            if(m==0){
                if(nums[m]>nums[m+1])
                    return m;
                else
                    l=m+1;
            }
            else if(m==n-1){
                if(nums[m]>nums[m-1])
                    return m;
                else
                    h=m-1;
            }
            else{
                if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                    return m;
                else
                    if(nums[m]<nums[m+1])
                        l=m+1;
                    else
                        h=m-1;
                    
            }
        }
        return -1;
    }
};