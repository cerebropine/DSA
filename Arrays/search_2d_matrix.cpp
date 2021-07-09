#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},
                        {10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    Solution sol;
    cout<<sol.searchMatrix(matrix,target)<<endl;
    return 0;
}