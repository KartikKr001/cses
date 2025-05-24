#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
vector<int>team;
bool bfs(int x){
    queue<pair<int,int>> q;
    q.push({x,1});
    team[x] = 1;
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        int val = curr.first;
        int num = curr.second;
        for(auto y:graph[val]){
            if(team[y] == 0){
                q.push({y,3-num});
                team[y] = 3-num;
            }   
            else if(team[val] == team[y]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    graph.clear();
    team.clear();
    graph.resize(n+1,list<int>());
    team.resize(n+1,0);
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(team[i] == 0){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }    
    for(int i=1;i<=n;i++){
        cout<<team[i]<<" ";
    }

    return 0;
}