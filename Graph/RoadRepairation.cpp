#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<ll>par;
vector<ll>rnk;
ll find(ll x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void dsu(ll x,ll y){
    x=find(x);
    y=find(y);
    if(rnk[x] <= rnk[y]){
        par[x] = y;
        rnk[y]++;
    }
    else{
        par[y] = x;
        rnk[x]++;
    }
}
void kruskal(ll n,vector<vector<pp>>&graph){
    vector<vector<ll>> edges;
    for(int i=1;i<graph.size();i++){
        for(auto y:graph[i]){
            edges.push_back({y.second,y.first,i});
        }
    }
    sort(edges.begin(),edges.end());
    ll sum = 0;
    for(auto y:edges){
        if(find(y[1])!=find(y[2])){
            dsu(y[1],y[2]);
            sum+=y[0];
        }
    }
    set<ll>compo;
    for(int i=1;i<=n;i++){
        compo.insert(find(i));
    }
    if(compo.size() == 1) cout<<sum<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    par.assign(n+1,0);
    rnk.assign(n+1,1);
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    vector<vector<pp>> graph(n+1,vector<pp>());
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    kruskal(n,graph);d:\work\coding\cses\Tree\RoadContruction.cpp  
    return 0;
}
