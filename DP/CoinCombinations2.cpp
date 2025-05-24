#define mod %1000000007
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int f(vector<int> &arr,int i,int target){
    if(target == 0) return 1;
    if(target < 0 || i>=arr.size()) return 0;
    if(dp[i][target] != -1) return dp[i][target];
    return dp[i][target] = (f(arr,i,target-arr[i]) mod + f(arr,i+1,target) mod) mod;
}
int main(){
    int n;
    int target;
    cin>>n>>target;
    dp.clear();
    dp.resize(n+1,vector<int>(target+1));
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) dp[i][0] = 1;

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=target;j++){
            int skip = 0;
            int pick = 0;
            if(j-arr[i]>=0) {
                pick = (dp[i][j-arr[i]]) mod;
            }
            if(i<n-1){
                skip = (dp[i+1][j]) mod;
            }
            dp[i][j] = (skip+pick) mod;
        }
    }

    cout<<dp[0][target] mod;
    return 0;
}