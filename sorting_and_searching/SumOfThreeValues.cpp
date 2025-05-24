#include<bits/stdc++.h>
using namespace std;
#define ll long long
class key{
public:
    ll val,idx;
};

bool cmp(key a,key b){
    return a.val < b.val;
}
int main(){
    ll n,t;
    cin>>n>>t;
    vector<key>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].val;
        v[i].idx = i;
    }

    sort(v.begin(),v.end(),cmp);
    int i,j,k;

    for(int i=0;i<n-2;i++){
        j = i+1;
        k = n-1;
        while(j<k){
            ll sum = v[i].val+v[j].val+v[k].val;
            if(sum < t){
                
                j++;
            }
            if(sum >= t){
                k--;
            }
        }
    }


    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}