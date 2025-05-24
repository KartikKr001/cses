#include<bits/stdc++.h>
using namespace std;

vector<int> lps(string patt) {
    vector<int> ans(patt.size());
    ans[0] = 0;
    for(int i = 1; i < patt.size(); i++) {
        int j = ans[i - 1];

        while(j > 0 && patt[i] != patt[j]) {
            j = ans[j - 1];
        }

        if(patt[i] == patt[j]) {
            j++;
        }

        ans[i] = j;
    }
    return ans;
}

int string_match(string s, string p) {
    int ans = 0;
    vector<int> Lps_array = lps(p);
    int i = 0, j = 0;

    while(i < s.size()) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            if(j != 0) {
                j = Lps_array[j - 1];
            }
            else {
                i++;
            }
        }

        if(j == p.size()) {
            ans++;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    string pat;
    cin >> pat;
    cout << string_match(s, pat) << endl;

    return 0;
}
