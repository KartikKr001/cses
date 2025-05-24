#define pp pair<ll,ll>
#define tp tuple<ll,ll,ll>
#define ll long long
#include<bits/stdc++.h>
using namespace std;

vector<list<pp>> graph;
vector<vector<ll>>dist;
void djkstras(ll src,ll dest){
    priority_queue<tp, vector<tp>, greater<tp>> pq; // Min-heap priority queue
    dist[src][0] = 0;
    pq.push({0, src, false});
    
    while (!pq.empty()) {
        auto [current_dist, node, token_used] = pq.top();
        pq.pop();
        
        if (current_dist > dist[node][token_used]) continue;
        
        for (auto& [neighbor, weight] : graph[node]) {
            ll new_dist = current_dist + weight;
            
            if (new_dist < dist[neighbor][token_used]) {
                dist[neighbor][token_used] = new_dist;
                pq.push({new_dist, neighbor, token_used});
            }
            
            if (!token_used) {
                ll discounted_dist = current_dist + weight / 2;
                if (discounted_dist < dist[neighbor][1]) {
                    dist[neighbor][1] = discounted_dist;
                    pq.push({discounted_dist, neighbor, true});
                }
            }
        }
    }

}
int main(){
    ll n,m;
    cin>>n>>m;
    graph.clear();
    graph.resize(n+1,list<pair<ll,ll>>());
    dist.assign(n+1,vector<ll>(2,LONG_LONG_MAX));
    ll s,d,wt;
    while(m--){
        cin>>s>>d>>wt;
        graph[s].push_back({d,wt});
    }
    djkstras(1,n);
    cout<<min(dist[n][0],dist[n][1]);
    return 0;
}