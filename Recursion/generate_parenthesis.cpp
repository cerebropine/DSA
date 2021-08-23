#include<bits/stdc++.h>
using namespace std;
int n;
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {  
        vector<char> s(2*n);
        pp(s,n,0,0,0);
        return res;
    }

    void pp(vector<char>&s,int n,int l, int r, int i){
        if(i==(2*n)) {
            string p(s.begin(), s.end());
            res.push_back(p);
            return;
            }
        if(l==r){
            s[i]='(';
            pp(s,n,l+1,r,i+1); 
        }
        else if(l>r){
            if(l==n) {
                s[i]=')';
                pp(s,n,l,r+1,i+1);
                }

            else {
                s[i]='(';
                pp(s,n,l+1,r,i+1);
                s[i]=')';
                pp(s,n,l,r+1,i+1); 
            }
        }
    }
};

int main(){
    cin>>n;
    Solution sol;
    sol.generateParenthesis(n);
    return 0;
}