/*
MAKING TEAMS

There are N boys and M girls attending a class.

The teacher needs to choose a group containing exactly X students containing no less than 4
 boys and no less than one girl for an project.

How many ways are there to choose a group?

Input Format
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.

For each test case contains three numbers 
N,M and X.

Output Format
For each test case, print the number of ways to form a group on seperate line.

Constraints
1≤T≤10^5

4≤N≤30

1≤M≤30

5≤X≤N+M

Example
Input
1
5 2 5
Output
10


*/





#include <bits/stdc++.h>
using namespace std;
#define N 61



int main() {
    // your code goes here
    vector<vector<int>> pascal(N,vector<int>(N,0));
    pascal.at(0).at(0)=1;
    for(int i=1;i<N;i++){
        pascal.at(i).at(0)=1;
        for(int j=1;j<i;j++){
            pascal.at(i).at(j)=pascal.at(i-1).at(j-1)+pascal.at(i-1).at(j);

        }
        pascal.at(i).at(i)=1;
    }
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        int n,m,k;
        cin>>n>>m>>k;
        ans+=pascal.at(n+m).at(k);
        if(m>=k-3) ans-=pascal.at(n).at(3)*pascal.at(m).at(k-3);
        if(m>=k-2) ans-=pascal.at(n).at(2)*pascal.at(m).at(k-2);
        if(m>=k-1) ans-=pascal.at(n).at(1)*pascal.at(m).at(k-1);
        if(m>=k) ans-=pascal.at(n).at(0)*pascal.at(m).at(k);
        if(n>=k) ans-=pascal.at(n).at(k)*pascal.at(m).at(0);
        cout<<ans<<endl;
    }
    return 0;
}