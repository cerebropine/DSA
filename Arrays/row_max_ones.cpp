#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
		int i,j;int ans=0,ans_row;
		i=0;j=m-1;ans_row=-1;
		while(i<=n-1 && j>=0){
			if(arr[i][j]==0) i++;
			else j--;
			
			int count_of_ones=m-1-j;
			if(count_of_ones>ans){
				ans=count_of_ones;
				ans_row=i;
			}
		}
	 	return ans_row;
	}

};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> arr(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		Solution sol;
		cout<<sol.rowWithMax1s(arr,n,m)<<endl;
	}
	return 0;
}