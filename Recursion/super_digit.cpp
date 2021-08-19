#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int helper(long long z){
    if(z<=9) return z;
    long long m=0;
    long long sum=0;
    while(z!=0){
        m=z%10;
        sum+=m;
        z=z/10;

    }
    return helper(sum);

}
int superDigit(string n, int k) {
   
    long long sum=0;
    for(int j=0;j<n.length();j++)
        sum+=n[j]-'0';
    return helper(sum*k);
}

int main(){
    int s=superDigit("123",2);
    return 0;
}