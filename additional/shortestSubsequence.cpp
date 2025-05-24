#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

int main() {
	// int t;
	// cin>>t;
	// while(t--){
		// ll n,k;
		// cin>>n;
		// vector<ll> v(n);
		// for(int i=0;i<n;i++){
		// 	cin>>v[i];
		// }
        string s;
        cin>>s;
        int a=0,g=0,c=0,t=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'A') a++;
            else if(s[i] == 'G') g++;
            else if(s[i] == 'C') c++;
            else t++;
        }
        char ch;
        if(a <= min({a,g,c,t})) ch = 'A';
        else if(g <= min({a,g,c,t})) ch = 'G';
        else if(c <= min({a,g,c,t})) ch = 'C';
        else ch = 'T';
        string ans = "";
        for(int i=0;i<=min({a,g,c,t});i++){
            ans += ch;
        }
        cout<<ans<<endl;
	// }

}
