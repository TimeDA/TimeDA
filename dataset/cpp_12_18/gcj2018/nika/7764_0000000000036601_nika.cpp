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
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

const int N = 200;
int i, j, k, m, n, l;
int a[100001], dp[N + 1][N + 1];

void upd(int& x, int y) {
    if (x == -1 || x > y) x = y;
}

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> n >> k;
        CL(0, a);
        int uns = n;
        F0(i, k) {
            cin >> a[i];
            uns -= a[i];
        }
        sort(a, a + k);
        reverse(a, a + k);

        CL(-1, dp);
        dp[0][0] = 0;
        int ans = 0;
        cerr << uns << endl;
        for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) if (dp[i][j] != -1) {
            if (i == N) {
                if (dp[i][j] <= uns) ans = max(ans, j);
            }
            else for (int x = 0; x <= 100; x++) {
                upd(dp[i + 1][j], dp[i][j]);
                int y = (n * (2 * x - 1) + 199) / 200;
              // cout << x << " " << y << endl;
                upd(dp[i + 1][j + x], dp[i][j] + max(0, y - a[i]));
            }
        }

        printf("Case #%d: %d\n", tt, ans);                        
    }
    return 0;
}
