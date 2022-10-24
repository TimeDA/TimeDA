#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    while (b - a > 1) {
        int m = (a + b) / 2;
        cout << m << endl;
        string res;
        cin >> res;
        if (res == "TOO_SMALL") {
            a = m;
        } else if (res == "TOO_BIG") {
            b = m;
        } else {
            return;
        }
    }
    cout << a << endl;
    string res;
    cin >> res;
    if (res == "CORRECT") {
        return;
    }
    cout << b << endl;
    cin >> res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}