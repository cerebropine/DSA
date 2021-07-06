#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prefixmin(n);
        vector<int>suffixmax(n);
        prefixmin.at(0)=prices.at(0);
        suffixmax.at(n-1)=prices.at(n-1);
        for(int i=1;i<n;i++){
            prefixmin.at(i)=min(prefixmin.at(i-1),prices.at(i));
        }
        for(int i=n-2;i>0;i--){
            suffixmax.at(i)=max(suffixmax.at(i+1),prices.at(i));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,suffixmax.at(i)-prefixmin.at(i));
        }
    return ans;
    }
};

int main(){
    vector<int> arr={7,1,5,3,6,4};
    Solution sol ;
    cout<<sol.maxProfit(arr)<<endl;

}