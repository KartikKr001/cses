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
vector<ll>par;
vector<ll>siz;
ll maxa;
ll compo;
ll find(ll a){
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}
void dsu(ll a,ll b){
    a = find(a);
    b = find(b);    
    if(a != b) compo--;
    else return;
    if(siz[a] <= siz[b]){
        par[a] = b;
        siz[b] += siz[a];
    }
    else{
        par[b] = a;
        siz[a] += siz[b];
    }
    maxa = max({maxa,siz[a],siz[b]});
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    par.assign(n+1,0);
    siz.assign(n+1,1);
    for(int i=1;i<=n;i++) par[i] = i;
    maxa = 0;
    compo = n;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        dsu(a,b);
        cout<<compo<<" "<<maxa<<endl;
    }
    
    return 0;
}
