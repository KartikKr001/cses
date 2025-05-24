#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long a,b;
    while(t--){
        cin>>a>>b;
        int temp = max(a,b)-min(a,b);
        if(a-temp>=0 && b-temp>=0){
            if((max(a,b)-3*temp + min(a,b)) % 3 == 0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}