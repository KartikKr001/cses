#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    set<int> st;
    for(int i=0;i<n;i++) cin>>coins[i];
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(auto x:st){
            temp.push_back(x+coins[i]);
        }
        for(int i=0;i<temp.size();i++) st.insert(temp[i]);
        st.insert(coins[i]);
    }
    cout<<st.size()<<endl;
    for(auto x:st){
        cout<<x<<" ";
    }
    return 0;
}