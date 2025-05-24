#include<bits/stdc++.h>
using namespace std;
class range{
public:
    int s,e,i;
};
bool cmp(range a,range b){
    if(a.s == b.s){
        return a.e>b.e;
    }
    return a.s<b.s;
}
int main(){
    int n;
    cin>>n;
    vector<range>rng(n);
    vector<int>par(n+1);
    vector<int>chi(n+1);
    for(int i=0;i<n;i++){
        cin>>rng[i].s>>rng[i].e;
        rng[i].i = i;
    }

    sort(rng.begin(),rng.end(),cmp);

    for(int j=0;j<n;j++){

    }
    
    for(int i=0;i<n;i++) cout<<par[i]<<" ";
    
    return 0;
}