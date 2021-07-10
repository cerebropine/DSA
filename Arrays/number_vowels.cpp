#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const char vowels[5]={'a','e','i','o','u'};
    int maxVowels(string s, int k) {
        int ans=0;
        int n=s.length();
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i])) count++;
        }
        ans=max(count,ans);
        for(int j=k;j<n;j++){
            if(isVowel(s[j])) count++;
            if(isVowel(s[j-k])) count--;
            ans=max(ans,count);
        }
        return ans;
    }

    bool isVowel(char ch)
    {
        for(int i=0;i<5;i++){
            if(ch==vowels[i]) return true;
        }
        return false;
    }
};

int main(){
    string s="abciiidef";
    int k=3;
    Solution sol;
    cout<<sol.maxVowels(s,k)<<endl;
    return 0;
}