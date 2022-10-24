#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char buf[100];

typedef long long llong;
vector<string> W;
vector<vector<char>> diff;
string cur;

bool go(int i, int l) {
    if (i == l) {
        return !binary_search(W.begin(), W.end(), cur);
    }
    for (int c : diff[i]) {
        cur += c;
        if (go(i + 1, l)) {
            return true;
        }
        cur.pop_back();
    }
    return false;
}

void solve(int cs) {
    int n, l;
    scanf("%d %d", &n, &l);
    W.clear();
    diff.assign(l, {});
    cur.clear();
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        W.push_back(buf);
        for (int j = 0; j < l; j++) {
            diff[j].push_back(buf[j]);
        }
    }
    sort(W.begin(), W.end());
    W.resize(unique(W.begin(), W.end()) - W.begin());
    for (int j = 0; j < l; j++) {
        sort(diff[j].begin(), diff[j].end());
        diff[j].resize(unique(diff[j].begin(), diff[j].end()) - diff[j].begin());
    }
    if (go(0, l)) {
        printf("Case #%d: %s\n", cs, cur.data());
    } else {
        printf("Case #%d: -\n", cs);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
