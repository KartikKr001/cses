#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    unordered_set<int>st;
    int i=0;
    int j=0;
    while(j<n){
        while(st.count(v[j]) == 1){
            st.erase(v[i++]);
        }
        ans = max(ans,j-i+1);
        st.insert(v[j]);
        j++;
    }
    cout<<ans<<endl;
}