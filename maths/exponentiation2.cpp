#define mod 1000000007
#define mod2 1000000006
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(int a,int b,int temp){
    if(b == 0) return 1;
    if(a == 0) return 0;
    if(b == 1) return a;
    ll ans = power(a,b/2,temp);
    if(b%2) return (((ans % temp)*(ans % temp) % temp)*a)% temp;
    return ((ans % temp)*(ans % temp) % temp);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        ll expo = power(b,c,mod2);
        cout<<power(a,expo,mod)<<endl;
    }
    return 0;
}