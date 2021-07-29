/* 
LCM Challenge

Bob have given a integer N
he have to find a triplet 
X, Y and Z where each of them are less than or equal to 
N and their LCM is maximum.

Input Format
A single Integer 
N

Output Format
A single integer, the maximum LCM Bob can achieve.

Constraints
1≤N≤10^6

Example
Input
7
Output
210
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a , long long b){
		return (b==0)?a:gcd(b,a%b);
}
int main() {
    // your code goes here
		long long n;
		cin>>n;
		long long  prod=0;
		if(n==1|| n==2) prod=n;
		else if(n%2==0)
		{
			if(gcd((n-3),n)==1) prod=n*(n-1)*(n-3);
			else prod=(n-2)*(n-1)*(n-3);
		}
		else prod=n*(n-1)*(n-2);
		
	cout<<prod<<endl;
	return 0;
}
