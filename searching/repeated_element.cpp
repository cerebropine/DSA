/*
Only Repeating Element(Try on Local IDE)
Medium
Given a sorted array of n elements containing elements in range from 
1
 to 
n
−
1
 i.e. one element occurs twice, the task is to find the repeating element in an array.

Follow up: Your solution should run in 
O
(
l
o
g
n
)
 time

Input Format

The first line of input contains 
N
, number of elements in array
The second line of input contains 
N
 space-separated integers, 
n
u
m
s
[
1
]
, 
n
u
m
s
[
2
]
, ......... 
n
u
m
s
[
N
]
Constraints

2
 
≤
 
N
 
≤
 
10
5
1
 
≤
 
n
u
m
s
[
i
]
 
≤
 
N
−
1
Output Format

Print the repeating element
Sample Input 0

7
1 2 3 4 4 5 6

Sample Output 0

4

Example
Input
7
1 2 3 4 4 5 6
Output
4


*/


#include <iostream>
using namespace std;

int binarySearch(int* arr, int n){
		int low=0;
		int high=n-1;
		int mid;
		while(low<=high){
				mid=(low+high)/2;
				if(arr[mid]==mid) high=mid-1;
				else{
						if(arr[mid]==arr[mid+1]) return mid+1;
						else low=mid+1;
				}
		}
		return -1;
}
int main() {
    // your code goes here
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<binarySearch(arr, n)<<endl;
    return 0;
}