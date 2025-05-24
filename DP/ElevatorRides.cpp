#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    int totalMasks = 1 << n;
    vector<int> dp(totalMasks, n + 1); // Initialize with n + 1 to represent an initially high number of rides
    vector<long long> capacity(totalMasks, 0);
    
    dp[0] = 0; // Base case: 0 people require 0 rides
    capacity[0] = x; // Initially, the elevator is empty, so full capacity is available
    
    for (int mask = 0; mask < totalMasks; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) { // If i-th person is not included in the current mask
                int newMask = mask | (1 << i);
                if (capacity[mask] >= weights[i]) {
                    // If the person can fit in the current ride
                    if (dp[mask] < dp[newMask] || (dp[mask] == dp[newMask] && capacity[newMask] < capacity[mask] - weights[i])) {
                        dp[newMask] = dp[mask];
                        capacity[newMask] = capacity[mask] - weights[i];
                    }
                } else {
                    // If the person cannot fit in the current ride, start a new ride
                    if (dp[mask] + 1 < dp[newMask] || (dp[mask] + 1 == dp[newMask] && x - weights[i] > capacity[newMask])) {
                        dp[newMask] = dp[mask] + 1;
                        capacity[newMask] = x - weights[i];
                    }
                }
            }
        }
    }
    
    cout << dp[totalMasks - 1] << endl;
    
    return 0;
}
