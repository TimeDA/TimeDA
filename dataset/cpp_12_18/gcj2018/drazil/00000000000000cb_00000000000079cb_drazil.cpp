#include <bits/stdc++.h>

using namespace std;

int arr[110000];
int a0[110000];
int a1[110000];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) scanf("%d", &a0[p0++]);
            else scanf("%d", &a1[p1++]);
        }
        sort(a0, a0 + p0);
        sort(a1, a1 + p1);
        p0 = p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) arr[i] = a0[p0++];
            else arr[i] = a1[p1++];
        }
        int err = -1;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                err = i - 1;
                break;
            }
        }
        if (err == -1) printf("Case #%d: OK\n", t);
        else printf("Case #%d: %d\n", t, err);
    }

    return 0;
}
