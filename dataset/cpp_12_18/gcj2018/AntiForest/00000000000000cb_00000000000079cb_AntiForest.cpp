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

    int N;
    vector<int> vals[2];
    void solve() {
        scanf ("%d", &N);
        FO (i,0,N) {
            int a;
            scanf ("%d", &a);
            vals[i%2].push_back(a);
        }
        FO (par,0,2) sort(vals[par].begin(), vals[par].end());
        vector<int> zipped;
        FO (i,0,N) {
            zipped.push_back(vals[i%2][i/2]);
        }
        FO (i,0,N-1) {
            if (zipped[i] > zipped[i+1]) {
                printf ("%d\n", i);
                return;
            }
        }
        printf ("OK\n");
        return;
    }
};

int T;

int main() {
    scanf("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
