#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
   bool flag =false;
   vector<long long> sequence;
   void transform(long long x,long long target){
       if(flag) return;
       if(x>target) return;
       else if(x==target) {
           flag=true;
           sequence.push_back(x);
           return;
           }
       else{
           sequence.push_back(x);
           transform(2*x,target);
           transform(10*x+1,target);
           if(!flag)
            sequence.pop_back();
       }

   }
   bool transformed(long long x,long long target){
       transform(x,target);
       if(flag==true) {
           cout<<"YES"<<endl;
           cout<<sequence.size()<<endl;
           for(int i=0;i<sequence.size();i++){
               cout<<sequence.at(i)<<" ";
           }
        
        }
        else{
            cout<<"NO"<<endl;
        }
   }

};

int main(){
    long long  num,target;
    cin>>num>>target;
    Solution sol;
    sol.transformed(num,target);
    return 0;
}