#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<list<int>> graph;
int f(int i){
    if(ans[i] != -1) return ans[i];
    int subo = 0;
    for(auto x:graph[i]){
        subo += f(x);
    }
    return ans[i] = graph[i].size()+subo;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int ele;
    graph.clear();
    graph.resize(n+1,list<int>());
    ans.clear();
    ans.resize(n+1,-1);
    for(int i=2;i<=n;i++){
        cin>>ele;
        graph[ele].push_back(i);
    }
    for(int i=1;i<graph.size();i++) f(i);
    for(int i=1;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;

}