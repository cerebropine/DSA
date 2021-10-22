
/*
Given a sorted array consisting of 
0
′
s
 and 
1
′
s
. The task is to print the index of first 
1
 in the given array. You must write an algorithm with 
O
(
l
o
g
(
n
)
)
 runtime complexity.

Input Format

The first line of input contains 
N
, size of the array
The second line of input contains 
N
 space-separated array elements
Constraints

1
 
≤
 
N
 
≤
 
10
5
0
 
≤
 
n
u
m
s
[
i
]
 
≤
 
1
Output Format

Print index of the first 
1
 or print 
−
1
.
Sample Input 0

5
0 0 0 1 1

Sample Output 0

4

Sample Input 1

3
0 0 0

Sample Output 1

-1

Explanation

Suppose indexing from 
1
 to 
N
, 
1
 exists in the array at position 
4
1
 is not present in the array
Example
Input
5 
0 0 0 1 1
Output
4

*/





#include <iostream>
using namespace std;

int binarySearch(int* arr,int n){
		int low=0;
		int high=n-1;
		int mid;
		while(low<=high){
				mid=(low+high)/2;
				if(arr[mid]==0) low=mid+1;
				else{
						if(mid==0) return mid+1;
						else if(arr[mid-1]==0) return mid+1;
						else high=mid-1;
				}
		}
		return -1;
}
int helper(int* arr, int n){
		int res=binarySearch(arr, n);
		if(res==-1) return -1;
		else return res;
}
int main() {
    // your code goes here
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
				cin>>arr[i];
		}
		
		cout<<helper(arr, n)<<endl;
		//cout<<res<<endl;
    return 0;
}