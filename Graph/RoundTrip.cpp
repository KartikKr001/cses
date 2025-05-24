#include <bits/stdc++.h>
using namespace std;


vector<int> parent_mapping;
vector<vector<int>> graph;
vector<bool> visited;

void add_edge(int src, int dest, bool bi_direc = true) {
    graph[src].push_back(dest);
    if (bi_direc) graph[dest].push_back(src);
}
int cycle_start = -1;
int cycle_end = -1;

bool dfs(int s, int par) {
    visited[s] = true;
    for (auto x : graph[s]) {
        if (x == par) continue;  // skip the parent node
        if (visited[x]) {
            // Found a cycle
            cycle_start = x;
            cycle_end = s;
            return true;
        }
        parent_mapping[x] = s;
        if (dfs(x, s)) return true;
    }
    return false;
}


int main() {
    int v, e;
    parent_mapping.clear();
    graph.clear();
    cin >> v >> e;
    graph.resize(v + 1, vector<int>());
    parent_mapping.resize(v+1,-1);
    visited.resize(v+1,false);

    int s, d; // source and destination
    while (e--) {
        cin >> s >> d;
        add_edge(s, d);
    }

    for(int i=1;i<=v;i++){
        if (!visited[i] && dfs(i, -1)) break;
    }
    if(cycle_end != -1){
        
        vector<int> ans;
        ans.push_back(cycle_start);    
        for(int temp = cycle_end;temp!=cycle_start;temp = parent_mapping[temp]) {
            ans.push_back(temp);
        }
        ans.push_back(cycle_start);

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
