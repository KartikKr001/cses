#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<int>maxH;
priority_queue<int,vector<int>,greater<int>>minH;
int a,b;
// each representing size of max and min heap
multiset<int>window;
void insertPQ(int ele){
    // balancing heaps
    while(a > b+1){
        minH.push(maxH.top());
        b++;
        maxH.pop();
        a--;
    }
    while(b > a+1){
        maxH.push(minH.top());
        a++;
        minH.pop();
        b--;
    }

    // error here
    // maxH.top() > minH
    if(a > 0 && ele > maxH.top()){
        minH.push(ele);
        b++;
    }
    else{
        maxH.push(ele);
        a++;
    }

    // balancing heaps
    while(a > b+1){
        while(window.count(maxH.top()) > 0){
            window.erase(window.find(maxH.top()));
            maxH.pop();
        }
        minH.push(maxH.top());
        b++;
        maxH.pop();
        a--;
    }
    while(b > a+1){
        while(window.count(minH.top()) > 0){
            window.erase(window.find(minH.top()));
            minH.pop();
        }
        maxH.push(minH.top());
        a++;
        minH.pop();
        b--;
    }
}
void removePQ(int ele){
    if(ele > maxH.top()) b--;
    else a--;
    while(window.count(maxH.top()) > 0){
        window.erase(window.find(maxH.top()));
        maxH.pop();
    }
    while(window.count(minH.top()) > 0){
        window.erase(window.find(minH.top()));
        minH.pop();
    }
}
int find_med(){
    if(a >= b) return maxH.top();
    else return minH.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    a = 0,b = 0;
    for(int i=0;i<k;i++){
        insertPQ(v[i]);
    }
    int i=0;
    while(i+k < n){
        cout<<find_med()<<" ";
        window.insert(v[i]);
        removePQ(v[i]);
        insertPQ(v[i+k]);
        i++;
    }
    cout<<find_med()<<" ";
    return 0;
}