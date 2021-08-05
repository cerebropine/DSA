#include<bits/stdc++.h>
using namespace std;

int a[2000];
int b[2000];
int main()
{
    int sum=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        sum+=a[x+y]++;
        sum+=b[1000+x-y]++;
    }
    cout<<sum<<endl;
    return 0;
}