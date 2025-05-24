#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>st;
// build st
void build(int i,int low,int high){
    if(low == high){
        st[i] = v[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*i+1,low,mid);
    build(2*i+2,mid+1,high);
    st[i] = st[2*i+1]^st[2*i+2];
}


int range(int i,int low,int high,int l,int r){
    if(low>=l && high<=r) return st[i];
    if(low>r || l>high) return 0;
    int mid = (low+high)/2;
    return (range(2*i+1,low,mid,l,r)^range(2*i+2,mid+1,high,l,r));
}
int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    v.clear();
    st.clear();
    v.resize(n);
    st.resize(4*n,INT_MAX);
    for(int i=0;i<n;i++) cin>>v[i];
    build(0,0,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<range(0,0,n-1,l-1,r-1)<<endl;
    }

}