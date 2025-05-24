#include<bits/stdc++.h>
using namespace std;
set<string>fin;
void f(string &s,int a){
    if(a>=s.size()){
        fin.insert(s);
        return;
    }
    unordered_set<string>st;
    for(int i=a;i<s.size();i++){
        swap(s[a],s[i]);
        if(st.count(s) == 0){
            st.insert(s);
        }
        else {
            swap(s[a],s[i]);
            continue;
        }
        f(s,a+1);
        swap(s[a],s[i]);
    }
    return;
}
int main(){

    string s;
    fin.clear();
    cin>>s;
    f(s,0);
    cout<<fin.size()<<endl;
    for(auto x:fin){
        cout<<x<<endl;
    }
    return 0;
}