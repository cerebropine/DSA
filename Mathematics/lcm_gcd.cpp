#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> answer;
        long long maxm=max(A,B);
        long long minm=min(A,B);
        long long temp;
        while(maxm%minm!=0){
            temp=minm;
            minm=maxm%minm;
            maxm=temp;
            
        }
        answer.push_back((A*B)/minm);
        answer.push_back(minm);
        
        return answer;
    }
};

int main(){
    vector<long long> answer;
    Solution sol;
    answer=sol.lcmAndGcd(5,10);
    cout<<"LCM : "<<answer.at(0)<<endl;
    cout<<"GCD : "<<answer.at(1)<<endl;
    return 0;
}