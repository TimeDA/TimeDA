#include <bits/stdc++.h>

#define INF 1000000010
#define INFLL ((1LL<<62)-5)
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
#define SZ(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

const int MAXS = 100005;
const int TOP_FIXED = 0;
const int BOT_FIXED = 0;
const int TOP_MINE = 0;
const int BOT_MINE = 0;

struct soln{
    int S;
    int a1[MAXS], a2[MAXS];
    int dp[MAXS][4];
    int othval[MAXS][4];
    void solve() {
        scanf("%d", &S);
        FO(i,0,S) {
            int d, a, b;
            scanf("%d %d %d", &d, &a, &b);
            a1[i] = d+a;
            a2[i] = d-b;
        }
        int ans = 0;
        FO(j,0,4) dp[0][j] = 1;
        FO(i,1,S) {
            // 0:
            if (a1[i-1] == a1[i]) {
                dp[i][0] = dp[i-1][0]+1;
            } else {
                dp[i][0] = 1;
            }
            // 1:
            if (a2[i-1] == a2[i]) {
                dp[i][1] = dp[i-1][1]+1;
            } else {
                dp[i][1] = 1;
            }
            // 2:
            if (a1[i-1] == a1[i]) {
                dp[i][2] = dp[i-1][2]+1;
                othval[i][2] = othval[i-1][2];
            } else {
                othval[i][2] = a2[i-1];
                if (othval[i-1][3] == a1[i]) {
                    dp[i][2] = dp[i-1][3]+1;
                } else {
                    dp[i][2] = dp[i-1][1]+1;
                }
            }
            // 3:
            if (a2[i-1] == a2[i]) {
                dp[i][3] = dp[i-1][3]+1;
                othval[i][3] = othval[i-1][3];
            } else {
                othval[i][3] = a1[i-1];
                if (othval[i-1][2] == a2[i]) {
                    dp[i][3] = dp[i-1][2]+1;
                } else {
                    dp[i][3] = dp[i-1][0]+1;
                }
            }
        }
        int numans = 0;
        FO(i,0,S) {
            int cmax = 0;
            FO(j,0,4) cmax = max(cmax, dp[i][j]);
            if (cmax > ans) {
                ans = cmax;
                numans = 0;
            }
            if (cmax == ans) numans++;
        }
        printf("%d %d\n", ans, numans);
    }
};

int T;

soln s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &T);
    FO (_z,0,T) {
        printf("Case #%d: ", _z+1);
        s.solve();
    }
    return 0;
}
