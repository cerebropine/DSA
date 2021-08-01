/*
Common Divisors


You will be given T pairs of natural numbers A and B.

For each pair, output the number of common divisors between the two numbers.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains two integers A and B.

Output Format
For each test case, output the number of common divisors between
the given pair on a seperate line.

Constraints
1≤T≤10^2

1≤A,B≤10^9

Example
Input
3
100000 100000
12 24
747794 238336
Output
36
6
2

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
   int t;
    cin>>t;
    while(t--){

        long long a,b;
        cin>>a>>b;
        long long gcd=__gcd(a,b);
        long long count=0;
        for(int i=2;i*i<=gcd;i++){
            if(gcd%i==0){
                if(gcd/i!=i) count=count+2;
                else count++;
            }
        }
        if(gcd>=2) count=count+2;
				else count=1;
        cout<<count<<endl;
    }

    return 0;
}