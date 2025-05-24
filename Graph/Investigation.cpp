#include<bits/stdc++.h>
#define ll long long
#define mod %1000000007
using namespace std;
vector<list<vector<ll>>>graph; // src->{dest,wt}
ll n;
void djkstras(){
    vector<ll> dist(n+1,LLONG_MAX);
    vector<ll> ways(n+1,0);
    vector<ll> min_flights(n+1,0);
    vector<ll> max_flights(n+1,0);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq; //{wt,dest}
    dist[1] = 0;
    ways[1] = 1;
    pq.push({0,1,0});
    ll mina = LLONG_MAX;
    while(pq.size() > 0){
        auto curr = pq.top();
        ll d = curr[0];
        ll city = curr[1];
        pq.pop();

        if(d > dist[city]) continue;

        for(auto x:graph[city]){
            long long newDist = d+x[1];
            if(dist[x[0]] > newDist){
                dist[x[0]] = newDist;

                ways[x[0]] = ways[city];
                min_flights[x[0]] = min_flights[city]+1;
                max_flights[x[0]] = max_flights[city]+1;

                pq.push({newDist , x[0]});
            }
            else if(dist[x[0]] == newDist){
                ways[x[0]] = (ways[x[0]] + ways[city]) mod;
                min_flights[x[0]] = min(min_flights[x[0]],min_flights[city]+1);
                max_flights[x[0]] = max(max_flights[x[0]],max_flights[city]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<min_flights[n]<<" "<<max_flights[n]<<endl;
}
int main(){
    ll m;
    cin>>n>>m;
    graph.assign(n+1,list<vector<ll>>());
    ll a,b,wt;
    while(m--){
        cin>>a>>b>>wt;
        vector<ll>tedist = {b,wt};
        graph[a].push_back(tedist);
    }
    djkstras();
    return 0;
}