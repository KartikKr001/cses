#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sa;
string sb;
string upp;
int alp = 0;
ll f(string c,int idx,int prev){
    // cout<<c<<" :: "<<prev<<endl;
    if(c > upp) return 0;
    if(c < sa) return 0;
    if(idx >= sb.size()){
        if(c > sb) return 0;
        alp++;
        cout<<alp<<" : "<<c<<endl;
        return 1;
    }
    ll ans = 0;
    for(int i=0;i<=9;i++){
        if(i == prev) continue;
        c[idx] = char(i+48);
        ans += f(c,idx+1,i);
    }
    return ans;
}

int main(){
    ll a;
    ll b;
    cin>>a>>b;
    sa = to_string(a);
    sb = to_string(b);
    while(sa.size() < sb.size()) sa = '0'+sa;
    upp = sb;
    for(int i=0;i<upp.size();i++){
        upp[i] = max(sa[i],sb[i]);
    }
    cout<<f(sa,0,-1);
    return 0;
}