#include<bits/stdc++.h>
using namespace std;

int minSwap(int *arr,int n,int k){
    int nlegalElements=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            nlegalElements++;
    }
    if(nlegalElements==0) return 0;
    int count=0;
    for(int i=0;i<nlegalElements;i++){
        if(arr[i]<=k) count++;
    }
    int ans=INT_MIN;
    ans=max(ans,count);
    for(int j=nlegalElements;j<n;j++){
        if(arr[j-nlegalElements]<=k) count--;
        if(arr[j]<=k) count++;
        ans=max(count,ans);

    }
    return nlegalElements-ans;
}

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout<<minSwap(arr,n,k)<<endl;
    }
    return 0;
}