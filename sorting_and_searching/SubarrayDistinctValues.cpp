#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) cin>>v[i];
    
    ll ans = 0;
    int i=0,j=0;
    int maxi = 0;
    while(j<n){
        mp[v[j]]++;
        j++;
        if(mp.size() > k){
// 
// 
            if(mp[v[i]] > 1) mp[v[i]]--;
            else mp.erase(v[i]);
            maxi = j;
            i++;
        }
    }
    cout<<ans;
    return 0;
}