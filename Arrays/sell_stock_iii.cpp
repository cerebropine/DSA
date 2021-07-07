#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {

        int n=prices.size();
        vector<int> prefixmin(n);
        vector<int>suffixmax(n);
        vector<int>prefixprofit(n);
        vector<int>suffixprofit(n);
        prefixmin.at(0)=prices.at(0);
        suffixmax.at(n-1)=prices.at(n-1);
        // prefix minimum
        for(int i=1;i<n;i++){
            prefixmin.at(i)=min(prefixmin.at(i-1),prices.at(i));
        }
        //prefix profit which will tell the best transaction till ith day
        prefixprofit.at(0)=0;
        for(int i=1;i<n;i++){
            prefixprofit.at(i)=max(prefixprofit.at(i-1),prices.at(i)-prefixmin.at(i-1));
        }

        //suffix minimum
        for(int i=n-2;i>=0;i--){
            suffixmax.at(i)=max(suffixmax.at(i+1),prices.at(i));
        }

        //suffix profit which will tell the best transaction after the ith day
        suffixprofit.at(n-1)=0;
        for(int i=n-2;i>=0;i--){
            suffixprofit.at(i)=max(suffixprofit.at(i+1),suffixmax.at(i+1)-prices.at(i));
        }

        // for each prefixprofit and suffixprofit chose the best combination
        int ans=suffixprofit.at(0);
        for(int i=1;i<n;i++){
            ans=max(prefixprofit.at(i-1)+suffixprofit.at(i),ans);
        }

     return ans;  
    }
};

int main(){
    vector<int> arr={2,1,4};
    Solution sol ;
    cout<<sol.maxProfit(arr)<<endl;
    return 0;
}