#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int sum=0;
        vector<string> resultpaths;
        vector<pair<pair<int,int>,string>> dir={{{0,1},"R"},{{1,0},"D"},{{-1,0},"U"},{{0,-1},"L"}};
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i, int j, int n, int m,string path){
        
        if(i>=n || j>=m || i<0 || j<0 || visited.at(i).at(j)==1 || grid.at(i).at(j)==0) return;
        
        if(i==n-1 && j==m-1) {
            sum++;
            resultpaths.push_back(path);
            path="";
            return; 
        }
        visited.at(i).at(j)=1;
        for(auto p: dir) {
            dfs(grid,visited,i+p.first.first,j+p.first.second,n,m,path+p.second);
            }
        visited.at(i).at(j)=0;
        return;
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution sol;
        vector<vector<int>> grid;
        for(int i=0;i<n;i++){
            vector<int> elem;
            for(int j=0;j<n;j++){
                int temp;
                cin>>temp;
                elem.push_back(temp);
            }
            grid.push_back(elem);
        }
        vector<vector<int>> visited(n, vector<int>(n,0));
        string path="";
        sol.dfs(grid,visited, 0,0,n,n,path);
        sort(sol.resultpaths.begin(), sol.resultpaths.end());
        for(auto p: sol.resultpaths) cout<<p<<endl;
    }
    return 0;
}