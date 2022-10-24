#include <vector>
#include <iostream>

using namespace std;

long long damage(string s) {
    long long cur = 1, ans = 0;
    for (auto c : s)
        if (c == 'C') cur *= 2;
        else ans += cur;
    return ans;
}

void solve(int t) {
    int a;
    string b;
    cin >> a >> b;
    int cnt = 0;
    while (damage(b) > a) {
        int idx = b.find("CS");
        if (idx == -1) {
            cnt = -1;
            break;
        }
        swap(b[idx], b[idx + 1]);
        cnt++;
    }
    cout << "Case #" << t << ": ";
    if (cnt == -1) cout << "IMPOSSIBLE" << endl;
    else cout << cnt << endl;
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



