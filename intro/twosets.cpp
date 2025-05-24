#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    int st1 = 0;
    vector<bool>v(n+2,false);
    if(n*(n+1) % 4 != 0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        ll target = n*(n+1)/4;
        for(int i=n;i>=1;i--){
            if(target == 0) break;
            if(v[i] == false && i<=target){
                v[i] = true;
                target -= i;
                st1++;
            }
        }
        cout<<st1<<endl;
        for(int i=1;i<=n;i++){
            if(v[i])
                cout<<i<<" ";
        }
        cout<<endl;
        cout<<n-st1<<endl;
        for(int i=1;i<=n;i++){
            if(v[i] == false)
                cout<<i<<" ";
        }
        cout<<endl;
    }   
    return 0;
}