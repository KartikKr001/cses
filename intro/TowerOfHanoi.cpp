#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void toh(int n,int s,int h,int d){
    if(n <= 0) return;
    toh(n-1,s,d,h);
    ans++;
    toh(n-1,h,s,d);
}
void co(int n,int s,int h,int d){
    if(n <= 0) return;
    co(n-1,s,d,h);
    cout<<s<<" "<<d<<endl;
    co(n-1,h,s,d);
}

int main(){
    int n;
    cin>>n;
    toh(n,1,2,3);
    cout<<ans<<endl;
    co(n,1,2,3);
    return 0;

}