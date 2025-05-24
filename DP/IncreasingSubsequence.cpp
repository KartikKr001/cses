#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<int> temp;
    temp.push_back(v[0]);

    for(int i=1;i<n;i++){
        if(v[i] > temp.back()){
            temp.push_back(v[i]);
        }
        else {
            int ind = lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
            temp[ind] = v[i];
        }
    }
    cout<<temp.size();
    return 0;
}