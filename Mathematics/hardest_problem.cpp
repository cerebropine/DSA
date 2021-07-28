#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        long long test[n];
        long long gcd=0;
        for(int i=0;i<n;i++) 
        {
            scanf("%lld",&test[i]);
            gcd=__gcd(gcd,test[i]);
        }
      if(gcd==1) printf("%d\n" , 1);
      else  printf("%d\n" , 0); 
    }
    
    return 0;
}