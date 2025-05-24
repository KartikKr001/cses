#define mod %1000000007
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(int a,int b){
    if(b == 0) return 1;
    if(a == 0) return 0;
    if(b == 1) return a;
    ll ans = power(a,b/2);
    if(b%2) return (((ans mod)*(ans mod) mod)*a)mod;
    return ((ans mod)*(ans mod) mod);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<power(a,b) mod<<endl;
    }
    return 0;
}