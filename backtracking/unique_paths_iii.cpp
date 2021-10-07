#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum=0;
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfsutil(vector<vector<int>>& grid, vector<vector<int>>& visited, int count, int& totalCount, int i , int j,int n, int m){
        if(i>=n || j>=m || i<0 || j<0 || grid.at(i).at(j)==-1 || visited.at(i).at(j)==1) return ;
        if(grid.at(i).at(j)==2){
            if(count==totalCount) sum++;
            return;
        }
        visited.at(i).at(j)=1;
        if(grid[i][j]==0) count++;
        for(auto p:dir) dfsutil(grid, visited,count,totalCount,i+p.first,j+p.second,n,m);
        visited.at(i).at(j)=0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         int count=0;
         int n=grid.size();
         int m=grid.at(0).size();
         pair<int,int> start;
         vector<vector<int>> visited(n, vector<int>(m,0));
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid.at(i).at(j)==0) count++;
                 if(grid.at(i).at(j)==1) start={i,j};
             }
         }
         dfsutil(grid, visited,0,count,start.first,start.second,n,m);
         return sum;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    sol.uniquePathsIII(grid);
    return 0;
}