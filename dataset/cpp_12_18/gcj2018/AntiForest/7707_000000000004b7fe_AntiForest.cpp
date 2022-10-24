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
    void solve() {
        int N;
        scanf ("%d", &N);
        ll minx = INF;
        ll maxx = -INF;
        ll miny = INF;
        ll maxy = -INF;
        FO (i,0,N) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
        }
        ll maxdiff = max(maxx-minx, maxy-miny);
        printf("%lld\n", maxdiff/2 + maxdiff%2);
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
