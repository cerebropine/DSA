#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int size=arr.size();
        if(size==1) return 1;
        int prefixmax=INT_MIN;
        for(int i=0;i<arr.size();i++){
            prefixmax=max(prefixmax,arr.at(i));
            if(prefixmax==i){
                ans++;
            }
        }
        return ans;
    }
    
};
int main(){
    Solution sol;
    vector<int> arr={1,0,2,3,4};
    cout<<sol.maxChunksToSorted(arr)<<endl;
    return 0;
}