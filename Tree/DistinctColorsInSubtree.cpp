#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<ll> fact,inv_fact;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  
map<ll, ll> prime_factorization(int x) { int i = 2; map<ll, ll> mp; while (i * i <= x) { while (x % i == 0) { mp[i]++; x /= i; } i++; } if (x > 1) mp[x]++; return mp;}
void precompute_factorial(ll n, ll m) { fact.assign(n + 1, 1); inv_fact.assign(n + 1, 1); for (ll i = 2; i <= n; i++) fact[i] = mod_mul(fact[i - 1], i, m); inv_fact[n] = expo(fact[n], m - 2, m); for (ll i = n - 1; i >= 0; i--) inv_fact[i] = mod_mul(inv_fact[i + 1], i + 1, m);}
ll nCr(ll n, ll r, ll mod) { 
    
    if (r > n || r < 0) return 0; if (r == 0) return 1; return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r], mod), mod);
}
vector<bool> sieve(int max_val) { vector<bool> is_prime(max_val + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= max_val; i++) {if (is_prime[i]) {for (int j = i * i; j <= max_val; j += i) {is_prime[j] = false;}}}return is_prime;}


vector<vector<ll>> tree;
ll timer;
vector<ll>tin;
vector<ll> tout;
vector<int> adj;
vector<set<ll>>st;
vector<ll>ans;
void dfs(int node, int par){
    for(int x : tree[node]) {
        if(x == par) continue;
        dfs(x, node);
        if (st[node].size() < st[x].size()) {
            swap(st[node], st[x]);
        }   
        for (auto y : st[x]){
            st[node].insert(y);
        }
    }
    ans[node] = st[node].size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        ll n;
        cin>>n;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        tree.assign(n+1,vector<ll>());
        for(int i=1;i<n;i++){
            ll a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        timer=0;
        tin.assign(n+1,0);
        ans.assign(n+1,0);
        tout.assign(n+1,0);
        st.clear();
        st.resize(n+1);
        for(int i=1;i<=n;i++){
            st[i].insert(v[i]);
        }
        dfs(1,-1);
        for(int i=1;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        
    // }
    return 0;
}
