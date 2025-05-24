#include<bits/stdc++.h>
using namespace std;

string s;
string t;
int m,n;
vector<vector<int>> dp;
int f(int i,int j){
    if(i>=s.size() && j>=t.size()) return 0;
    if(i>=s.size()) return abs(n-j);
    if(j>=t.size()) return abs(m-i);
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = f(i+1,j+1);
    else return dp[i][j] = 1+min({f(i+1,j+1),f(i,j+1),f(i+1,j)});
}
int main(){
    cin>>s;
    cin>>t;
    m = s.size();
    n = t.size();
    dp.clear();
    dp.resize(m+2,vector<int>(n+2,-1));
    cout<<f(0,0)<<endl;
}