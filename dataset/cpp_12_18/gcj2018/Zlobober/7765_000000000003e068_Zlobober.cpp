#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int readInt() {
    int t;
    scanf("%d", &t);
    if (t == -1) {
        exit(0);
    }
    return t;
}

void solve() {
    int n = readInt();
    vector<int> cnt(n, 0);
    vector<char> available(n, true);
    for (int i = 0; i < n; i++) {
        int k = readInt();
        if (k == -1) {
            exit(0);
        }
        vector<int> prefs;
        for (int j = 0; j < k; j++) {
            int t = readInt();
            cnt[t]++;
            prefs.push_back(t);
        }
        pair<int, int> pr(1000, -1);
        for (int p : prefs) {
            if (!available[p]) {
                continue;
            }
            pr = min(pr, make_pair(cnt[p], p));
        }
        printf("%d\n", pr.second);
        if (pr.second != -1) {
            available[pr.second] = false;
        }
        fflush(stdout);
    }
}

int main() {
    int T = readInt();
    for (int t = 0; t < T; t++) {
        solve();
    }
}
