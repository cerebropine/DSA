#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> subsetSums(vector<int> arr, int N)
    {  
       vector<int>temp;
       subsetUtil(arr,N,0,temp);
       vector<int> res;
       for(int i=0;i<result.size();i++){
           res.push_back(accumulate(result.at(i).begin(),result.at(i).end(),0));
       }
       return res;
    }

    void subsetUtil(vector<int>& arr, int N,int i,vector<int>& temp)
    {
      if(i==N){
          result.push_back(temp);
          return;
      }
          subsetUtil(arr,N,i+1,temp);
          temp.push_back(arr.at(i));
          subsetUtil(arr,N,i+1,temp);
          temp.pop_back();
    }
};

int main(){
    Solution sol;
    vector<int> arr={2,3};
    int N=2;
    sol.subsetSums(arr,N);
    return 0;

}