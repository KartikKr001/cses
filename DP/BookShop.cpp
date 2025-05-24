#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> cost(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n,vector<int>(x,0));
    for(int i=0;i<n;i++) cin>>cost[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    int c = dp[0].size();
    int r = dp.size();

    for(int i=0;i<c;i++){
        dp[r-1][i] = 0;
    }
    for(int i=0;i<r;i++){
        dp[i][0] = 0;
    }

    for(int i=r-2;i>=0;i--){
        for(int j=1;j<c;j++){
            if(j-cost[i] >= 0) dp[i][j] = max(dp[i+1][j],pages[i]+dp[i][j-cost[i]]);
            else dp[i][j] = dp[i+1][j];
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[n-1][x-1];

    return 0;
}