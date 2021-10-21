/*
Given a 1-indexed array of integers nums
 that is already sorted in non-decreasing order, 
 find two numbers such that they add up to a specific target
 number. Let these two numbers be

nums[index1] , nums[index2] where 1<=first<=second<=nums.length.

Print the indices of the two numbers index1 and index2.

The tests are generated such that there is exactly one solution. 
You may not use the same element twice.

You must write an algorithm with 
O(nlogn) runtime complexity.
 
Input Format

The first line of input contains 
N, size of the array

The second line of input contains 
N space-separated array

The second line of input contains N space-separated array elements 

The third line of the input contains a single integer 
target.

Output Format

Print the indices of the two numbers, 
i
n
d
e
x
1
 and 
i
n
d
e
x
2
 whose sum is 
t
a
r
g
e
t
Sample Input 0

4
2 7 11 15
9

Sample Output 0

1 2

Sample Input 1

3
2 3 4
6

Sample Output 1

1 3

Sample Input 2

2
-1 0
-1

Sample Output 2

1 2

Explanation

The sum of 
2
 and 
7
 is 
9
. Therefore index1 = 
1
, index2 = 
2
.
The sum of 
2
 and 
4
 is 
6
. Therefore index1 = 
1
, index2 = 
3
.
The sum of 
1
 and 
0
 is 
−
1
. Therefore index1 = 
1
, index2 = 
2
.

*/









#include <iostream>
using namespace std;
int binarySearch(int* arr, int target, int n , int i){
		int low=i;
		int high=n-1;
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
		for(int i=0;i<n;i++){
				cin>>arr[i];
		}
		int target;
		cin>>target;
		for(int i=0;i<n;i++){
				int res=binarySearch(arr, target-arr[i],n, i+1);
				if(res!=-1){
						cout<<i+1<<" "<<res+1<<endl;
						break;
				}
		}
    return 0;
}