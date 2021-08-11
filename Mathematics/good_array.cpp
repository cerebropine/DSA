#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        
        int n=nums.size(); int gcd=0;
        for(int i=0;i<n;i++){
            gcd=__gcd(nums.at(i),gcd);
            if(gcd==1) return true;
            
        }
        return false;
        
    }
};

//https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity