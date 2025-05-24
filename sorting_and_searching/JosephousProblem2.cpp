#include<bits/stdc++.h>
using namespace std;
set<int>v;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;  
    v.clear();
    for(int i=0;i<n;i++) v.insert(i+1);
    int i=0;
    while(v.size()>0){
        i = (i+k)%v.size();
        auto x=v.begin();
        int tempi = i;
        while(tempi--) x++;
        cout<<*x<<" ";
        v.erase(x);
    }
    return 0;
}