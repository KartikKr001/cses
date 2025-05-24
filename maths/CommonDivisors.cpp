#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin>>n;

    vector<int>v(n);
    unordered_map<int,int> mp;
    int ans = 1;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    
    sort(v.begin(),v.end());
    int maxa = v[n-1];
    
    for(int i=maxa;i>=1;i--){
        int cnt = 0;
        for(int j=1;j*i<=maxa;j++){
            if(mp[i*j] > 0){
                cnt+=mp[i*j];
                if(cnt >= 2){
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<1<<endl;
    return 0;
}