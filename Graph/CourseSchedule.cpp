#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>indeg(n+1);
    vector<list<ll>>graph;
    graph.assign(n+1,list<ll>());
    ll a,b;
    while(m--){
        cin>>a>>b;
        indeg[b]++;
        graph[a].push_back(b);
    }
    vector<ll> ans;
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(q.size() > 0){
        ll curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto x:graph[curr]){
            if(indeg[x] > 0){
                indeg[x]--;
                if(indeg[x] == 0) q.push(x);
            }
        }
    }
    if(ans.size() < n) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }


}