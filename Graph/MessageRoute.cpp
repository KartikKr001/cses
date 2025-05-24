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

    int src = 1;
    int dest = n;
    queue<pp>q;
    q.push({1,0});
    unordered_map<int,int>visited;
    visited[1] = 0;
    int start = -1;
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        if(visited.size()>=n) break;
        int node = curr.first;
        int prev = curr.second;
        for(auto neigh:graph[node]){
            if(visited.count(neigh) == 0){
                q.push({neigh,node}); 
                visited[neigh] = node;
            }
        }
    }
    if(visited.count(n) == 0) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> temp;
        int a = n;
        while(a != 1){
            temp.push_back(a);
            a = visited[a];
        }
        temp.push_back(1);
        cout<<temp.size()<<endl;
        for(int i=temp.size()-1;i>=0;i--) cout<<temp[i]<<" ";
    }







    return 0;
}