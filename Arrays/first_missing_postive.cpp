#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //make all elements which are negative and zeros to a value greater than nums.size()
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)<=0) nums.at(i)=nums.size()+1;
        }
       // mark the presence of each element if it is between 1 to nums.size()
        for(int i=0;i<nums.size();i++){
			//since we are marking presence of an element by making element of its corresponding index as -ve
			// therefore, we need to take +ve value or actual value of that element (as it may have been made -ve during process)
			int element=abs(nums[i]);
			// now, presence of each element is marked at an index less by 1 than that element
			// eg. presence of 1 is marked at index 0
			// i.e. if 1 is present, we will make element at index 0 as -ve
            int index=element-1;;
            if(index<nums.size() && nums[index]>0) nums[index]*=(-1);
        }

        for(int i=0;i<nums.size();i++){
            if(nums.at(i)>0) return i+1;
        }
        return nums.size()+1;
    }

};



int main(){
    vector<int> arr={3,4,-1,1};
    Solution sol;
    cout<<sol.firstMissingPositive(arr)<<endl;
    return 0;
}