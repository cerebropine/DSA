#include<bits/stdc++.h>
using namespace std;
#define n 3

int sumMatrices(int arr[][n]){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int top_left=(i+1)*(j+1);
            int bottom_right=(n-i)*(n-j);
            sum+=arr[i][j]*top_left*bottom_right;
        }
    }
    return sum;
}

int main(){
    int arr[][n]={{1,2,3},{4,5,6},{7,8,9}};
    cout<<sumMatrices(arr)<<endl;
    return 0;
}