#include<bits/stdc++.h>
using namespace std;
string st;
int expand(int i,int parity){
    int x = i-1,y = i+1;
    int ans = 1;

    while(x>=0 && y<st.size()){
        if(st[x] == st[y]){
            x--;y++;
            ans += 2;
        }
        else return ans;
    }
    return ans;
}
int main(){
    string s;
    st = "#";
    cin>>s;
    int n=s.size();
    int ans = 1;
    int start = 0;
    if(s.size() == 0) cout<<0<<endl;
    // manacher's algo
    for(int i=0;i<n;i++){
        st += (s[i]);
        st+='#';
    }

    for(int i=0;i<st.size();i++){
        int odd = expand(i,1);
        if(odd > ans){
            start = (i-((odd-1)/2));
            ans = odd;
        }
        // if(s[i]==s[i+1]){
        //     // O(n^2) in worst case
        //     int even = expand(i,0);
        //     if(even > ans){
        //         st = (i-((even/2)-1));
        //         ans = even;
        //     }
        // }
    }   
    cout<<s.substr(start/2,ans/2)<<endl;

    return 0;
}