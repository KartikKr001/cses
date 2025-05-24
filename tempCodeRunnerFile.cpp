#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;
vector<list<pp>> graph;
void add_edge(int src,int dest,int wt,bool bi_direc=true){
    graph[src].push_back({dest,wt});
    if(bi_direc){
        graph[dest].push_back({src,wt});
    }
}

map<int,pp> dijkstras(int src,int n){
    // O((v+e)logV)
    map<int,pp> mp;    //mp[src] = dist,via
    unordered_set<int> visited;
    priority_queue<pp,vector<pp>,greater<pp>> pq;  //wt-dest
    for(int i=0;i<n;i++){
        mp[i] = {INT_MAX,-1};
    }
    mp[src] = {0,src};
    pq.push({0,src});
    while(pq.size() > 0){
        pp curr = pq.top();
        pq.pop();
        if(visited.count(curr.second) == 1) continue;
        for(auto neigh : graph[curr.second]){
            // relaxation algo
            if(mp[neigh.first].first > mp[curr.second].first+neigh.second){
                // mp[curr.second].first ==> shortest dist src to curr
                mp[neigh.first].first  =  curr.first+neigh.second;
                mp[neigh.first].second  =  curr.second;
                pq.push({mp[neigh.first].first , neigh.first});
            }
        }
        visited.insert(curr.second);
    }
    for(auto x:mp){
        cout<<x.first<<" "<<x.second.first<<endl;
    }
    return mp;
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<"{"<<x.first<<" , "<<x.second<<"} ,";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    graph.clear();
    graph.resize(n,list<pp>());
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        add_edge(s,d,w);
    }