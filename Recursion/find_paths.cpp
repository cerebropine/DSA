#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        long long count=0;
        void countPaths(int i,int j,int m,int n){
            if(i==m-1 || j==n-1){
                count++;
                return;
            }
            countPaths(i+1,j,m,n);
            countPaths(i,j+1,m,n);
        }
        
};

long long numberOfPaths(int m,int n)
    {
    Solution sol;
    sol.countPaths(0,0,m,n);
    return sol.count;
    }


int main(){
    Solution sol;
    int m,n;
    cin>>m>>n;
    long long npaths=numberOfPaths(m,n);
    cout<<npaths<<endl;
}