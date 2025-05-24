#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,bool>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,true});
        v.push_back({b,false});
    }
    sort(v.begin(),v.end());
    int cust = 0;
    int ans = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].second == true){
            cust++;
            ans = max(ans,cust);
        }
        else{
            cust--;
        }
    }
    cout<<ans<<endl;
    return 0;
}