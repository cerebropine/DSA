/* Search a Key

Given an array nums of N integers which is sorted in ascending order, and an integer target,
 write a program to search target in nums
If target exists, then print its index. Otherwise, print −1
. You must write an algorithm with O(log(n))
 runtime complexity.

Input Format

The first line of input contains N
, number of elements in the array
The second line of input contains 
N space-separated integers nums[0],........nums[N−1]
The third line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
Each test case consists of a positive integer 
target Constraints

1≤N≤10^5

1≤nums[i], target≤10^9
1≤T≤10^5

Output Format

Print index of the 
target or if not found, print −1
.
Sample Input 0

6
0 1 3 5 9 12
2
9
2

Sample Output 0

4
-1

Explanation

9
 is present at index 
4
2
 is not present in the array
Example
Input
6  
0 1 3 5 9 12  
2  
9  
2
Output
4
-1 */ 
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
		return -1;
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