#include<bits/stdc++.h>
using namespace std;
char ch[3];

class Solution{
    public:
       long long ans=10000000000000;
        void bt(int hei,long long b[5]){
            if(hei==3) {
                ans=min(ans,b[0]);
                return;
            }
            for(int i=0;i<4-hei;i++){
                for(int k=i+1;k<4-hei;k++){
                    long long c[5];
                    for(int j=0;j<5;j++){
                        c[j]=b[j];
                    }
                    if(ch[hei]=='*'){
                        c[i]=c[i]*c[k];
                    }
                    else{
                        c[i]=c[i]+c[k];
                    }
                    for(int m=k;m<4;m++){
                        c[m]=b[m+1];
                    }
                    bt(hei+1,c);
                }
            }
        }
};

int main(){
   Solution sol;
   long long b[5];
   for(int i=0;i<4;i++){
       cin>>b[i];
   }
   b[4]=0;
   for(int i=0;i<3;i++){
       cin>>ch[i];
   }
   sol.bt(0,b);
   cout<<sol.ans<<endl;
}