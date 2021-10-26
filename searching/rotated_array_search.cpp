/*
Rotated Sorted Array
Medium
You have been given an integer array 
n
u
m
s
 sorted in ascending order with distinct values. 
n
u
m
s
 is rotated at an unknown pivot index 
k
 (
0
 
≤
 
k
 
<
 
n
u
m
s
.
l
e
n
g
t
h
) such that the resulting array is 
[
n
u
m
s
[
k
]
,
n
u
m
s
[
k
+
1
]
,
.
.
.
,
n
u
m
s
[
n
−
1
]
,
n
u
m
s
[
0
]
,
n
u
m
s
[
1
]
,
.
.
.
,
n
u
m
s
[
k
−
1
]
]
 (0-indexed).

For example, 
[
0
,
1
,
2
,
4
,
5
,
6
,
7
]
 might be rotated at pivot index 
3
 and become 
[
4
,
5
,
6
,
7
,
0
,
1
,
2
]
.

Given the array 
n
u
m
s
 after the rotation and an integer 
t
a
r
g
e
t
, print the index of 
t
a
r
g
e
t
 if it is in 
n
u
m
s
, or 
−
1
 if it is not in 
n
u
m
s
.

You must write an algorithm with 
O
(
l
o
g
n
)
 runtime complexity.

Input Format

The first line of input contains 
N
, size of the array
The second line of input contains 
N
 space-separated array elements 
n
u
m
s
[
0
]
,
.
.
.
.
.
.
.
.
,
n
u
m
s
[
N
−
1
]
The third line of the input contains a single integer 
T
 denoting the number of test cases. The description of 
T
 test cases follows.
Each test case consists of a positive integer 
t
a
r
g
e
t
Constraints

1
 
≤
 
N
 
≤
 
10
4
−
10
4
 
≤
 
n
u
m
s
[
i
]
, 
t
a
r
g
e
t
 
≤
 
10
4
1
 
≤
 
T
 
≤
 
10
5
Output Format

For each testcase, print the index if the 
t
a
r
g
e
t
 is found. If not, print 
−
1
.
Sample Input 0

7
4 5 6 7 0 1 2
2
0
3

Sample Output 0

4
-1

Explanation

0
 is present at position 
4
3
 is not present in the array
Example
Input
7 
4 5 6 7 0 1 2
2
0
3
Output
4
-1


*/



#include <iostream>
using namespace std;
int findPivot(int* arr, int n){
		int low=0;
		int high=n-1;
		int mid;
		while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]<arr[n-1]) high=mid-1;
            else{
                if(mid<n-1 && arr[mid]>arr[mid+1]) return mid;
                else low=mid+1;
            }
				
		}
        return n-1;
		
}
int binarySearch(int* arr, int n, int target, int l  , int h){
		int low=l;
		int high=h;
		int mid;
		while(low<=high){
				mid=(low+high)/2;
				if(arr[mid]==target) return mid;
				else if(arr[mid]<target) low=mid+1;
                else high=mid-1;
		}
        return -1;
}
int main() {
    // your code goes here
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int t;
        cin>>t;
		while(t--){
				int target;
				cin>>target;
				int pivot=findPivot(arr,n);
				int index=binarySearch(arr, n, target, 0,pivot);
                if(index==-1) index=binarySearch(arr, n, target,pivot+1, n-1);
                cout<<index<<endl;
				//TO DO binary search
		}
        return 0;
}