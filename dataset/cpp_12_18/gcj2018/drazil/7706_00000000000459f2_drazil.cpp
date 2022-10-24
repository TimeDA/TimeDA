#include <bits/stdc++.h>

using namespace std;

int arr[110];
int to[110];
char s[110][110];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", arr + i);
        if (arr[0] == 0 || arr[n - 1] == 0) printf("Case #%d: IMPOSSIBLE\n", t);
        else {
            bool ok = true;
            int mr = 0;
            int pos = 0;
            for (int i = 0; i < n; ++i) {
                if (arr[i] != 0) {
                    int val = arr[i];
                    while (val--) {
                        to[pos++] = i;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                mr = max(mr, abs(i - to[i]));
            }
            for (int i = 0; i < mr; ++i) {
                for (int j = 0; j < n; ++j) s[i][j] = '.';
                s[i][n] = '\0';
            }
            
            for (int i = 0; i < n; ++i) {
                if (to[i] > i) {
                    for (int j = 0; j < to[i] - i; ++j) {
                        s[j][i + j] = '\\';
                    }
                }
                if (to[i] < i) {
                    for (int j = 0; j < i - to[i]; ++j) {
                        s[j][i - j] = '/';
                    }
                }
            }
            
            if (!ok) printf("Case #%d: IMPOSSIBLE\n", t);
            else {
                printf("Case #%d: %d\n", t, mr + 1);

                for (int i = 0; i < mr; ++i) puts(s[i]);
                for (int i = 0; i < n; ++i) putchar('.');
                putchar('\n');
            }
        }
    }
    
    return 0;
}
