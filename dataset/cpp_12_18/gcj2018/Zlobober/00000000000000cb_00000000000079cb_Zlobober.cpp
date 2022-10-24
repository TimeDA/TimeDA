#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

int A[N];
int E[N], O[N];

void solve(int cs) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        ((i & 1) ? O : E)[i / 2] = A[i];
    }
    sort(E, E + (n + 1) / 2);
    sort(O, O + n / 2);
    for (int i = 0; i < n; i++) {
        A[i] = ((i & 1) ? O : E)[i / 2];
    }
    int res = -1;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            res = i;
            break;
        }
    }
    if (res == -1) {
        printf("Case #%d: OK\n", cs);
    } else {
        printf("Case #%d: %d\n", cs, res);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }

}
