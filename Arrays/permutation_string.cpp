#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.length();
        int sn=s1.length();
        if(sn>n) return false;
        int freq_s1[26]={0};
        int freq_s2[26]={0};
        for(int i=0;i<sn;i++){
            freq_s1[s1[i]-'a']++;
            freq_s2[s2[i]-'a']++;
        }
        if(checkAnagram(freq_s1,freq_s2)) return true;
        for(int j=sn;j<n;j++){
            freq_s2[s2[j-sn]-'a']--;
            freq_s2[s2[j]-'a']++;
            if(checkAnagram(freq_s1,freq_s2)) return true;
        }
        return false;
        
    }
    bool checkAnagram(int *freq_s1,int *freq_s2){
        for(int i=0;i<26;i++){
            if(freq_s1[i]!=freq_s2[i]) return false;
        }
        return true;
    }

};


int main(){
    string s1="ab";
    string s2 = "eidbaooo";
    Solution sol;
    cout<<sol.checkInclusion(s1,s2)<<endl;
}