/*A natural number is called three-prime if it has exactely three divisors.

You are given an array A of N
 numbers, output the sum of all the three-prime numbers in the array.

Input Format
The first line of the input contains a single integer T
 denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains a single integer N.

The second line contains N space-separated integers 
A[0],A[1],...,A[N−1]

Output Format
For each test case, output the sum of all three-prime numbers on a seperate line.

Constraints
1≤T≤10
1≤N≤10^5
1≤Ai≤10^9

Example
Input
1
3
4 5 6
Output
4

*/

#include <bits/stdc++.h>
using namespace std;
#define N 100001
int primes[N];
int main() {
    // your code goes here
    for(int i=0;i<N;i++){
        primes[i]=1;
    }
    primes[1]=0;
    for(int i=2;i*i<N;i++){
        for(int j=i;i*j<N;j++)
        {
            if(primes[i*j]==1) primes[i*j]=0;
        }
    }




    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    long long ans=0;
    while(n--)
    {
        long long sum=0;
        long long element;
        cin>>element;
        long long root=sqrt(element);
        if(root*root==element){
            if(primes[root]) sum+=element;
        }
        ans+=sum;
       
    }  
    cout<<ans<<endl;

}

    return 0;
}