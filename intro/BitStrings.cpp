#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod %1000000007

int main(){
    ll n;
    cin>>n;
    ll ans = 1;
    while(n--){
        ans = (ans mod + ans mod)mod;
    }
    cout<<ans<<endl;

    return 0;
}