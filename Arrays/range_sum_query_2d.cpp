#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
       
       int m=matrix.size();
       int n=matrix[0].size();
       for(int i=0;i<m;i++){
           int sum=0;
           for(int j=0;j<n;j++)
           {
               sum+=matrix[i][j];
               matrix[i][j]=sum;
           }
       }

       for(int i=0;i<n;i++){
           int sum=0;
           for(int j=0;j<m;j++)
           {
               sum+=matrix[j][i];
               matrix[j][i]=sum;
           }
       }

       this->matrix=matrix;

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      if(row1-1>=0 && col1-1>=0){
      return matrix[row2][col2]-matrix[row1-1][col2]-matrix[row2][col1-1]+matrix[row1-1][col1-1];  
      }
      else if(row1-1>=0){

          return matrix[row2][col2]-matrix[row1-1][col2];
      }
      else if(col1-1>=0){
          return matrix[row2][col2]-matrix[row2][col1-1];
      }
      else{
          return matrix[row2][col2];
      }
    }
};

int main(){
    vector<vector<int>> matrixs={{3, 0, 1, 4, 2},{5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrixs);
    cout<<obj->sumRegion(2, 1, 4, 3)<<endl;
    return 0;
}
