#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    ll low = 1;
    ll high = *max_element(v.begin(),v.end())*t;

    ll mid = 0;
    ll ans = 0;
    while(low<=high){
        mid = low + (high-low)/2;
        ll score  = 0;
        for(int i=0;i<n;i++){
            score += (mid/v[i]);
            if(score >= t) break;
        }

        if(score >= t){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans;

    return 0;
}