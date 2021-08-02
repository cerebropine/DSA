#include <bits/stdc++.h>
using namespace std;
// sieve code starts.
const int n=1e5;
pair<int,vector<int>> sieve[n+1];
 
int CountSieve(){
   for(int m=0;m<=n;m++){
    sieve[m].first=1;
}
sieve[0].first=sieve[1].first=0;
for(int i=2;i<=n/2;i++)
{
    if(sieve[i].first==1)
    {
    sieve[i].second.push_back(i);
    for(int j=2;i*j<=n;j++)
    {
            sieve[i*j].first=0;
            sieve[i*j].second.push_back(i);
    }
}
}
}
 
void printVector(std::vector <int> const &a) {
   std::cout << "The vector elements are : ";
 
   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
   cout<<endl;
}
 
int main()
{
   CountSieve();
   int n,m;
   scanf("%d %d",&n,&m);
   int current[n+1]={0};
   for(int l=0;l<m;l++){
       char c;
       int d;
       scanf(" %c %d",&c,&d);
       if(c=='+')
       {
           if(current[d]==0 || current[d]!=d){
			   bool flag=true;
               for(auto z : sieve[d].second)
               {
                   if(current[z]!=0){
                       cout<<"Conflict with "<<current[z]<<endl;
					   flag=false;
                       break;
                   }
               }
			   if(flag){
				   for(auto z:sieve[d].second){
					   current[z]=d;
				   }
				 current[d]=d;
                 cout<<"Success"<<endl;
			   }              
           }
           else
               {
                   cout<<"Already on"<<endl;
               }
       }
	   else{
		   if(current[d]==0 || current[d]!=d)
			   cout<<"Already off"<<endl;
			else{
				for(auto z : sieve[d].second){
				    current[z]=0;
				}
				current[d]=0;
			
				cout<<"Success"<<endl;
			}				
		   
		   }
   
   }
 
   return 0;
}