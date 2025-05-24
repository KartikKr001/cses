#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ele = 0;
    long long sum = 0;
    for(int i=1;i<n;i++){
        cin>>ele;
        sum += ele;
    }
    cout<<(n*(n+1)/2)-sum<<endl;

    return 0;
}