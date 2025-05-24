#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

template <typename... Args>
struct State;
template <typename T, typename... Rest>
struct State<T, Rest...> {
    T value;
    State<Rest...> next;

    State(T v, Rest... rest) : value(v), next(rest...) {}

    bool operator==(const State &other) const {
        return value == other.value && next == other.next;
    }
};

struct EmptyState {
    bool operator==(const EmptyState &) const { return true; }
};

struct StateHash {
    template <typename T>
    size_t combine(size_t seed, const T &val) const {
        return seed * 31 + hash<T>()(val);
    }

    template <typename... Args>
    size_t operator()(const State<Args...> &s) const {
        return hashState(s, 17); 
    }

private:
    template <typename T, typename... Rest>
    size_t hashState(const State<T, Rest...> &s, size_t seed) const {
        return hashState(s.next, combine(seed, s.value));
    }

    size_t hashState(const EmptyState &, size_t seed) const {
        return seed;
    }
};
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
    ll t;
    t = 1;
    // Sample State of making hashState (3 integers,2 bool)
    // using MyState = State<int,int,int,bool,bool>;

    // unordered_map<MyState,int,StateHash> dp;
    // MyState s1(1, 10, 20, true, false);
    // MyState s2(2, 15, 30, false, true);
    // dp[s1] = 100;    -> (state:hash)
    // dp[s2] = 200;

    while (t--) {
        ll n,k;
        ll a,b,x,c;
        cin>>n>>k;
        cin>>x>>a>>b>>c;
        vector<ll> v(n);
        v[0] = x;
        for(int i=1;i<n;i++){
            v[i] = (a*v[i-1] + b) % c;
        }
        ll ans = 0;
        if(k == 1){
            for(int i=0;i<n;i++){
                if(k%2) ans ^= v[i];
            }
            cout<<ans<<endl;
            return 0;
        }
        vector<ll>temp(n);
        for(int i=0;i<k-1;i++){
            if((i+1)%2){
                ans ^= v[i];
            } 
            temp[i] = (i+1);
        }
        int en = -1;
        for(int i=0;i<k-1;i++){
            if((i+1)%2){
                ans ^= v[n-i-1];
            } 
            temp[n-1-i] = (i+1);
            en = n-i-1;
        }
        for(int i=k;i<en;i++){
            temp[i] = k;
            if(k%2) ans ^= v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
