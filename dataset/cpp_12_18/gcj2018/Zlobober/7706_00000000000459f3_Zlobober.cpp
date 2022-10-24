#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int N = 505;
const int M = 33;

int D[M][N][N];
const int inf = 1e4;

map<pair<int, int>, int> cache;

void solve(int cs) {
    int R, B;
    scanf("%d %d", &R, &B);
    int ans = -1;
    if (cache.count(make_pair(R, B))) {
        ans = cache[make_pair(R, B)];
    }
    if (ans == -1) {
        for (int i = 0; i < M; i++) {
            for (int r = 0; r < N; r++) {
                for (int b = 0; b < N; b++) {
                    D[i][r][b] = -inf;
                }
            }
        }
        D[0][R][B] = 0;
        for (int i = 0; i < M - 1; i++) {
            for (int r = 0; r < N; r++) {
                for (int b = 0; b < N; b++) {
                    if (D[i][r][b] < 0) {
                        continue;
                    }
                    for (int j = 0; j < M; j++) {
                        int nr = r - j * i;
                        int nb = b - j * (j - 1) / 2;
                        if (nr < 0 || nb < 0) {
                            break;
                        }
                        D[i + 1][nr][nb] = max<int>(D[i + 1][nr][nb], D[i][r][b] + j);
                    }
                }
            }
        }
        ans = 0;
        for (int i = 0; i < M; i++) {
            for (int r = 0; r <= R; r++) {
                for (int b = 0; b <= B; b++) {
                    ans = max<int>(ans, D[i][r][b]);
                }
            }
        }
        --ans;
    }
    cache[make_pair(R, B)] = ans;
    printf("Case #%d: %d\n", cs, ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
