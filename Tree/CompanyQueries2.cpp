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
map<ll, ll> prime_factorization(int x) { int i = 2; map<ll, ll> mp; while (i * i <= x) { while (x % i == 0) { mp[i]++; x /= i; } i++; } if (x > 1) mp[x]++; return mp;}
vector<bool> sieve(int max_val) {
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_val; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_val; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}


vector<vector<ll>> uplift;
vector<vector<ll>> tree;
vector<ll> tin, tout;
ll timer, limit; // ceil(log2(n))

void dfs(ll node, ll par) {  // Function to calculate binary lifting table
    tin[node] = ++timer;
    uplift[node][0] = par;
    for (int i = 1; i <= limit; i++) {
        if (uplift[node][i-1] != -1){
            uplift[node][i] = uplift[uplift[node][i-1]][i-1];
        }
    }
    for (auto it : tree[node]) {
        if (it != par) {
            dfs(it, node);
        }
    }

    tout[node] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = limit; i >= 0; i--) {
        if (uplift[u][i] != -1 && !is_ancestor(uplift[u][i], v)) {
            u = uplift[u][i];
        }
    }
    return uplift[u][0];
}

ll get_kth_ancestor(ll u, ll k) {
    for (int i = limit; i >= 0; i--) {
        if ((1 << i) & k) {
            if (u == -1) return -1;
            u = uplift[u][i];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    tree.assign(n+1,vector<ll>());
    for (int i=2;i<=n;i++){
        ll ele;
        cin>>ele;
        tree[i].push_back(ele);
        tree[ele].push_back(i);
    }

    timer = 0;
    limit = ceil(log2(n+1));
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    uplift.assign(n+1, vector<ll>(limit+1,-1));
    dfs(1,-1); 
    while(q--){
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}
