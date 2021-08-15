#include<bits/stdc++.h>
using namespace std;
const long long M=1e9+7;

int main(){
    /*
    4 5
    ABABA
    BCGDG
    AAAAA
    YABSA
    */
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char element;
            cin>>element;
            arr[i][j]=element-'A';
        }

    }
    int ans=1;
    for(int j=0;j<m;j++){
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
           map[arr[i][j]]=0;
        }
        ans=((ans%M)*(map.size()%M))%M;
    }
    cout<<ans%M<<endl;
}