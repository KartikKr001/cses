#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void f(string s,int n,bool flag){
    if(n == 1){
        if(flag){
            cout<<s+char(v[0]+48)<<endl;
            cout<<s+char(v[1]+48)<<endl;
        }
        else{
            cout<<s+char(v[1]+48)<<endl;
            cout<<s+char(v[0]+48)<<endl;
        }
        return ;
    }
    if(flag){
        f(s+'0',n-1,flag);
        f(s+'1',n-1,!flag); 
    }
    else{
        f(s+'1',n-1,!flag); 
        f(s+'0',n-1,flag);
    }
}
int main(){
    int n;
    cin>>n;
    v.clear();
    v.resize(2);
    v[1] = 1;
    string s = "";
    f(s,n,true);
    return 0;
}