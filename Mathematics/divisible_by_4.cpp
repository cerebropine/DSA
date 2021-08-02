/*
Divisible Pairs

You are given an array A of N
 numbers, output the count of pairs in the array whose sum is divisible by 4.

Input Format
The first line of the input contains a single integer 
T
 denoting the number of test cases.

The description of 
T
 test cases follows.

The first line of each test case contains a single integer 
N
.

The second line contains 
N
 space-separated integers 
A[0],A[1]..... A[N−1] representing the array numbers.

Output Format
For each test case, output the count of pairs in the array whose sum is divisible by 
4
 on a separate line.

Constraints
1≤T≤10

1≤N≤10^5

1≤Ai≤10^6

Example
Input
1
5
2 2 1 7 5
Output
3

*/


#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
		int t;
		cin>>t;
		while(t--){
				int n;
				cin>>n;
				int nums[n];
				vector<int>rem(4,0);
				for(int i=0;i<n;i++){
						cin>>nums[i];
						rem.at(nums[i]%4)++;
				}
				int ans=0;
				ans+=rem[0]*(rem[0]-1)/2;
				ans+=rem[2]*(rem[2]-1)/2;
				ans+=rem[1]*rem[3];
				cout<<ans<<endl;
				
				
				
		}
    return 0;
}