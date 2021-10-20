/* 
Given an array of integers, 
nums sorted in ascending order, and a target value.
Print the number of occurrences of the target in the given array.
You must write an algorithm with 
O(log(n)) runtime complexity.
If 
target is not found in the array, return −1.

You must write an algorithm with O(log(n)) runtime complexity.

Input Format

The first line contains an integer 
N
, number of elements in the array nums

The second line contains 
N
 space-separated integers 
nums[0],......, nums[N]

The third line of the input contains a single integer 
T denoting
the number of test cases. The description of 
T test cases follows.

Each test case consists of a positive integer 
target

Constraints

1≤N≤10^5
1≤nums[i]≤10^9
1≤T≤10^5

Output Format

For each test case, print starting and ending index of the target value or 
−1.

Sample Input 0

5
1 2 2 4 5
5
1
2
3
4
5

Sample Output 0

1
2
0
1
1

Explanation

1
 is present one time
2
 is present two times
3
 is not present in the array
4
 is present one time
5
 is present one time
*/


#include <iostream>
using namespace std;

int lowSearch(int low, int high, int key,int* arr){
		while(low<=high){
					int mid=(low+high)/2;
					if(arr[mid]==key) {
                        if(arr[mid-1]!=key){
                            return mid+1;
                        }
                        else{
                            high=mid-1;
                        }
							
					}
				  else if(arr[mid]<key) low=mid+1;
				  else high=mid-1;
			}	
		return -1;
}

int highSearch(int low, int high, int key,int* arr){
		while(low<=high){
					int mid=(low+high)/2;
					if(arr[mid]==key) {
                        if(arr[mid+1]!=key){
                            return mid+1;
                        }
                        else{
                            low=mid+1;
                        }
							
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
			int lowest=lowSearch(low, high, key ,arr);
      int highest = highSearch(low, high, key ,arr);
			if(lowest==-1)
					cout<<0<<endl;
			else{
					cout<<highest-lowest+1<<endl;
			}
			
		}
		
    return 0;
}