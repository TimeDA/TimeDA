#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


char buf[1000];

int n;

typedef long long llong;

llong power() {
    llong res = 0;
    llong cur = 1;
    for (int i = 0; i < n; i++) {
        if (buf[i] == 'C') {
            cur <<= 1;
        } else {
            res += cur;
        }
    }
    return res;
}

bool hack() {
    for (int i = n - 1; i >= 1; i--) {
        if (buf[i - 1] == 'C' && buf[i] == 'S') {
            swap(buf[i], buf[i - 1]);
            return true;
        }
    }
    return false;
}

void solve(int cs) {
    int d;
    scanf("%d", &d);
    scanf("%s", buf);
    n = strlen(buf);
    int ans = 0;
    while (power() > d) {
        if (!hack()) {
            ans = -1;
            break;
        }
        ans++;
    }
    if (ans != -1) {
        printf("Case #%d: %d\n", cs, ans);
    } else {
        printf("Case #%d: IMPOSSIBLE\n", cs);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
