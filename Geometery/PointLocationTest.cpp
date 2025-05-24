#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long
int main(){
    int t;
    cin>>t;
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    for(int i=0;i<t;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        ll temp1 = (y2-y1)*(x3-x4);
        ll temp2 = (y3-y4)*(x2-x1);
        if(temp1 == temp2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}