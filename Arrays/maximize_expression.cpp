#include<bits/stdc++.h>
using namespace std;
#define lli long long int

class solution {
  
   public:
       
    long long maximize_expression(int n ,  lli  p , lli  q , lli  r , vector<lli>& arr) {
        long long ans=LLONG_MIN;
         
        vector<lli> PMAX(arr.size());
        vector<lli> SMAX(arr.size());
        prefix_max(PMAX,arr,p,n);
        suffix_max(SMAX,arr,r,n);
        for(int i=0; i<n;i++){
            ans=max(PMAX[i]+(arr[i]*q)+SMAX[i], ans);
        }
        return ans;

    }
    void prefix_max(vector<lli>& PMAX, vector<lli>& arr, lli  p,int  n){
        PMAX[0]=p*arr[0];
        for(int i=1;i<n;i++){
            PMAX[i]=max(PMAX[i-1],p*arr[i]);
        }
    }
        void suffix_max(vector<lli>& SMAX,vector<lli>& arr, lli  r,int n){
        SMAX[n-1]=r*arr[n-1];
        for(int i=n-2;i>=0;i--){
            SMAX[i]=max(SMAX[i+1],r*arr[i]);
        }
    }
};

int main()
{
    lli  n,p,q,r;
    //5 1 2 3
    // 1 2 3 4 5
    cin>>n>>p>>q>>r;
    
    vector<lli> arr;
    lli  temp;
    while ( cin>>temp )
    {
        arr.push_back(temp);
    }
    solution sol;
    lli  ans=sol.maximize_expression(n,p,q,r,arr);
    cout<<ans<<endl;
    return 0;
}