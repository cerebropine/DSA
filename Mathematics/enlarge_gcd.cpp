    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll max_elemen;
    void compute_spf(vector<ll> &spf){
        
        for(ll i=2;i<=max_elemen;i++){
            if(!spf[i]) 
            {
                spf[i]=i;
                for(ll j=i;i*j<=max_elemen;j++){
                    if(spf[i*j]==0){
                        spf[i*j]=i;
                    }
                }
            }
        }
       
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin>>n;
        ll nums[n];
        ll gcd=0;

        for(int i=0;i<n;i++){
            cin>>nums[i];  
            gcd=__gcd(gcd,nums[i]);  
        }
        
        for(int i=0;i<n;i++){
            nums[i]=nums[i]/gcd;
            max_elemen=max(nums[i],max_elemen);
        }
        vector<ll> spf(max_elemen+1,0);
        vector<ll> primeCounter(max_elemen+1,0);
        compute_spf(spf);
        for(int i=0;i<n;i++){
            ll num=nums[i];ll prev=0;
            while(num!=1){
                if(spf.at(num)!=prev)
                {
                    primeCounter.at(spf.at(num))++;
                    prev=spf.at(num);
                }
                
                num=num/spf.at(num);
                
            }
        }
        ll cnt=0;
        for(int i=2;i<=max_elemen;i++){
            cnt=max(cnt,primeCounter.at(i));
            
        }
        cnt? cout<<n-cnt<<"\n" : cout<<"-1\n";



    /*
    We would need to look at every prime number and note down how many of the numbers are 
    already divisible by that prime number.
    Let's say total numbers are n, and number divisible by some prime number, 3, is x. 
    Then, you will have to remove (n-x) for changing gcd to 3.

    Similarly try for other primes and see how many numbers would need
    to be removed for making that gcd. Then, you will be able to find the best prime number.

    */

    
    return 0; 
    }