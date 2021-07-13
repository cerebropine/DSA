#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        vector<int> rearrangeArray(vector<int>& arr){
            int n=arr.size();
            for(int i=0;i<n;i++){
                int value=i;
                int con=arr[value];
                int current=arr[value];
                int next=arr[current];
                while(con!=next){
                    arr[current]=value;
                    value=current;
                    current=next;
                    next=arr[current];
                }
                arr[current]=value;
                i=next+1;

            }
            return arr;
        }

};

int main(){
    vector<vector<int>> arr={{1, 3, 0, 2},{2, 0, 1, 4, 5, 3},
                            {0, 1, 2, 3},  {3, 2, 1, 0}};
    Solution sol;
    for(int i=0;i<arr.size();i++){
        vector<int> out=sol.rearrangeArray(arr.at(i));
        for(int j=0;j<out.size();j++) cout<<out.at(j)<<" ";
        cout<<endl;
    }
    
    return 0;
}
