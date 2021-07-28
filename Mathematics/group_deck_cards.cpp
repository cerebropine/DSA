#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int ,int> map; int gcd=0;
        for(int i=0;i<deck.size();i++) map[deck.at(i)]++;
        for (auto x : map) gcd =__gcd(gcd,x.second);
        if(gcd==1) return false;
        if(deck.size()%gcd==0) return true;
        else return false;
    }
   
};

int main(){
    vector<vector<int>> test={{1,2,3,4,4,3,2,1},{1,1,1,2,2,2,3,3},{1},{1,1},{1,1,2,2,2,2}};
    Solution sol;
    for(int i=0;i<test.size();i++)
        cout<<sol.hasGroupsSizeX(test.at(i))<<endl;
    return 0;
}