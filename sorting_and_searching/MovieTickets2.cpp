#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a,b;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    while(n--){
        cin>>a>>b;
        pq.push({b,a});
    }
    multiset<int> st;
    int ans = 0;
    while(pq.size() > 0){
        auto curr = pq.top();
        pq.pop();

        auto it = st.upper_bound(curr.second);
        if(it != st.begin()){
            it--;
            st.erase(it);
        }

        if(st.size() < k){
            st.insert(curr.first);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}