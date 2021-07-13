#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max_num=INT_MIN;
        int min_num=INT_MAX;
        int n=nums.size();
        if(n<=1) return 0;
        for(int i=0;i<n;i++){
            max_num=max(max_num,nums.at(i));
            min_num=min(min_num,nums.at(i));
        }
        if(max_num==min_num) return 0;
        int gap=(max_num-min_num)/(n-1);
        if(gap*(n-1)+min_num!=max_num) gap++;
        int no_buckets=1+(max_num-min_num)/gap;
        vector<pair<int,int>> bucketarray(no_buckets,make_pair(INT_MAX, INT_MIN));;
        for(int i=0;i<n;i++){
            bucketarray.at((nums[i]-min_num)/gap).first=min(bucketarray.at((nums[i]-min_num)/gap).first,nums[i]);
            bucketarray.at((nums[i]-min_num)/gap).second=max(bucketarray.at((nums[i]-min_num)/gap).second,nums[i]);
        }
        int ans=0;
        int i=0,j=1;
        while(i<no_buckets-1 && j<no_buckets){
            if(bucketarray.at(i).second==INT_MIN) i++;
            else if(bucketarray.at(j).first==INT_MAX) j++;
            else
            {
                 ans=max(ans,bucketarray.at(j).first-bucketarray.at(i).second);
                 i++;
                 j++;
            }
        }
        return ans;
       
    }
};

int main(){
    vector<int> arr={100,3,2,1};
    Solution sol;
    cout<<sol.maximumGap(arr)<<endl;
    return 0;
}