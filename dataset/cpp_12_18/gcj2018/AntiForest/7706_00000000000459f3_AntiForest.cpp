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

const int MAXR = 502;
const int MAXN = 115;
// upto, used r, pairs done -> min b
int dp[MAXR][MAXR][MAXN];
void precomp() {
    FO(i,0,MAXR) FO(j,0,MAXR) FO(k,0,MAXN) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    FO (i,0,MAXR-1) {
        FO (j,0,MAXR) {
            FO (k,0,MAXN) {
                if (dp[i][j][k] < 0) continue;
                //if (i < 3 && j < 3 && k < 3) printf("%d %d %d: %d\n", i, j, k, dp[i][j][k]);
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                int newam = dp[i][j][k];
                int newr = j;
                int newdone = k;
                FO (t,1,MAXN) {
                    newr += i;
                    if (i == 0) {
                        newam += t;
                    } else {
                        newam += t-1;
                    }
                    newdone++;
                    if (newr >= MAXR || newam >= MAXR) break;
                    dp[i+1][newr][newdone] = min(dp[i+1][newr][newdone], newam);
                }
            }
        }
    }
}

struct soln {
    void countam() {
        int c = 1;
        int am = 0;
        int cc = 0;
        int sum = 0;
        while (sum <= 1000) {
            am++;
            sum += c;
            cc++;
            if (cc == c+1) {
                c += 1;
                cc = 0;
            }
        }
        printf("%d\n", am-1);
    }
    void solve() {
        int R, B;
        scanf("%d %d", &R, &B);
        int ans = 0;
        FO(i,0,MAXR) {
            FO(j,0,MAXR) {
                FO (k,0,MAXN) {
                    if (j <= R && dp[i][j][k] <= B) ans = max(ans, k);
                }
            }
        }
        printf("%d\n", ans);
    }
};

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precomp();

    scanf("%d", &T);
    FO (_z,0,T) {
        printf("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
