#include <bits/stdc++.h>

using namespace std;

long long eval(char *s, int len) {
    long long out = 0;
    long long cur = 1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'C') cur *= 2;
        else out += cur;
    }
    return out;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int d;
        char s[110];
        scanf("%d%s", &d, s);
        int nc = 0, ns = 0;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'C') ++nc;
            else ++ns;
        }
        if (ns > d) {
            printf("Case #%d: IMPOSSIBLE\n", t);
        } else {
            int ans = 0;
            while (eval(s, len) > d) {
                ++ans;
                for (int i = len - 1; i > 0; --i) {
                    if (s[i] == 'S' && s[i - 1] == 'C') {
                        swap(s[i], s[i - 1]);
                        break;
                    }
                }
            }
            printf("Case #%d: %d\n", t, ans);
        }
    }

    return 0;
}
