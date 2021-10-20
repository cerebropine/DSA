/*
Given a sorted array of distinct integers 

nums and a target value, print the index if the 
target is found. If not, print the index where it would be if it were inserted in order.
You must write an algorithm with O(log(n)) runtime complexity.

Input Format

The first line of input contains N, size of the array
The second line of input contains N space-separated array elements 
nums[0],........,nums[N−1]
The third line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.
Each test case consists of a positive integer target
Constraints

1≤N≤105
1≤nums[i], target≤10^9
1≤T≤10^5


Output Format

For each testcase, print the index if the 
t
a
r
g
e
t
 is found. If not, print the index where it would be if it were inserted in order.
Sample Input 0

4
1 3 5 6
4
5
2
7
0

Sample Output 0

2
1
4
0

Explanation

5
 is present at position 
2
2
 will be inserted at position 
1
7
 will be inserted at position 
4
0
 will be inserted at position 
0
Example
Input
4
1 3 5 6
4
5
2
7
0
Output
2
1
4
0  */

#include <iostream>
using namespace std;

int binarySearch(int low, int high, int key,int* arr){
		while(low<=high){
					int mid=(low+high)/2;
					if(arr[mid]==key) {
							return mid;
					}
				  else if(arr[mid]<key) low=mid+1;
				  else high=mid-1;
			}	
		return low;
}
int main() {
    // your code goes here
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
				cin>>arr[i];
		}
		
		int t;
        cin>>t;
		while(t--){
			int key;
			cin>>key;
			int low=0;
			int high=n-1;
			cout<<binarySearch(low, high, key ,arr)<<endl;
			
		}
		
    return 0;
}