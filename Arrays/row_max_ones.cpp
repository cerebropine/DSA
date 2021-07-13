#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
		int i,j;int ans;
		i=0;j=m-1;ans=-1;
		while(i<=n-1 && j>0){
			if(arr[i][j]==0){
				i=i+1;	
			}
			else{
				if(arr[i][j]==arr[i][j-1]) {
					j=j-1;
					ans=i;
				}
				else{
					i=i+1;
					
				}				
			}
		}

		if(j==m-1){
			for(int k=0;k<n;k++){
				if(arr[k][j]==1) return k;
			}
		}
	 	return ans;
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