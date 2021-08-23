#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans=get_ans(x,n);
        if(n<0) return 1/ans;
        else return ans;
       
    }
    double get_ans(double x,int n)
    {
       if(n==0) return 1;
       double k=get_ans(x,n/2);
       if(n%2==0) return k*k;
       else return x*k*k;
    }
};

int main(){
    Solution sol;
    double val=sol.myPow(2.00,-2);
}