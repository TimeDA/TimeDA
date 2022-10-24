#include <cstdio>
#include <algorithm>

using namespace std;

int a[100010], b[100010], c[100010];

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        int n;
        scanf("%d", &n);
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++)
            if (i & 1) scanf("%d", &b[n2++]);
            else scanf("%d", &a[n1++]);
        sort(a, a + n1);
        sort(b, b + n2);
        n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++)
            c[i] = (i & 1) ? b[n2++] : a[n1++];

        int ans = -1;
        for (int i = 0; i + 1 < n; i++)
            if (c[i] > c[i+1]) {
                ans = i;
                break;
            }
        printf("Case #%d: ", t);
        if (ans == -1) printf("OK\n");
        else printf("%d\n", ans);
    }
    return 0;
}
