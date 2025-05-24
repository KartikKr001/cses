#include <iostream>
#include <string>
#include <vector>

int booth(const std::string &s) {
    int n = s.length();
    std::string s2 = s + s;
    std::vector<int> f(2 * n, -1);
    int k = 0; // Least rotation of string found so far

    for (int j = 1; j < 2 * n; ++j) {
        char sj = s2[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s2[k + i + 1]) {
            if (sj < s2[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        if (sj != s2[k + i + 1]) {
            if (sj < s2[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main() {
    std::string s;
    std::cin >> s;
    int start = booth(s);
    std::cout << s.substr(start) + s.substr(0, start) << std::endl;
    return 0;
}
