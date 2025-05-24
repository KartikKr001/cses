#define mod %1000000007
#define ll long long
#include<bits/stdc++.h>
using namespace std;

ll powe(ll a,ll b){
    // a^b
    if(b == 0) return 1;
    if(b == 1) return a mod;
    ll temp = powe(a,b/2) mod;
    if(b % 2 == 0) return (temp*temp) mod;
    else return (((temp*temp))*a) mod;
}
int main(){
    int q;
    cin>>q;
    ll sum = 1;
    ll pro = 1;
    ll cnt = 1;
    int a,b;
    // total number of divisors = product of occurence of each prime number
    // sum of prime numbers = 
    while(q--){
        cin>>a>>b;
        cnt = (cnt mod * (b+1) mod) mod;  
        ll temp_sum = (((powe(a,b+1)-1)/(a-1))) mod;
        sum = (sum mod * temp_sum mod) mod;
    }
    cout<<cnt<<" "<<sum;
    
    return 0;
}