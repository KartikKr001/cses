#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    // generate all subseq using bitmasking
    // number of subseq -> 1<<n
    ll total_sub = 1<<n;
    ll ans = INT_MAX;
    for(ll i=0;i<total_sub;i++){
        ll temp = 0;
        for(ll j=0;j<n;j++){
            if((1<<j) & i){
                temp += v[n-1-j];
            }
        }
        ans = min(ans,abs(max(temp,sum-temp)-min(temp,sum-temp)));
    }

    cout<<ans<<endl;

    return 0;
}