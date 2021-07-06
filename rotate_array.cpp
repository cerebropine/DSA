#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int temp;
        for(int i=0;i<n/2;i++){
            temp=nums[i];
            nums[i]=nums[n-i-1];
            nums[n-i-1]=temp;
        }
        for(int i=0;i<k/2;i++){
            temp=nums[i];
            nums[i]=nums[k-i-1];
            nums[k-i-1]=temp;
        }
        for(int i=k;i<(n+k)/2;i++){
            temp=nums[i];
            nums[i]=nums[n+k-i-1];
            nums[n+k-i-1]=temp;
        }
    
    }
};

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    int k=3;
    Solution sol;
    sol.rotate(arr,3);
    return 0;
}