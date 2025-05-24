#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++) q.push(i);
    int flag = true;
    while(q.size()>0){
        if(flag) q.push(q.front());
        q.pop();
        if(flag) cout<<q.front()<<" ";
        flag = !flag;
    }
    return 0;
}