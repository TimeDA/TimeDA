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

const int MAXC = 105;

struct soln {
    int C;
    vector<int> poses;
    int fin[MAXC];
    char gr[MAXC][MAXC];
    void solve() {
        scanf("%d", &C);
        FO(i,0,C) {
            scanf("%d", &fin[i]);
            FO(j,0,fin[i]) poses.push_back(i);
        }
        if (!fin[0] || !fin[C-1]) {
            printf("IMPOSSIBLE\n");
            return;
        }
        int H = 0;
        FO(i,0,C) {
            H = max(H, abs(i-poses[i]));
        }
        H++;
        printf("%d\n", H);
        FO (i,0,MAXC) FO(j,0,MAXC) gr[i][j] = '.';
        FO(i,0,C) {
            int delt = poses[i]-i;
            if (!delt) continue;
            int absdelt = abs(delt);
            int cH = H-1-absdelt;
            int dir = (delt > 0) ? 1 : -1;
            int cx = i;
            while (cx != poses[i]) {
                gr[cH][cx] = delt > 0 ? '\\' : '/';
                cx += dir;
                cH++;
            }
        }
        FO (i,0,H) {
            FO (x,0,C) {
                printf("%c", gr[i][x]);
            }
            printf("\n");
        }
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
