/* COUNTING PRIMES : 

You are given a non-negative number N.

Count the number of prime numbers less than or equal to N.

Input Format
The first line of the input contains a single integer 
T denoting the number of test cases.

The description of 
T  test cases follows.Next T lines each contain a single integer N.

Output Format
For each test case, output the number of prime numbers less than or equal to 
N on a seperate line.

Constraints
1≤T≤1e5

0≤N≤1e6

EXAMPLE

Input
2
1
10
Output
0
4

*/


#include <iostream>
using namespace std;
#define max_m 1000001
int primes[max_m];
int pre[max_m];

int main() {
        // your code goes here
		for(int i=1;i<max_m;i++) 
		{
		primes[i]=1;
		pre[i]=0;
		}
		primes[1]=0;
		primes[0]=0;
		for(int i=2;i*i<=max_m;i++){
            for(int j=i;j*i<=max_m;j++){
                    if(primes[i*j]==1){
                            primes[i*j]=0;
                    }
            }
		}
		int ans=0;
		pre[0]=0;
		for(int i=1;i<=max_m;i++){
            if(primes[i]==1){
                    ans++;
                    pre[i]=ans;
            }
            else pre[i]=ans;
		}
		int t;
		cin>>t;
		while(t--){
            int n;
            cin>>n;			
            cout<<pre[n]<<endl;
		}
    return 0;
}

/* leetcode solution 
#include <iostream>
using namespace std;
#define max_m 5000001

class Solution {
public:
    int countPrimes(int n) {
     if(n==0)
       return 0;
    int primes[n+1];
    int pre[n+1];
    setprimes(n,primes,pre);
    return pre[n-1];
        
    }
    
    void setprimes(int n,int primes[],int pre[]){
        
        for(int i=1;i<n;i++) 
		{
		primes[i]=1;
		pre[i]=0;
		}
		primes[1]=0;
		primes[0]=0;
		for(int i=2;i*i<n;i++){
            for(int j=i;j*i<n;j++){
                    if(primes[i*j]==1){
                            primes[i*j]=0;
                    }
            }
		}
		int ans=0;
		pre[0]=0;
		for(int i=1;i<n;i++){
            if(primes[i]==1){
                    ans++;
                    pre[i]=ans;
            }
            else pre[i]=ans;
		}
    }
};












*/