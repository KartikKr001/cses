#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; 
    cin >> n;
    vector<bitset<3000>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i+1; j < n; j++) {
            ll cnt = (v[i]&v[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    }
    cout<<ans<<endl;
}