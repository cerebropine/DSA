#include<bits/stdc++.h>
using namespace std;

class Solution{

public:
    int getCountOfWaste(vector<pair<int ,int>>waste,int a,int b,int m){
        int count=0;
        for(int i=0;i<waste.size();i++){
            if(waste.at(i).first<a && waste.at(i).second<=m){
                count++;
            }
            else if(waste.at(i).first==a && waste.at(i).second<b){
                count++;
            }
            else if(waste.at(i).first==a && waste.at(i).second==b) return -1;
        
        }
        return count;
    }
    void printFields(){
        int n,m,k,t;
        cin>>n>>m>>k>>t;
        vector<pair<int,int>> waste;
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            waste.push_back(make_pair(a,b));
        }
        for(int i=0;i<t;i++){
            int a,b;
            cin>>a>>b;
            int kCount=getCountOfWaste(waste,a,b,m);
            if(kCount==-1) cout<<"Waste"<<endl;
            else{
                int position=((a-1)*m+(b-1)-(kCount))%3;
                if(position==0) cout<<"Carrots"<<endl;
                else if(position==1) cout<<"Kiwis"<<endl;
                else cout<<"Grapes"<<endl;
                }
        }
    }
};

int main(){
  
  Solution sol;
  sol.printFields();
  return 0;

}