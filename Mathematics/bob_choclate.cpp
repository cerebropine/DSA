#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    long long product=1;
    int begin=-1;int end=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            begin=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]==1){
            end=i;
            break;
        }
    }
    if(begin==-1 && end==-1) cout<<0<<endl;
    else{
        int b=begin;
        for(int i=begin+1;i<=end;i++){
            if(nums[i]==1){
                product*=(i-b);
                b=i;
            }
    }
    cout<<product<<endl;
    }
}