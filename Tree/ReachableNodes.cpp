#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

int main() {
    // ll t;
    // cin >> t;

    // while (t--) {
    //     ll n, k;
    //     cin>>n>>k;

    ll n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n+1,vector<int>());
    vector<int>indegree(n+1);
    while(e--){
        int a,b;
        cin>>a>>b;
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(auto x:graph[i]) indegree[x]++;
    }
    vector<int>cpy = indegree;
    queue<int>q;
    vector<int>temp(n+1,-1);
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            temp[i] = 1;
            q.push(i);
        }
    }
    while(q.size() > 0){
        int curr = q.front();
        q.pop();
        for(auto x:graph[curr]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
            temp[x] = max(temp[x],temp[curr]+1);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<temp[i]-max(indegree[i]-1,0)<<" ";
    }
    cout<<endl;


    // }
    return 0;
}
