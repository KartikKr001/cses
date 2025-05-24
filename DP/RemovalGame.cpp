#include<bits/stdc++.h>
using namespace std;
long long dp[5003][5003];
vector<int>num;
long long f(int i,int j){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max({min(num[i]+f(i+2,j),num[i]+f(i+1,j-1)),min(num[j]+f(i+1,j-1),num[j]+f(i,j-2))});
}
int main(){
    int n;
    cin>> n;
    num.clear();
    num.resize(n);
    for(int i=0;i<n;i++) cin>>num[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,n-1)<<endl;
    return 0;

}