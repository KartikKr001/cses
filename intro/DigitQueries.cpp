#define ll long long 
#include<bits/stdc++.h>
using namespace std;
char getKth(long long k) {
    long long digitLength = 1;  // Start with single-digit numbers
    long long count = 9;        // 9 numbers with single digit (1-9)
    long long start = 1;        // The starting number of the current digit length
    
    // Step 1: Determine the range where k falls
    while (k > digitLength * count) {
        k -= digitLength * count;
        digitLength++;
        count *= 10;  // Move to the next range: 10-99, 100-999, etc.
        start *= 10;  // Starting number of the next digit length
    }
    
    // Step 2: Determine the exact number and the digit within it
    // k-1 -> 1 based indexing
    long long num = start + (k-1)/ digitLength;  // Find the number
    string numStr = to_string(num);  // Convert the number to string
    return numStr[(k - 1) % digitLength];  // Find the exact digit
}
int main(){
    int k;
    cin>>k;
    while(k--){
        long long position;
        cin>>position; 
        cout<<getKth(position)<<endl;
    }
    return 0;
}