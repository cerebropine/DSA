#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();

        int m1=nums.at(0);
        int m2=INT_MIN;
        int c1=1;
        int c2=0;
        
        for(int i=1;i<n;i++){

            if(m1==nums.at(i)) c1++;
            else if(m2==nums.at(i)) c2++;

            else if(c1==0){
                m1=nums.at(i);
                c1++;
            }
            else if(c2==0) 
            {
                m2=nums.at(i);
                c2++;
            }
            
            else {
                c1--;
                c2--;
            }

        }

        c1=0;c2=0;
        for(int i=0;i<n;i++){
            if(nums.at(i)==m1) c1++;
            if(nums.at(i)==m2) c2++;
        }
        if(c1>n/3) result.push_back(m1);
        if(c2>n/3) result.push_back(m2);
       return result;
    }
};

int main(){
    vector<int> arr={2,1,1,3,1,4,5,6};
    Solution sol;
    vector<int> res=sol.majorityElement(arr);
    for(int j=0;j<res.size();j++) cout<<res.at(j)<<" ";
    return 0;
}