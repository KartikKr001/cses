#define mod %1000000007
#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    vector<vector<int>> dp(1000001,vector<int>(2,0));
    int siz = 1000000;
    dp[siz][0] = 1;
    dp[siz][1] = 1;
    for(int i=siz-1;i>0;i--){
        dp[i][0] = ((((dp[i+1][0] mod)+(dp[i+1][0] mod))mod + ((dp[i+1][0] mod)+(dp[i+1][0] mod))mod) mod +(dp[i+1][1] mod)) mod;
        dp[i][1] = (((dp[i+1][1] mod) + (dp[i+1][1] mod))mod +(dp[i+1][0] mod)) mod;
    }

    while(testcase--){
        int n;
        cin>>n;
        cout<<(dp[siz-n+1][0] mod +dp[siz-n+1][1] mod) mod<<endl;
    }
    return 0;
}