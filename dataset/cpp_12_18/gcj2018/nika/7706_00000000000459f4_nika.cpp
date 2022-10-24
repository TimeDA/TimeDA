#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define P(x) cerr << #x << "=" << x << endl

const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, compcnt;
int a[21][21], v[21][21];
string s[21];

const int DX[]={-1,0,1,0};
const int DY[]={0,1,0,-1};

void dfs(int i, int j) {
    v[i][j] = 1;
    compcnt++;
    F0(k, 4) {
        int x = i + DX[k], y = j + DY[k];
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        if (a[x][y] && !v[x][y]) dfs(x, y);
    }
}

int solvebad() {
    /*
    int isw = 0, isb = 0;
    F0(i, m) F0(j, n) {
        if (s[i][j] == 'W') isw = 1;
        if (s[i][j] == 'B') isb = 1;
    }
    if (!isw || !isb) return m * n;
    */

    int ret = 0;
    F0(mask, (1 << (m * n))) {
        int cnt = 0;
        F0(i, m) F0(j, n) {
            v[i][j] = 0;
            if ((1<<(i*n+j))&mask) { a[i][j] = 1; cnt++; } else a[i][j] = 0;
        }
        if (cnt <= ret) continue;
        int comps = 0;
        F0(i, m) F0(j, n) if (a[i][j] && !v[i][j]) {
            comps++;
            dfs(i, j);
        }
        if (comps != 1) continue;

        bool foundMatch = false;
        F0(sa, m + 1) F0(sb, n + 1) {
            int failed = 0;
            string q = "????";
            F0(i, m) F0(j, n) if (a[i][j]) {
                int qu = 2 * (i >= sa) + (j >= sb);
                if (q[qu] == '?') q[qu] = s[i][j];
                else if (q[qu] != s[i][j]) { failed = 1; break; }
            }
            if (failed) continue;

            F0(i0, m + 1) F0(j0, n + 1) {
                if (q[0] != '?' && (i0 - 1 < 0 || j0 - 1 < 0 || s[i0 - 1][j0 - 1] != q[0])) continue;
                if (q[1] != '?' && (i0 - 1 < 0 || j0 >= n || s[i0 - 1][j0] != q[1])) continue;
                if (q[2] != '?' && (i0 >= m || j0 - 1 < 0 || s[i0][j0 - 1] != q[2])) continue;
                if (q[3] != '?' && (i0 >= m || j0 >= n || s[i0][j0] != q[3])) continue;

                foundMatch = true;
                break;
            }
            if (foundMatch) break;
        }

        if (!foundMatch) continue;

        ret = cnt;
    }
    return ret;
}

int solvegood() {
    set<string> qs;
    F0(i0, m + 1) F0(j0, n + 1) {
        string q = "????";
        if (i0 - 1 >= 0 && j0 - 1 >= 0) q[0] = s[i0 - 1][j0 - 1];
        if (i0 - 1 >= 0 && j0 < n) q[1] = s[i0 - 1][j0];
        if (i0 < m && j0 - 1 >= 0) q[2] = s[i0][j0 - 1];
        if (i0 < m && j0 < n) q[3] = s[i0][j0];
        qs.insert(q);
    }

    int ret = 0;
    for (string q : qs) {
        F0(sa, m + 1) F0(sb, n + 1) {
            F0(i, m) F0(j, n) a[i][j] = v[i][j] = 0;
            F0(i, m) F0(j, n) {
                int qu = 2 * (i >= sa) + (j >= sb);
                if (s[i][j] == q[qu]) a[i][j] = 1;
            }
            F0(i, m) F0(j, n) if (a[i][j] && !v[i][j]) {
                compcnt = 0;
                dfs(i, j);
                ret = max(ret, compcnt);
            }
        }
    }
    return ret;
}

void stress() {
    while (1) {
        m = rand() % 4 + 1;
        n = rand() % 4 + 1;
        F0(i, m) {
            s[i].assign(n, 'W');
            F0(j, n) if (rand()%2) s[i][j] = 'B';
        }
        int ans1 = solvebad();
        int ans2 = solvegood();
        cerr << ans1 << "=" << ans2 << " ";
        if (ans1 != ans2) exit(0);
    }
}

int main() {
   // stress();
   // freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> m >> n;
        F0(i, m) cin >> s[i];

        int ans = solvegood();
        printf("Case #%d: %d\n", tt, ans);                        
    }
    return 0;
}
