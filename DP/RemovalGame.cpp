#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

ll dp[5003][5003][2];
vector<ll>v;
long long f(int i,int j,bool flag){
    if(i > j) return 0;
    if(dp[i][j][flag] != 1e10) return dp[i][j][flag];
    if(flag){
        return dp[i][j][flag] = max(v[i]+f(i+1,j,!flag),v[j]+f(i,j-1,!flag));
    }
    else{
        return dp[i][j][flag] = min(f(i+1,j,!flag),f(i,j-1,!flag));
    }
}
int main(){
    int n;
    cin>> n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<5003;i++){
        for(int j=0;j<5003;j++){
            dp[i][j][0] = 1e10;
            dp[i][j][1] = 1e10;
        }
    }
    cout<<f(0,n-1,1)<<endl;
    return 0;

}