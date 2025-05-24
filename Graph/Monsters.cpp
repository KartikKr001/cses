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
    //  use precompute_factorial(n,m) first
    if (r > n || r < 0) return 0; if (r == 0) return 1; return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r], mod), mod);
}
vector<bool> sieve(int max_val) { vector<bool> is_prime(max_val + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= max_val; i++) {if (is_prime[i]) {for (int j = i * i; j <= max_val; j += i) {is_prime[j] = false;}}}return is_prime;}

vector<vector<char>> graph;
vector<vector<ll>> bfs(int n,int m,queue<vector<ll>>q){
    vector<vector<ll>>ans(n,vector<ll>(m,-1));
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x[0];
        int j = x[1];
        int k = x[2];
        if(ans[i][j] != -1) continue;
        ans[i][j] = k;
        if(i-1>=0 && ans[i-1][j]==-1 && graph[i-1][j] == '.'){
            q.push({i-1,j,k+1});
        }
        if(i+1<ans.size() && ans[i+1][j]==-1 && graph[i+1][j] == '.'){
            q.push({i+1,j,k+1});
        }
        if(j-1>=0 && ans[i][j-1]==-1 && graph[i][j-1] == '.'){
            q.push({i,j-1,k+1});
        }
        if(j+1<ans[0].size() && ans[i][j+1] == -1 && graph[i][j+1] == '.'){
            q.push({i,j+1,k+1});
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.assign(n,vector<char>(m,'.'));
    vector<vector<ll>>distM(n,vector<ll>(m));
    vector<vector<ll>>distA(n,vector<ll>(m));
    queue<vector<ll>>q;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'A'){
                q.push({i,j,0});
                x = i;
                y = j;
            }
        }
    }
    graph[x][y] = '.';
    distA = bfs(n,m,q);
    
    //  for(auto x:distA){
    //      for(auto y:x){
    //          cout<<y<<" ";
    //      }
    //      cout<<endl;
    //  }
    //  cout<<endl;
    //  cout<<endl;
    while(q.size() > 0) q.pop();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'M'){
                q.push({i,j,0});
            }
        }
    }

    distM = bfs(n,m,q);
    //  for(auto x:distM){
    //      for(auto y:x){
    //          cout<<y<<" ";
    //      }
    //      cout<<endl;
    //  }


    //  cout<<endl;
    //  cout<<endl;
    vector<vector<char>>ans(n,vector<char>(m,'n'));
    ans[x][y] = 'y';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(distA[i][j] != -1 && (distM[i][j] > distA[i][j] || distM[i][j] == -1)){
                ans[i][j] = 'y';
            }
        }
    }

    //  for(int i=0;i<n;i++){
    //      for(int j=0;j<m;j++){
    //          cout<<ans[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }

    string fin = "";
    int xx = -1;
    int yy = -1;
    for(int i=0;i<n;i++){
        if(ans[i][0] == 'y'){
            xx = i;
            yy = 0;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i][m-1] == 'y'){
            xx = i;
            yy = m-1;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(ans[0][i] == 'y'){
            xx = 0;
            yy = i;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(ans[n-1][i] == 'y'){
            xx = n-1;
            yy = i;
            break;
        }
    }
    if(xx != -1 && yy != -1){
    while(xx != x || yy != y){
            //  cout<<xx<<" "<<yy<<endl;
            if(xx - 1 >= 0 && ans[xx-1][yy] == 'y'){
                ans[xx][yy] = 'n';
                xx--;
                fin += "D";
            }
            else if(xx + 1 < n && ans[xx+1][yy] == 'y'){
                ans[xx][yy] = 'n';
                xx++;
                fin += "U";
            }
            else if(yy + 1 < m && ans[xx][yy+1] == 'y'){
                ans[xx][yy] = 'n';
                yy++;
                fin += "L";
            }
            else if(yy - 1 >= 0 && ans[xx][yy-1] == 'y'){
                ans[xx][yy] = 'n';
                yy--;
                fin += "R";
            }
        }
        cout<<"YES"<<endl;
        cout<<fin.size()<<endl;
        reverse(fin.begin(),fin.end());
        cout<<fin<<endl;
    }else cout<<"NO"<<endl;
}



