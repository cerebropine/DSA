#include<bits/stdc++.h>
using namespace std;

/*One way to think could simply be : func(i, j) can call func(i+1,j) and func(i+1,j+1)
 where cell (i,j) denotes your current glass. Also pass another variable qty: quantity of liquid. 
I think you can figure out how much of qty should be poured over left and right glasses.*/
int n;
void fillglasses(vector<vector<double>>& glasses,int i,int j,double qty){
    if(i>n) return;
    glasses[i][j]+=qty;
    if(glasses[i][j]>1){
        fillglasses(glasses,i+1,j,(glasses[i][j]-1)/2.0);
        fillglasses(glasses,i+1,j+1,(glasses[i][j]-1)/2.0);
        glasses[i][j] = 1;
    }
}



int main(){
    double t;
    cin>>n>>t;
    vector<vector<double>> glasses(n+1,vector<double>(n+1,0));
    fillglasses(glasses,1,1,t);
    int cnt=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
             if(glasses[i][j] == 1) cnt++;
        }
    }
    cout<<cnt<<endl;
}