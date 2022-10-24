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

const int MAXR = 22;
const int NONE = 0;
const int BLACK = 1;
const int WHITE = 2;

const int dy4[4] = {-1,0,1,0};
const int dx4[4] = {0,1,0,-1};

struct soln {
    int R, C;
    char gr[MAXR][MAXR];
    bool tem[MAXR][MAXR];
    bool seen[MAXR][MAXR];
    soln() {
        FO (i,0,MAXR) FO(j,0,MAXR) gr[i][j] = 0;
    }
    int dfs(int r, int c) {
        if (!tem[r][c]) return 0;
        seen[r][c] = true;
        int ret = 1;
        FO (i,0,4) {
            int ny = r+dy4[i];
            int nx = c+dx4[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (seen[ny][nx]) continue;
            ret += dfs(ny, nx);
        }
        return ret;
    }

    int findLargestCC() {
        FO(i,0,R) FO(j,0,C) seen[i][j] = false;
        int ans = 0;
        FO(i,0,R) FO(j,0,C) ans = max(ans, dfs(i,j));
        return ans;
    }

    void solve() {
        scanf("%d %d", &R, &C);
        FO(i,0,R) {
            FO(j,0,C) {
                scanf(" %c", &gr[i][j]);
                if (gr[i][j] == 'B') gr[i][j] = BLACK;
                else gr[i][j] = WHITE;
            }
        }
        int ans = 0;
        FO(bm,0,3*3*3*3) {
            int typ[2][2];
            typ[0][0] = bm%3;
            typ[0][1] = (bm/3)%3;
            typ[1][0] = (bm/3/3)%3;
            typ[1][1] = (bm/3/3/3)%3;
            if (typ[0][0] == NONE && typ[0][1] == NONE) continue;
            if (typ[0][0] == NONE && typ[1][0] == NONE) continue;
            // disconnecteds:
            if (typ[0][0] == NONE && typ[1][1] == NONE) continue;
            // yolo hope that was enough pruning.
            bool found = false;
            FO (y,0,R) {
                FO (x,0,C) {
                    bool isgood = true;
                    FO (dy,0,2) {
                        FO (dx,0,2) {
                            if (typ[dy][dx] == NONE) continue;
                            if (typ[dy][dx] != gr[y+dy][x+dx]) isgood = false;
                        }
                    }
                    if (isgood) found = true;
                }
            }
            if (!found) continue;
            //printf ("good: typ:\n%d%d\n%d%d\n", typ[0][0], typ[0][1], typ[1][0], typ[1][1]);

            // try all splits. Split everything < given value.
            FO (spy,0,R+1) {
                FO (spx,0,C+1) {
                    FO (y,0,R+1) {
                        FO (x,0,C+1) {
                            int quady = y < spy ? 0 : 1;
                            int quadx = x < spx ? 0 : 1;
                            bool isgood = typ[quady][quadx] != NONE && typ[quady][quadx] == gr[y][x];
                            tem[y][x] = isgood;
                        }
                    }
                    int cans = findLargestCC();
                    if (cans == 9) {
                        //printf ("wtf: typ:\n %d%d\n%d%d spy: %d spx: %d\n", typ[0][0], typ[0][1], typ[1][0], typ[1][1], spy, spx);
                    }
                    ans = max(ans, cans);
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
    scanf("%d", &T);
    FO (_z,0,T) {
        printf("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
