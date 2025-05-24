#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool valid(vector<ll>&v,ll k,ll val){
    ll currSum = 0;
    ll partit = 1;
    for(ll i=0;i<v.size();i++){
        currSum += v[i];
        if(currSum > val){
            partit ++;
            currSum = v[i];
        }
    }
    if(partit <= k) return true;
    return false;

}

ll bin_search(vector<ll>&v,ll k,ll low,ll high){
    ll mid = (low+high)/2;
    ll ans = -1;
    while(low<=high){
        mid = (low+high)/2;
        if(valid(v,k,mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    ll n,k;
    cin>>n>>k;

    vector<ll>v(n);
    ll low = INT_MIN;
    ll high = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        low = max(low,v[i]);
        high += v[i];
    }
    
    // binary search b/w max element of array and sum of all elements
    // for a paticular mid value -> check if for that val,if minimum partitions made are less than k

    cout<<bin_search(v,k,low,high);

    return 0;
}