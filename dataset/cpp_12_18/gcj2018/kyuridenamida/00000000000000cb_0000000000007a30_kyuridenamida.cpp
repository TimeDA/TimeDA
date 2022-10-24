#include <vector>
#include <iostream>
#include <map>

using namespace std;


void solve(int t) {
    map<pair<int, int>, int> memo;
    int a;
    cin >> a;
    for (int i = 2; i <= 8;) {
        cout << i << " " << 2 << endl;

        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
            break;
        memo[{x, y}] = true;
        bool ok = true;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                ok &= memo[{i + j, 2 + k}];
            }
        }
        if (ok) {
            i += 3;
        }
    }


}

void main_(istream &cin) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
}



