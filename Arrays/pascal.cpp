
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==1){
            result.push_back({1});
            return result;
        }
        else if(numRows==2){
            result.push_back({1});
            result.push_back({1,1});
            return result;
        }
        else{
            result.push_back({1});
            result.push_back({1,1});
            for(int i=3;i<=numRows;i++)
            {
                vector<int> res(i);
                res.at(0)=1;
                int j=i-2;
                while(j){
                    res.at(j)=result.at(i-2).at(j-1)+result.at(i-2).at(j);
                    j--;
                }
                res.at(i-1)=1;
                result.push_back(res);
            }
        }
        return result;
    }
};

int main(){
int numRows;
cin>>numRows;
//[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Solution sol;
vector<vector<int>> result=sol.generate(numRows);
for(int i=0;i<numRows;i++){
    for(int j=0;j<result.at(i).size();j++) cout<<result.at(i).at(j)<<" ";
    cout<<endl;
}
return 0;
}