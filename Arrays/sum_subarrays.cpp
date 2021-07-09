#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        int ans=0;
        long long modulo=1e9+7;
        for(int i=0;i<n;i++){
            long long temp=((i+1)%modulo * (n-i) %modulo)%modulo;
            ans=(ans%modulo+(((temp%modulo) * (a[i]%modulo))%modulo)%modulo)%modulo;
        }
        return ans;
    }
};

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n+5];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution sol;
        cout<<sol.subarraySum(a,n)<<endl;
    }
    return 0;
}