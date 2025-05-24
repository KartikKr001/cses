#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    multiset<int> tickets;
    cin>>n>>m;
    vector<int>cust(m);
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        tickets.insert(ele);
    }
    for(int i=0;i<m;i++){
        cin>>cust[i];
        auto it = tickets.upper_bound(cust[i]);
        if(it == tickets.begin()) cout<<-1<<endl;
        else{
            it--;
            cout<<*(it)<<endl;
            tickets.erase(it);
        }
    }
    
    return 0;

}