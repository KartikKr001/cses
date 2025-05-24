#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(pp a,pp b){
        return a.second < b.second;
    }
};


vector<list<pair<int,int>>> graph;
int djkstras(int src,int dest){
    priority_queue<pp,vector<pp>,cmp> q;
    unordered_map<int,int>dist;
    unordered_set<int>vis;
    for(int i=1;i<=dest;i++) dist[dest] = -1;
    dist[1] = 0;
    q.push({src,0});
    while(q.size()>0){
        auto curr = q.top();
        int s = curr.first;
        int val = curr.second;
        // cout<<s<<" "<<val<<endl;
        if(vis.count(s) == 1) continue;
        for(auto x:graph[s]){
            if(dist[x.first] < dist[s] + x.second){
                dist[x.first] = dist[s] + x.second;
                q.push({x.first,dist[x.first]});
            }
        }
        q.pop();
        vis.insert(s);
    }
    // for(auto x:dist){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    return dist[dest];
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.clear();
    graph.resize(n+1,list<pair<int,int>>());
    int s,d,wt;
    while(m--){
        cin>>s>>d>>wt;
        graph[s].push_back({d,wt});
        graph[d].push_back({s,wt});
    }
    cout<<djkstras(1,n);


    return 0;
}