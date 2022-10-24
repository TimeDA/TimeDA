#include <bits/stdc++.h>

using namespace std;

typedef array<array<int, 4>, 4> Board;

int chk(Board B, int N) {
    for (int i = 0; i < N; i++) {
        set<int> v;
        for (int j = 0; j < N; j++) {
            v.insert(B[i][j]);
        }
        if (v.size() < N) return 0;
    }

    for (int i = 0; i < N; i++) {
        set<int> v;
        for (int j = 0; j < N; j++) {
            v.insert(B[j][i]);
        }
        if (v.size() < N) return 0;
    }
    return 1;

}

void solve(int cs) {
    int N;
    Board A;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    int ans = 1e9;
    for (int i = 0; i < (1 << (N * N)); i++) {
        Board B;
        int hoge = 114514;
        for (int j = 0; j < N * N; j++) {
            if (i >> j & 1) {
                B[j / N][j % N] = A[j / N][j % N];
            } else {
                B[j / N][j % N] = hoge++;
            }
        }

        if (chk(B, N)) {
            ans = min(ans, N * N - __builtin_popcount(i));
        }
    }
    cout << "Case #" << cs << ": " << ans << endl;

}

int main() {
    int T;
    cin >> T;
    int cs = 1;
    while (T--) {

        solve(cs++);
    }

}
