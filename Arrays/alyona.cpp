#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
   int m,n;
   cin>>m>>n; 
   vector<int> arr(m+1);
   for(int i=1;i<m+1;i++){
       int temp;
       cin>>temp;
       arr.at(i)=temp;
   }
   vector<int> prefixsum(m+1);
   prefixsum.at(0)=0;
   prefixsum.at(1)=arr.at(1);
   for(int i=2;i<m+1;i++){
       prefixsum.at(i)=prefixsum.at(i-1)+arr.at(i);
   }
   int ans=0;
   for(int i=0;i<n;i++){
       int n1,n2;
       cin>>n1>>n2;
       if(prefixsum.at(n2)-prefixsum.at(n1-1)>0){
           ans+=prefixsum.at(n2)-prefixsum.at(n1-1);
       }
    
   }
   cout<<ans<<endl;
   return 0;
 
}