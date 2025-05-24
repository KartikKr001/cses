#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]] = i;
    }
    int curr = 0;
    int prev = -1;
    int ans = 1;
    int ele = 1;
    while(ele <= n){
        curr = mp[ele];
        if(prev != -1 && prev > curr){
            ans++;
        }
        prev = curr;
        ele++;
    }
    cout<<ans<<endl;

    return 0;
}