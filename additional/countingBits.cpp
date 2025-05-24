#define ll long long
#include<bits/stdc++.h>
using namespace std;

ll dp[64][64][2];
string binary;

// Recursive function to count '1' bits
ll countOneBits(int idx, bool isTight, ll countOnes) {

    if (idx == binary.size()) return countOnes;
    if (dp[idx][countOnes][isTight] != -1) return dp[idx][countOnes][isTight];

    int limit = (isTight) ? binary[idx] - '0' : 1;

    ll result = 0;
    for (int digit = 0; digit <= limit; digit++) {
        result += countOneBits(idx+1,(isTight & (digit == limit)),countOnes+(digit == 1));
    }
    return dp[idx][countOnes][isTight] = result;
}


int main(){
    ll n;
    cin>>n;
    // Convert the number n to its binary representation as a string
    string temp = bitset<64>(n).to_string();
    // Remove leading zeros
    temp = temp.substr(temp.find('1'));

    memset(dp,-1,sizeof dp);
    
    binary = temp;

    cout<<countOneBits(0, true, 0)<<endl;

}