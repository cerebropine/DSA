#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int primes[n+1];
    int spf[n+1];
    for(int i=0;i<=n;i++){
        primes[i]=1;
        spf[i]=-1;
    }
    primes[1]=0;
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i;i*j<=n;j++){
            if(primes[i*j]==1){
                primes[i*j]=0;
                spf[i*j]=i;
            }
        }
    }

    while(n!=1){
        int con=n;
        map<int,int> order;
        while(spf[con]!=-1){
            order[spf[con]]++;
            con=con/spf[con];
        }
        if(con!=1) order[con]++;
        if(order.size()==2) ans++;
        n--;
    }
    cout<<ans<<endl;

}