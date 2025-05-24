#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int a,int b){
    return v[a] < v[b];
}
int main(){
    int n;
    cin>>n;
    int tar;
    cin>>tar;
    if(n < 2){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>ind = v;
    for(int i=0;i<n;i++) ind[i] = i;

    sort(ind.begin(),ind.end(),cmp);
    sort(v.begin(),v.end());
    
    int ans = 0;
    int i=0,j=n-1;
    while(j>i){
        int x = v[j]+v[i];
        if(x == tar){
            cout<<ind[i]+1<<" "<<ind[j]+1<<endl;
            return 0;
        }
        else if(x>tar){
            j--;
        }
        else i++;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}