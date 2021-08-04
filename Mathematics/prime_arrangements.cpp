#include<bits/stdc++.h>
using namespace std;
#define N 102
const long long M= 1e9+7;
int primes[N];
class Solution {
public:
    int numPrimeArrangements(int n) {
        for(int i=0;i<N;i++){
            primes[i]=1;
        }
        primes[1]=0;
        for(int i=2;i*i<N;i++){
            for(int j=i;i*j<N;j++){
                if(primes[i*j]==1) primes[i*j]=0;
            }
        }
       int count=0;
       for(int i=1;i<=n;i++){
           if(primes[i]==1){
               count++;
           }
       }
       long long ans=1;
       for(long long i=1;i<=count;i++){
           ans=((ans%M)*(i%M))%M;
       }
        for(long long  i=1;i<=n-count;i++){
           ans=((ans%M)*(i%M))%M;
       }
       return ans;  
    }
};

int main(){

    int n;
    cin>>n;
    Solution sol;
    cout<<sol.numPrimeArrangements(n)<<endl;
}