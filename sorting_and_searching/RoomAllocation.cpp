#define pp pair<int,int>
#include<bits/stdc++.h>
using namespace std;
class cust{
public:
    int a,d,idx;
};
bool cmp(cust c1,cust c2){
    return c1.a<c2.a;
}
int main(){
    int n;
    cin>>n;
    vector<cust>time(n);
    for(int i=0;i<n;i++){
        cin>>time[i].a>>time[i].d;
        time[i].idx = i;
    }

    // cout<<endl;
    sort(time.begin(),time.end(),cmp);
    // for(int i=0;i<n;i++){
    //     cout<<time[i].a<<time[i].d<<endl;
    // }
    
    vector<int>allot(n);
    allot[time[0].idx] = 1;
    int maxA = 1;
    int curr = time[0].d;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({curr,1});
    for(int i=1;i<n;i++){
        if(pq.top().first < time[i].a){
            int j = pq.top().second;
            pq.pop();
            pq.push({max(curr,time[i].d),j});
            allot[time[i].idx] = j;
        }
        else {
            maxA++;
            pq.push({max(curr,time[i].d),maxA});
            allot[time[i].idx] = maxA;
        }
        curr = min(curr,time[i].d);
    }
    cout<<maxA<<endl;
    for(int i=0;i<n;i++){
        cout<<allot[i]<<" ";
    }
    
    return 0;
}