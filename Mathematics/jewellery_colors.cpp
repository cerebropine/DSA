#include<bits/stdc++.h>
using namespace std;
#define N 100001
int primes[N];
int main(){
    
    for(int i=0;i<N;i++){
        primes[i]=1;
    }
    primes[1]=0;
    for(int i=2;i*i<N;i++){
        for(int j=i;i*j<N;j++){
            if(primes[i*j]==1){
                primes[i*j]=0;
            }
        }
    }
    int n;
    cin>>n;
    map<int,int> order;
    if(n<=2) cout<<1<<endl;
    else cout<<2<<endl;
    for(int i=2;i<n+2;i++){
        if(primes[i]==1) cout<<1<<" ";
        else cout<<2<<" ";
    }
}