#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<ll>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<ll>pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+v[i];
    }
    ll a=0,b=0;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<endl;
    }
    return 0;
}