#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<list<int>> graph;
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<int>());
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int>q;
    unordered_map<int,int>visited;
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
    }
    return 0;
}