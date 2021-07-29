
/*
Prime-Factorization(Multiple Queries)

Given a number N, print all its unique prime factors and their exponents in N.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N in a separate line.


Output Format
For each test case, for each prime factor of the number N in that test case, 
output two space separated integers: the prime factor and its power in N.

Prime factors should be printed in increasing order.

Constraints

1≤T≤10^5
1≤N≤10^6

Example
Input
2
100
35
Output
2 2
5 2
5 1
7 1

*/

#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int primes[N];
int spf[N];
int main() {
    // your code goes here
    for(int i=0;i<N;i++){
        primes[i]=1;
        spf[i]=-1;
    }
    primes[1]=0;
    for(int i=2;i*i<N;i++){
        for(int j=i;i*j<N;j++){
            if(primes[i*j]==1){
                primes[i*j]=0;
                spf[i*j]=i;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      map<int, int> order;
      while(spf[n]!=-1){
          order[spf[n]]++;
          n=n/spf[n];
      } 
      if(n!=1) order[n]++; 
      for (auto i = order.begin(); i
         != order.end(); i++){
             cout<<i->first<<" "<<i->second<<endl;
         }
    }

    return 0;
}