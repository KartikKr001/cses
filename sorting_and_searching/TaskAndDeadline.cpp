#define ll long long
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<ll>v(n);
    int ele;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        cin>>ele;
        sum += ele;
    }
    sort(v.begin(),v.end());
    ll diff = 0;
    for(int i=0;i<n;i++){
        diff += v[i]*(n-i);
    }
    cout<<(sum - diff);


    return 0;
}