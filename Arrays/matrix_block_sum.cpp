#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
                mat[i][j]=sum;
            }
        }

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=mat[j][i];
                mat[j][i]=sum;
            }
        }
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                vector<int> region=getRegion(i,j,m,n,k);
                int r1=region[0];
                int c1=region[1];
                int r2=region[2];
                int c2=region[3];
                if(r1-1 <0 && c1-1<0){
                    result[i][j]=mat[r2][c2];
                }
                else if(r1-1<0){
                    result[i][j]=mat[r2][c2]-mat[r2][c1-1];
                }
                else if(c1-1<0){
                    result[i][j]=mat[r2][c2]-mat[r1-1][c2];
                }
                else{
                result[i][j]=mat[r2][c2]-mat[r2][c1-1]-mat[r1-1][c2]+mat[r1-1][c1-1];
                }
            }
        }
        return result;
    }

    vector<int> getRegion(int i,int j, int m,int n,int k){
        vector<int> region(4);
        int r1,c1,r2,c2=0;
        if(i+k>m-1) r2=m-1;
        else r2=i+k;
        if(j+k>n-1) c2=n-1;
        else c2=j+k;

        if(i-k<0) r1=0;
        else r1=i-k;
        if(j-k<0) c1=0;
        else c1=j-k;
        
        region.at(0)=r1;
        region.at(1)=c1;
        region.at(2)=r2;
        region.at(3)=c2;
        return region;
    }
};


int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    sol.matrixBlockSum(mat,1);
    return 0;
}