#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    map<ll,int> mp;
    mp[0]++;  // correctly handles subarrays starting from 0th index itself
    ll ans = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(sum < 0){
            ans += mp[(sum%n + n)%n]; //to make positive
        }
        else ans += mp[sum%n]; // here sum % n == (sum%n + n)%n;
        mp[(sum%n + n)%n]++; //general case
    }

    cout<<ans;
    return 0;
}