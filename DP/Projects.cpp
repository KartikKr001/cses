#include<bits/stdc++.h>
using namespace std;
#define ll long long

class project{
public:
    ll st;
    ll en;
    ll val;
};

bool cmp(project a,project b){
    return a.en<b.en;
}

int main(){
    ll n;
    cin>>n;
    vector<project>v(n);

    for(int i=0;i<n;i++){
    cin>>v[i].st>>v[i].en>>v[i].val;
    }

    //Sort according to end times
    sort(v.begin(),v.end(),cmp);

    // precompute last non-conflicting project
    vector<int> last(n,-1);
    for(int i=0;i<n;i++){
        int low = 0,high = i-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(v[mid].en < v[i].st){
                last[i] = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    vector<ll> dp(n+1,0);
    // computing the answers
    for(int i=1;i<=n;i++){
        // max with dp[i-1] ensures the correct dp table
        dp[i] = max(dp[i-1],v[i-1].val);

        if(last[i-1] != -1) dp[i] = max(dp[i],v[i-1].val + dp[last[i-1] + 1]);
    }
    cout<<dp[n];



    return 0;
}
