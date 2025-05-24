#define ll long long
#include<bits/stdc++.h>
using namespace std;

// Binary Indexed Tree always has 1 based indexing

ll n;
vector<ll> bit;
void update(ll idx,ll val){
    // idx is 1 based
    while(idx <= n){
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

ll query(ll idx){
    // idx is 1 based
    ll ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int main(){
    ll q; //number of queries
    cin>>n>>q;
    bit = vector<ll>(n+1,0);
    vector<ll>a(n+1);

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }

    while(q--){
        ll queryType;
        cin>>queryType;
        if(queryType == 2){
            // sum in range [l,r] -> 1 based;
            ll l,r;
            cin>>l>>r;
            ll ans = query(r) - query(l-1);
            cout<<ans<<endl;
        }
        else{
            // modify a value in gveb array
            ll idx,val;
            // idx is based
            cin>>idx>>val;
            update(idx,-a[idx]); //make it to zero
            a[idx] = val;
            update(idx,a[idx]);
        }

    }

    return 0;
}