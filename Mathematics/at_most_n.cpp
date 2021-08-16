#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& d, int n) {
        string s=to_string(n);
        int l=s.size();
        int ds=d.size();
        int res=0;
        for(int i=1;i<l;i++)
            res+=pow(ds,i);
        int k;
        for(k=0;k<l;k++){
            int count=0;
            for(int j=0;j<ds;j++){
                if(d.at(j)[0]<s[k]) count++;
            }
            res+=count*pow(ds,l-k-1);
            bool flag=false;
            for(int i=0;i<ds;i++){
                if(s[k]==d.at(i)[0]){
                    flag=true;
                }
            }
            if(!flag) break;

        }

        
        if(k==l) res++;
        return res;
    }
    
};

int main(){
    Solution sol;
    vector<string> ss={"1","3","5","7"};
    cout<<sol.atMostNGivenDigitSet(ss,100)<<endl;
    return 0;
}