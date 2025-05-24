#include <bits/stdc++.h>
using namespace std;
void bfs(){
    // dete
}
int main(){
    int m,n;
    cin>>n>>m;
    int a,b;
    vector<list<int>> graph;
    vector<list<int>> new_graph;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return 0;
}
