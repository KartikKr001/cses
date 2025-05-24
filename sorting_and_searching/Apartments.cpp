#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> des(n);
    vector<int> apar(m);
    for(int i=0;i<n;i++){
        cin>>des[i];
    }
    for(int i=0;i<m;i++){
        cin>>apar[i];
    }
    sort(des.begin(),des.end());
    sort(apar.begin(),apar.end());
    int i=0,j=0;
    int ans = 0;
    while(i<n && j<m){
        if(abs(des[i]-apar[j]) <= k){
            ans++;
            i++,j++;
        }
        else if(des[i] > apar[j]){
            j++;
        }
        else i++;
    }
    cout<<ans<<endl;
}