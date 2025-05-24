#include<bits/stdc++.h>
using namespace std;
#define mod %1000000007
int n;
vector<vector<int>>dp;
int f(int i,int target){
    if(i>n) return 0;
    if(target < 0) return 0;
    if(target == 0) return 1;
    if(dp[i][target] != -1) return dp[i][target];
    return dp[i][target] = (f(i+1,target) mod +f(i+1,target-i) mod) mod;
}
int main(){
    cin>>n;
    if((n*(n+1)) % 4 != 0) cout<<0<<endl;
    else {
        dp.clear();
        dp.resize(n+1,vector<int>((n*(n+1)/4)+2,-1));
        int ans = f(1,n*(n+1)/4);
        cout<<ans<<endl;
    }
}
