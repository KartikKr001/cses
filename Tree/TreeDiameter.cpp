#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
unordered_set<int>vis;
// flag = false for first bfs,true for second bfs
int bfs(int node,int max_dist,bool flag){
    queue<pp>q;
    q.push({node,0});
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int dist = curr.second;
        if(max_dist < dist){
            max_dist = dist;
            node = x;
        }
        vis.insert(x);
        for(auto neigh:graph[x]){
            if(vis.count(neigh) == 0){
                q.push({neigh,dist+1});
            }
        }
    }
    if(flag) return max_dist;
    else return node;
}



int main(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    graph.clear();
    graph.resize(n+1,list<int>());
    vis.clear();
    int e = n-1;
    int a,b;
    while(e--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // find farthest node from any random node (will always a farthest leaf node)
    // again find another farthest node from that farthest node 
    // both are leaf nodes
    // return that distance

    int nodeA = a;
    int max_dist = 0;
    nodeA = bfs(nodeA,max_dist,false);
    vis.clear();
    cout<<bfs(nodeA,0,true);
    return 0;
}