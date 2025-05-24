    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;

    int main(){
        int n,x;
        cin>>n>>x;

        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        
        ll ans = 0;
        ll sum = 0;
        map<ll,int> mp;
        mp[0]++; 
        for(int i=0;i<n;i++){
            sum += v[i];
            ans += mp[sum-x];
            mp[sum]++;
        }

        cout<<ans;
        return 0;
    }