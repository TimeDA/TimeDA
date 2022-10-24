#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int test) {
    int n;
    cin >> n;
    vector < int > p(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total += p[i];
    }
    cout << "Case #" << test << ":";
    while (total > 0) {
        bool done = false;
        for (int i = 0; i < n && !done; ++i) {
            if (p[i] == 0) {
                continue;
            }
            --p[i];
            int value = *max_element(p.begin(), p.end());
            if (value * 2 <= total - 1) {
                done = true;
                --total;
                cout << " " << char('A' + i);
                break;
            }
            ++p[i];
        }
        for (int i = 0; i < n && !done; ++i) {
            for (int j = i + 1; j < n && !done; ++j) {
                if (p[i] == 0 || p[j] == 0) {
                    continue;
                }
                --p[i];
                --p[j];
                int value = *max_element(p.begin(), p.end());
                if (value * 2 <= total - 2) {
                    done = true;
                    total -= 2;
                    cout << " " << char('A' + i) << char('A' + j);
                    break;
                }
                ++p[i];
                ++p[j];
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    return 0;
}