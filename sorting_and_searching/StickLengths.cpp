#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;

    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    ll med = v[n/2];
    
    ll ans = 0;

    for(int i=0;i<n;i++){
        ans += abs(med-v[i]);
    }
    cout<<ans<<endl;
    return 0;
}
