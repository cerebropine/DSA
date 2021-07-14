#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
      int n=nums.size();
      int ans=0;
      int i=0;
      while(i<n){
          int value=i;
          int con=nums[value];
          int current=nums[value];
          int next=nums[current];
          int count=0;
          while(con!=next){
              nums[current]=value;
              value=current;
              current=next;
              next=nums[current];
              count++;
              i++;
          }
          nums[current]=value;
          count++;
          ans=max(count,ans);
          i++;
      } 
      return ans;       
    }
};

int main(){

    vector<int> arr={0,3,2,1,4};
    Solution sol;
    cout<<sol.arrayNesting(arr)<<endl;
    return 0;
}