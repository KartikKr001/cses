#define pp pair<ll,ll>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<vector<pp>> graph;
vector<ll> mp;
void djkstras(ll src,ll n){
    priority_queue<pp,vector<pp>,greater<pp>> pq; //wt-dest
    unordered_set<ll>vis;
    mp.assign(n+1,LLONG_MAX);
    for(ll i=1;i<=n;i++) mp[i] = LLONG_MAX;
    pq.push({0,src});
    mp[src] = 0;

    while(pq.size() > 0){
        auto curr = pq.top();
        pq.pop();
        ll wt = curr.first;
        ll node = curr.second;
        vis.insert(node);

        // If we already have a shorter distance, skip this
        if (wt > mp[node]) continue;
        
        for(auto x:graph[node]){
            if(vis.count(x.first)) continue;
            if(mp[x.first] > mp[node]+x.second){
                mp[x.first] = mp[node]+x.second;
                pq.push({mp[node]+x.second,x.first});
            }
        }


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
    for(int i=1;i<=v;i++){
        cout<<mp[i]<<" ";
    }

    return 0;
}
