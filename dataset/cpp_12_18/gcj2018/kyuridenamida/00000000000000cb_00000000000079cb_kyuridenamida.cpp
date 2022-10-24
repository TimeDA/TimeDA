#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long damage(string s) {
    long long cur = 1, ans = 0;
    for (auto c : s)
        if (c == 'C') cur *= 2;
        else ans += cur;
    return ans;
}

void solve(int t) {
    int n;
    cin >> n;
    vector<int> lst[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lst[i % 2].push_back(x);
    }
    for (int i = 0; i < 2; i++)
        sort(lst[i].begin(), lst[i].end());
    vector<int> fin(n);
    int id[2] = {};
    for (int i = 0; i < n; i++) {
        int x;
        if (i % 2 == 0) {
            x = lst[0][id[0]++];
        } else {
            x = lst[1][id[1]++];
        }
        fin[i] = x;
    }
    cout << "Case #" << t << ": ";
    if (is_sorted(fin.begin(), fin.end())) {
        cout << "OK" << endl;
    } else {
        for (int i = 0; i + 1 < fin.size(); i++) {
            if (fin[i] > fin[i + 1]) {
                cout << i << endl;
                break;
            }
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



