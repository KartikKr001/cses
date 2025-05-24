#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int>indegree;
vector<int>dist;
vector<int>par;


void longestPath(int src,int dest){
    dist[src] = 0;
    int n = dest;
    queue<int>q;
    for(int i=1;i<=dest;i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> ans;

    while(q.size()>0){
        auto curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto x:graph[curr]){
            if(indegree[x] > 0) indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    
    for (int i=0;i<n;i++) {
        int u = ans[i];
        if (dist[u] != INT_MIN) { // If u is reachable
            for (int v : graph[u]) {
                if (dist[u] + 1 > dist[v]) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                }
            }
        }
    }
    
    //  destination is unreachable
    if (dist[dest] == INT_MIN) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;
    for (int v = dest; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout<<(dist[dest] + 1)<<endl; // Length of the longest path
    for (int v : path) {
        cout<<v<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    // using longestPathlogial sorting 
    // normal bfs gives tle
    int n,m;
    cin>>n>>m;
    graph.assign(n+1,vector<int>());
    indegree.assign(n+1,0);
    dist.assign(n+1,INT_MIN);
    par.assign(n+1,-1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    longestPath(1,n);
    return 0;
}