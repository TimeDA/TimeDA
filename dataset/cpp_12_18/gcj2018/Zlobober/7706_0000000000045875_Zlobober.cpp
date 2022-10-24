#include <cstdio>
#include <vector>
using namespace std;

const int N = 105;
vector<pair<int, int>> byval[2 * N];

vector<int> E[N];
int to[N];

int n;

int curver = 0;
int used[N];

int DFS(int x) {
    used[x] = curver;
    for (int y : E[x]) {
        if (to[y] == -1 || (used[to[y]] != curver && DFS(to[y]))) {
            to[y] = x;
            return 1;
        }
    }
    return 0;
}

int kuhn(vector<pair<int, int>> edges) {
    for (int i = 0; i < n; i++) {
        E[i].clear();
        to[i] = -1;
    }
    for (const auto& pr : edges) {
        E[pr.first].push_back(pr.second);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        curver++;
        ans += DFS(i);
    }
    return ans;
}

void solve(int cs) {
    scanf("%d", &n);
    for (int i = 0; i <= 2 * n; i++) {
        byval[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            byval[x + n].emplace_back(i, j);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++) {
        ans += kuhn(byval[i]);
    }
    printf("Case #%d: %d\n", cs, n * n - ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
