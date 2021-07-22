#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        long long get_lcm(long long A,long long B){
            if(A==0) return 0;
            long long maxm=max(A,B);
            long long minm=min(A,B);
            long long temp;
            while(maxm%minm!=0){
                temp=minm;
                minm=maxm%minm;
                maxm=temp;
            }
            return (A*B)/minm;
        }

        string getResult(long long N, long long A,long long B, long long K){
            long long lcm=get_lcm(A,B);
            long long solved=N/A+N/B - 2*(N/lcm);
            if(solved>=K) return "Win";
            else return "Lose";

        }



};

int main(void){
    long long t;
    cin>>t;
    while(t--){
        long long N,A,B,K;
        cin>>N>>A>>B>>K;
        Solution sol;
        cout<<sol.getResult(N,A,B,K)<<endl;
    }

}
