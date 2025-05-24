#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<ll>pref(n);
    pref[0] = v[0];
    for(int i=1;i<n;i++) pref[i] = pref[i-1]+v[i];

    int i=0,j=0;
    int ans = 0;
    while(j<n){
        ll sum = pref[j]-pref[i]+v[i];
        if(sum < x){
            j++;
        }
        else if(sum > x){
            i++;
        }
        else{
            ans++;
            i++;
            j++;
        }
    }
    cout<<ans;
    return 0;
}