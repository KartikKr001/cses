#define pp pair<ll,ll>
#define ll long long
#include<bits/stdc++.h>
using namespace std;
int k;
vector<list<pp>> graph;
vector<priority_queue<ll>>dist;
void djkstras(ll src,ll dest){
    priority_queue<pp, vector<pp>, greater<pp>> pq; // Min-heap priority queue
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        ll s = curr.second;
        ll w = curr.first;

        if (dist[s].size() >= k && dist[s].top() <= w) continue;

        dist[s].push(w);

        for (auto x : graph[s]) {
            pq.push({w + x.second, x.first});
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m>>k;
    graph.clear();
    graph.resize(n+1,list<pair<ll,ll>>());
    dist.assign(n+1,priority_queue<ll>());
    ll s,d,wt;
    while(m--){
        cin>>s>>d>>wt;
        graph[s].push_back({d,wt});
    }
    djkstras(1,n);
    vector<ll> ans;
    while(dist[n].size() > 0){
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    for(int i=k-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}