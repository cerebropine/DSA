#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count=0;
    int countArrangement(int n) {
        bool visited[n+1];
        for(int i=1;i<=n;i++) visited[i]=false;
        calculate(n,1,visited);
        return count;
    }
    void calculate(int n,int pos,bool* visited){
        if(pos>n) count++;
        for(int i=1;i<=n;i++){
            if(!visited[i] && (pos%i==0 || i%pos==0)){
                visited[i]=true;
                calculate(n,pos+1,visited);
                visited[i]=false;
            }
        }
    }
};

int main(){
    Solution sol;
    int in;
    cin>>in;
    cout<<sol.countArrangement(in)<<endl;
    return 0;
}
