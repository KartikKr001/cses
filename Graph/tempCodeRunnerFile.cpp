#define pp pair<ll,ll>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<vector<pp>> graph;
map<ll,ll> mp;
void djkstras(ll src,ll n){
    priority_queue<pp,vector<pp>,greater<pp>> pq; //wt-dest
    unordered_set<ll>vis;
    for(ll i=1;i<=n;i++) mp[i] = LLONG_MAX;
    pq.push({0,src});
    mp[src] = 0;

    while(pq.size() > 0){
        auto curr = pq.top();
        pq.pop();
        ll wt = curr.first;
        ll node = curr.second;
        
        for(auto x:graph[node]){
            if(vis.count(x.first)) continue;
            if(mp[x.first] > mp[node]+x.second){
                mp[x.first] = mp[node]+x.second;
                pq.push({mp[node]+x.second,x.first});
            }
        }

        // vis.insert(node);

    }
    return;
}


int main() {
    ll v, e;
    cin>>v>>e;
    graph.assign(v + 1, vector<pp>());
    
    ll s,d,w;
    while (e--) {
        cin>>s>>d>>w;
        graph[s].push_back({d,w});
    }

    djkstras(1,v);
    for(auto x:mp){
        cout<<x.second<<" ";
    }

    return 0;
}
