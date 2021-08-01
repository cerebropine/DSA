/*
General method to calculate all primes in the range 
2......N is to start with the number 2
, mark it as prime, and mark all its multiples (excluding itself) as not prime. Then, we find the next smallest unmarked number, mark it as prime, and mark all its multiples (excluding itself) as not prime. Continuing this way, we get a list of all primes.

Now, let us say that we modified the above algorithm, and start with N
 instead of 2. We mark it as prime, and mark all its factors (excluding itself) as not prime. Then we find the next greatest unmarked number, mark it as prime, and mark all its factors (excluding itself) as not prime. Continuing this way, we get a list of all primes.

You are given a natural number N. 
You run both the original and modified version of finding
primes for numbers from 2..N.

Output the count of integers that are present in both the lists.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N in a separate line.

Output Format
For each test case, output the count of numbers marked as a prime on a separate line.

Constraints
1≤T≤10^5

2≤N≤10^6

Example
Input
3
2
4
7
Output
1
1
2
*/


#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int primes[N];
int counts[N];

/*
just look at this, for any number x < N/2. 2*x < N. So, x will definitely get
cancelled out when we reach 2*x (or 3*x or any other multiple).

*/

int main() {
    for(int i=0;i<N;i++){
        primes[i]=1;
    }
    primes[1]=0;
    for(int i=2;i*i<N;i++){
        for(int j=i;i*j<N;j++){
            if(primes[i]==1) primes[i*j]=0;
        }
    }
    int count=0;
    for(int i=2;i<N;i++){
        if(primes[i]==1){
            count++;
            counts[i]=count;
        }
        else counts[i]=count;
    }    

       int t; cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            cout<<counts[n]-counts[n/2]<<endl;
        }
    return 0;
}