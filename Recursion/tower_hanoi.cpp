#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<pair<int,int>> result;
    void tower_hanoi(int n,int from_rod,int to_rod,int aux_rod){
    if(n==1){
        result.push_back(make_pair(from_rod,to_rod));
        return;
    }
    tower_hanoi(n-1,from_rod,aux_rod,to_rod);
    result.push_back(make_pair(from_rod,to_rod));
    tower_hanoi(n-1,aux_rod,to_rod,from_rod);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        tower_hanoi(N,1,3,2);
        vector<int> res;
        res.push_back(result.at(n-1).first);
        res.push_back(result.at(n-1).second);
        return res;
    }
};




int main(){
    int N,n;
    cin>>N>>n;
    Solution sol;
    vector<int> res=sol.shiftPile(N,n);
    cout<<res.at(0)<<" "<<res.at(1)<<endl;
    return 0;

}