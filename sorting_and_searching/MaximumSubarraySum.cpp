#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
int main(){
    int n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<ll>pre = v;
    for(int i=1;i<n;i++) pre[i] = pre[i-1]+v[i];
    
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll ans = pre[0];
    // JUST TO INITALIZE PRIORITY_QUEUE
    pq.push(pre[0]);
    for(int i=0;i<n;i++){
        ans = max({ans,pre[i]-pq.top(),pre[i]});
        pq.push(pre[i]);
    }
    cout<<ans<<endl;
    return 0;
}
*/

/*
    dp approach

*/
vector<int> v;
int f(int i,int par){
    if(i>=v.size()) return 0;
    return max(f(i+1,0),v[i]+f(i+1,1));
}
int main(){
    int n;
    cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<f(0);
    return 0;
}