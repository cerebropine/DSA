/*
You are given an 
N
∗
M
 binary matrix of 
1
s
 (representing soldiers) and 
0
s
 (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 
1
s
 will appear to the left of all the 
0
s
 in each row. A row 
i
 is weaker than a row 
j
 if one of the following is true:

The number of soldiers in row 
i
 is less than the number of soldiers in row 
j
Both rows have the same number of soldiers and 
i
<
j
Print the indices of all the weakest rows in the matrix ordered from weakest to strongest.

Input Format

The first line of input contains 
N
 and 
M
, denoting rows and columns of the matrix
The second line of input contains the binary matrix 
m
a
t
Constraints

1
 
≤
 
N
, 
M
 
≤
 
10
3
0
 
≤
 
m
a
t
[
i
]
 
≤
 
1
Output Format

Print the indices of all the weakest rows in the matrix ordered from weakest to strongest.
Sample Input 0

5 5
1 1 0 0 0
1 1 1 1 0
1 0 0 0 0
1 1 0 0 0
1 1 1 1 1

Sample Output 0

2 0 3 1 4

Explanation

The number of soldiers in each row is:

Row 0: 2
Row 1: 4
Row 2: 1
Row 3: 2
Row 4: 5
The rows ordered from weakest to strongest are [2,0,3,1,4].

Example
Input
5 5  
1 1 0 0 0   
1 1 1 1 0   
1 0 0 0 0  
1 1 0 0 0  
1 1 1 1 1
Output
2 0 3 1 4
*/


#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int n){
		int low=0;
		int high=n-1;
		int mid;
		while(low<=high){
				mid=(low+high)/2;
				if(arr[mid]==0) high=mid-1;
				else{
						if(mid==n-1) return mid+1;
						if(arr[mid+1]==0) return mid+1;
						else low=mid+1;
				}
		}
		return -1;
}
bool cmp(pair<int,int> p1, pair<int,int>p2){
		if(p1.first!=p2.first) return p1.first<p2.first;
		return p1.second<p2.second;
}
int main() {
    // your code goes here
		int n, m;
		cin>>n>>m;
		vector<vector<int>> grid(n, vector<int>(m,0));
		for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
						cin>>grid.at(i).at(j);
				}
		}
		vector<pair<int, int>> res;
		for(int k=0;k<n;k++){
				res.push_back({binarySearch(grid.at(k),m),k});
		}
		
		sort(res.begin(), res.end(),cmp);
		for(int p=0;p<n;p++) cout<<res.at(p).second<<" ";

    return 0;
}