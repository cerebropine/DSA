
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int count=0;int sum=0;
            int res=sqrt(double(nums.at(i)));
            if(res*res==nums.at(i)) continue;
            for(int j=2;j*j<=nums.at(i);j++)
            {
                if(nums.at(i)%j==0){count+=2;sum+=j+nums.at(i)/j;}
                if(count>2) break;
            }
            if(count==2) ans+=sum+nums.at(i)+1;
        }
       return ans; 
    }
};

int main(){
    vector<int>test={21,4,7};
    Solution sol;
    cout<<sol.sumFourDivisors(test)<<endl;
    return 0;
}