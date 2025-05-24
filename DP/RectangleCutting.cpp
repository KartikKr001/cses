#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,b;
    cin>>l>>b;
    vector<vector<int>> dp; 
    dp.resize(b+2,vector<int>(l+2,INT_MAX));  // b x l
    
    for(int i=0;i<=min(l,b);i++) dp[i][i] = 0;
    for(int i=0;i<=l;i++) dp[0][i] = 0;
    for(int i=0;i<=b;i++) dp[i][0] = 0;

    for(int i=1;i<=b;i++){
        for(int j=1;j<=l;j++){
            if(i == j) continue;
            for(int k=1;k<=min(i,j);k++){
                if(j>k) dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                if(i>k) dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
        }
    }

    cout<<dp[b][l];
    return 0;
}