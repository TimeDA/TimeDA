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

struct soln {
    int A;
    static const int MAXD = 205;
    bool planted[MAXD][MAXD];
    int H, W;
    bool done;
    soln() {
        FO (i,0,MAXD) FO (j,0,MAXD) planted[i][j] = false;
        done = false;
    }
    int getUnplanted(int r, int c) {
        int unp = 0;
        FO (dx,-1,1+1) {
            FO (dy,-1,1+1) {
                unp += !planted[r+dy][c+dx];
            }
        }
        return unp;
    }
    void plant(int r, int c) {
        printf ("%d %d\n", r, c);
        fflush (stdout);
        int pr, pc;
        scanf ("%d %d", &pr, &pc);
        planted[pr][pc] = true;
        if (!pr && !pc) done = true;
    }
    void solve() {
        scanf ("%d", &A);
        H = 3;
        W = A/H+1;
        while (W%3) W++;
        assert(W*H >= A);
        for (int y = 2;;y += 3) {
            y = min(y, H-1);
            for (int x = 2;;x += 3) {
                x = min(x, W-1);
                while (getUnplanted(y,x) > 0 && !done) {
                    plant(y,x);
                }
                if (x == W-1) break;
            }
            if (y == H-1) break;
        }
    }
};

int T;
int main() {
    scanf ("%d", &T);
    FO(_z,0,T) {
        soln s;
        s.solve();
    }
    return 0;
}
