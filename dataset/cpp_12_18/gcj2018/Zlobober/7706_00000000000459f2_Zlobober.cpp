#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 105;

int A[N];
int L[N], R[N];
char F[N][N];

void solve(int cs) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    if (A[0] == 0 || A[n - 1] == 0) {
        printf("Case #%d: IMPOSSIBLE\n", cs);
        return;
    }
    int pt = 0;
    for (int i = 0; i < n; i++) {
        L[i] = pt;
        R[i] = pt + A[i] - 1;
        pt += A[i];
    }
    assert(pt == n);
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n; j++) {
            F[i][j] = '.';
        }
        F[i][n] = '\n';
        F[i][n + 1] = 0;
    }
    int mn = n;
    for (int i = 0; i < n; i++) {
        if (L[i] == R[i] + 1) {
            continue;
        }
        for (int j = i + 1; j <= R[i]; j++) {
            F[n - 1 - (j - (i + 1))][j] = '/';
            mn = min(mn, n - 1 - (j - (i + 1)));
        }
        for (int j = i - 1; j >= L[i]; j--) {
            F[n - 1 - ((i - 1) - j)][j] = '\\';
            mn = min(mn, n - 1 - ((i - 1) - j));
        }
    }
    printf("Case #%d: %d\n", cs, n + 1 - mn);
    for (int i = mn; i < n + 1; i++) {
        printf("%s", F[i]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
