#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>par(n+1,0);
    vector<int>sum(n+1,0);
    int a,b;
    par[1] = 1;
    sum[1] = 1;
    int e = n-1;
    while(e--){
        cin>>a>>b;
        par[b] = a;
        sum[b] = b+sum[a];
    }
    while(q--){
        cin>>a>>b;
        cout<<sum[b]-sum[a]+a<<endl;
    }




    
    return 0;
}