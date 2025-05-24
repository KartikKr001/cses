#include<bits/stdc++.h>
#define mod %1000000007
using namespace std;
vector<vector<int>> dp;
vector<int> arr;
int f(int m,int i,int prev){
    if(prev>m || prev <= 0) return 0;
    if(i>=arr.size()) return 1;
    if(dp[i][prev]!=-1) return dp[i][prev];
    if(arr[i] == 0){
        return dp[i][prev] = ((f(m,i+1,prev)mod + f(m,i+1,prev+1)mod)mod + f(m,i+1,prev-1)mod)mod;
    }
    else{
        if(abs(arr[i]-prev) > 1) return 0;
        else return dp[i][prev] = f(m,i+1,arr[i])mod;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    dp.clear();
    arr.clear();
    dp.resize(n+1,vector<int>(m+1,-1));
    arr.resize(n);
    for(int i=0;i<n;i++) cin>> arr[i];
    long long ans=0;
    if(arr[0] != 0) ans = f(m,0,arr[0])mod;
    else{   
        for(int i=1;i<=m;i++){
            ans = (ans mod +f(m,1,i)mod)mod;
        }
    }
    cout<<ans;
    return 0;
}