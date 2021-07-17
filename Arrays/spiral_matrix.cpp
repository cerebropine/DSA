#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m=matrix.size();
        int n=matrix.at(0).size();
        int i=0,j=n-1,k=m-1,l=0;
        while(i<=k && j>=l){
        for(int h=l;h<=j;h++) result.push_back(matrix.at(i).at(h));
        i++;
        if(m*n==result.size()) break;
        for(int h=i;h<=k;h++) result.push_back(matrix.at(h).at(j));
        j--;
        if(m*n==result.size()) break;
        for(int h=j;h>=l;h--) result.push_back(matrix.at(k).at(h));
        k--;
        if(m*n==result.size()) break;
        for(int h=k;h>=i;h--) result.push_back(matrix.at(h).at(l));
        l++;
        if(m*n==result.size()) break;
        }

        return result;
    }
};

int main(){
    vector<vector<int>> mat={{1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12}};
    Solution sol;
    vector<int> res=sol.spiralOrder(mat);
    return 0;
}