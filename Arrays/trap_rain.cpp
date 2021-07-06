#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        if(n==0) return 0;
        vector<int> pmax(n);
        vector<int> smax(n);
        pmax.at(0)=height.at(0);
        for(int i=1;i<n;i++)
        {

            pmax.at(i)=max(pmax.at(i-1),height.at(i));
        }
        smax.at(n-1)=height.at(n-1);
        for(int i=n-2;i>=0;i--){
            smax.at(i)=max(smax.at(i+1),height.at(i));
        }

        for(int i=1;i<n-1;i++){
            ans+=min(pmax.at(i),smax.at(i))-height.at(i);
        }
    return ans;
    }
};

int main(){
    Solution s;
    vector<int> input;
    int  temp;
    while ( cin>>temp && temp != -9999)
    {
        input.push_back(temp);
    }
    int ans=s.trap(input);
    cout<<ans<<endl;
    return 0;
}