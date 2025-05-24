#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    stack<int> st;
    vector<int> ans(n);
    st.push(0);
    ans[0] = 0;

    for(int i=1;i<n;i++){
        while(st.size()>0 && v[st.top()] >= v[i]) st.pop();
        if(st.size()>0){
            ans[i] = st.top()+1;
        }else {
            ans[i] = 0;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";

    
    return 0;
}