#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, a, b;
    cin>>n>>a>>b;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<ll> prefixSum(n+1, 0);
    prefixSum[0] = 0;
    // taking first element of prefix array 0 
    // for -> pref[i+x] - pref[i-1] = v[x];
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + v[i-1];
    }


    // we will iterate through all possible [a,b] in [0,n-1]
    // now we see that for paticular index i
    // possible ans will be in index x = [i+a-1,i+b-1]
    // in each iteration sum = pref[x]-pref[i-1];
    // we see that sum depends on pref[x] where for paticular iteration pref[i-1] is constant
    // so we take using a set<int,int> where largest value on top
    // at every point update maxSum
    // after one iteration from [i+a-1,i+b-1] delete (i+a-1)th pair from set
    // ensuring only required elements are present in set
    // add new element in set

    multiset<ll> st;
    // initializing elements in set
    for(int i=a;i<=min(n,b);i++){
        st.insert(prefixSum[i]);
    }

    // traversing in prefix array
    // 0th index is 0
    ll maxSum = LLONG_MIN;
    for(int i=1;i<=n-a+1;i++){
        // finding largest element
        auto curr = *st.rbegin();
        maxSum = max(maxSum,curr - prefixSum[i-1]);
        // deleting i+a-1 th element and adding i+b-1 th element
        if(i+a-1 <= n) st.erase(st.find(prefixSum[i+a-1]));
        // adding next element
        if(i+b <= n) st.insert(prefixSum[i+b]);
    }

    cout<<maxSum<<endl;



    return 0;
}
