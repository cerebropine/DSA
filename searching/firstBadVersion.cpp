// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// dummy method
bool isBadVersion(int s){
    return true;
};
class Solution {
public:
    int firstBadVersion(int n) {
        
        int low=1;
        int high=n;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(!isBadVersion(mid)) low=mid+1;
            else{
                if(mid==1) return mid;
                if(!isBadVersion(mid-1)) return mid;
                else high=mid-1;
            }
        }
        return -1;
        
    }
};