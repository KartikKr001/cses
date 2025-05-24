#include<bits/stdc++.h>
using namespace std;
#define ll long long
class key{
public:
    ll val,idx;
};

bool cmp(key a,key b){
    return a.val < b.val;
}
int main(){
    ll n,t;
    cin>>n>>t;
    vector<key>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].val;
        v[i].idx = i;
    }

    sort(v.begin(),v.end(),cmp);

    int i,j,left,right;
    ll sum;
    for(i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            left = j+1;
            right = n-1;
            while(left < right){
                sum = v[i].val+v[j].val+v[left].val+v[right].val;
                if(sum < t){
                    left++;
                }
                else if(sum == t){
                    cout<<v[i].idx+1<<" "<<v[j].idx+1<<" "<<v[left].idx+1<<" "<<v[right].idx+1<<endl;
                    return 0;
                }
                else if(sum > t){
                    right--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}