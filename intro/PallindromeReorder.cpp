#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    bool flag;
    if(s.size()%2 == 0) flag = false;
    else flag = true;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    string a="";
    char extra = '!';
    for(auto x:mp){
        if(x.second%2 != 0){
            if(flag == false){
                cout<<"NO SOLUTION"<<endl;
                return 0;
            }
            else{
                extra = x.first;
                flag = false;
            }
        }
    }
    mp[extra]--;
    for(auto x:mp){
        int temp = x.second;
        while(temp>0){
            a+=x.first;
            temp-=2;
        }
    }
    string b = a;
    reverse(b.begin(),b.end());
    if(extra != '!'){
        a = a+extra;
    }
    cout<<a+b<<endl;

    return 0;
}