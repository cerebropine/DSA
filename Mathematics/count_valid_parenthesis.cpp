#include<bits/stdc++.h>
using namespace std;

/*Using the concept of catalan numbers*/

int main(){

    int n;
    cin>>n;
    int catalan[n+1];
    catalan[0]=1;
    catalan[1]=1;
    for(int i=2;i<=n;i++){
        catalan[i]=0;
        for(int j=0;j<i;j++){
            catalan[i]+=catalan[j]*catalan[i-j-1];
        }
    }
    cout<<catalan[n]<<endl;


}