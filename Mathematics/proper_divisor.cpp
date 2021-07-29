/* 
Divisor Summation

You are given a natural number N. Output the sum of all its proper divisors.
A Proper Divisor of a natural number is the divisor 
that is strictly less than that number.

Input Format

The first line of the input contains a single integer T
, denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N.

Output Format

For each test case, output the sum of all proper divisors of N on a seperate line.

Constraints

1<=T<=10^2
1<=N<10^9

Example

Input
3
2
10
20
Output
1
8
22

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int sum=0;
        if(n==1) cout<<sum<<endl;
        else
        {
        sum=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(i==n/i) sum=sum+i;
                else sum=sum+i+n/i;
            }
        }
        cout<<sum<<endl;
        }
    }
}