/* 
Count of Divisors For Multiple Queries

You are given an array A of N integers.

Count the number of unique prime factors of each element in it.

Input Format

The first line of the input contains a single integer T
, denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains a single integer N.

The second line of each test case contains N space-separated integers 
A[0] A[1] A[2]....A[n]


Output Format

For each test case output a line containing N
space separated integers denoting the number of
prime factors of each of the array element.

Constraints
1≤T≤10

1≤N≤10^5

1≤Ai≤10^6

Example
Input
1
3
10 12 14
Output
2 2 2

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
            if(primes[i*j]==1)
            {
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
        while(n--){
            int element;
            cin>>element;
            map<int,int> order;
            while(spf[element]!=-1){
                order[spf[element]]++;
                element=element/spf[element];
            }
            if(element!=1) order[element]++;
            cout<<order.size()<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}