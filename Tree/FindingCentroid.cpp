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
    // use precompute_factorial(n,m) first
    if (r > n || r < 0) return 0; if (r == 0) return 1; return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r], mod), mod);
}
vector<bool> sieve(int max_val) { vector<bool> is_prime(max_val + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= max_val; i++) {if (is_prime[i]) {for (int j = i * i; j <= max_val; j += i) {is_prime[j] = false;}}}return is_prime;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--) {
        ll n;
        cin>>n;
        if(n == 1) {
            cout<<1<<endl;
            return 0;
        }
        vector<vector<ll>>tree;
        tree.assign(n+1,vector<ll>());
        vector<ll>indegree(n+1);
        for(int i=0;i<n-1;i++){
            ll a,b;
            cin>>a>>b;
            indegree[a]++;
            indegree[b]++;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        vector<ll>cpy = indegree;
        queue<pp>q;
        map<ll,vector<ll>>mp;
        vector<ll>cnt(n+1);
        for(int i=1;i<=n;i++){
            if(indegree[i]==1){
                q.push({i,0});
                cnt[i] = 0;
            }
        }
        ll ans = -1;
        set<ll>vis;
        while(!q.empty()){
            ll node=q.front().first;
            ll level=q.front().second;
            q.pop();
            if(vis.count(node)) continue;
            ans = node;
            vis.insert(node);
            for(auto it:tree[node]){
                indegree[it]--;
                if(vis.count(it) == 0){
                    cnt[it] += cnt[node]+1;
                    mp[it].push_back(cnt[node]+1);
                }
                if(indegree[it]==1){
                    q.push({it,level+1});
                }
            }
        }
        auto v = (*mp.rbegin()).second;
        for(auto &x:mp){
            // cout<<x.first<<" : ";
            sort(x.second.begin(),x.second.end());
            ll sum = 0;
            bool flag = true;
            // for(auto y:x.second){
            //     cout<<y<<" ";
            // }
            for(auto y:x.second){
                if(y > n/2){
                    flag = false;
                    break;
                }
                sum += y;
            }
            if(flag){
                if((n-sum-1) > n/2) continue;
                else{
                    ans = x.first;
                    break;
                }
            }
            // cout<<endl;
        }
        // cout<<endl;
        // for(int i=0;i<=n;i++) cout<<i<<" ";
        // cout<<endl;
        // for(auto x:cnt){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        cout<<ans<<endl;
    // }
    return 0;
}
