#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int pc(int a, int b) {
    int z = a * 1000 / b;
    return z / 10 + (z % 10 >= 5);
}

pair<int, int> next(int cur, int n) {
    int c = pc(cur, n);
    c++;
    // k / n * 100 >= c
    // k >= c / 100 * n
    // k >= c * n / 100
    int nval = (c * n + 99) / 100;
    // printf("%d %d : %d %d\n", cur, n, c, pc(
    return {nval - cur, c - 1 - pc(nval, n)};
}

map<pair<int, int>, int> mm;

int get(const vector<int>& a, int n, size_t i, int left) {
    pair<int, int> key{i, left};
    if (mm.count(key)) return mm[key];
    int res = 0;

    if (i >= a.size()) {
        for (int j = 1; j <= left; j++) {
            int cur = pc(j, n) + get(a, n, i, left - j);
            if (cur > res) res = cur;
        }
    } else {
        for (int j = 0; j <= left; j++) {
            int cur = pc(a[i] + j, n) + get(a, n, i + 1, left - j);
            if (cur > res) res = cur;
        }
    }

    mm[key] = res;
    return res;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(k);
    int left = n;
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        left -= a[i];
    }

    mm.clear();
    printf("%d\n", get(a, n, 0, left));
}

int main() {
    //printf("%d\n", pc(1, 3));
    //printf("%d\n", pc(2, 3));
    //printf("%d %d\n", next(1, 3).first, next(1, 3).second);
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
