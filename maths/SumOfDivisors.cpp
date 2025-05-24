#include<bits/stdc++.h>
using namespace std;
#define mod %1000000007
#define ll long long
int main(){
    long long n;
    cin>>n;
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans = ((ans mod) + ((n/i)*i) mod) mod;
    }
    
    cout<<ans<<endl;

    return 0;
}