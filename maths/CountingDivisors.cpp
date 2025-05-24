#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> sieve(int n) {
    vector<int> ans;
    vector<bool> grid(n + 1, true);
    for (int i=2;i*i<=n; i++) {
        if(grid[i]){
            for(int j=i*i;j<=n;j+=i) {
                grid[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (grid[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    // finding prime factors
    // finding numbers whose gcd with n is 1
    vector<int>primes = sieve(1000006);
    while(t--){
        int n;
        cin>>n;
        // euclid's totient
        int ans = 1;
        int k = n;
        // number of divisors -> 
        for(int i=0;i<primes.size() && primes[i]*primes[i] <=n ;i++){
            int temp = 0;
            while(k % primes[i] == 0){
                temp ++;
                k /= primes[i];
            }
            ans *= (temp+1);
        }
        if (k > 1) {
            ans *= 2; // It is a prime itself, hence contributes 2 divisors
        }
        cout<<ans<<endl;
    }

    return 0;
}