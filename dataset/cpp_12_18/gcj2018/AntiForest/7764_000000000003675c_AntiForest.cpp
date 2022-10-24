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

const int MAXM = 105;
const ll MAXSUM = 1e12;
struct soln{
    int M;
    int r1[MAXM], r2[MAXM];
    ll globalAm[MAXM];
    vector<int> outgoing[MAXM];

    void init() {
        FO(i,0,M) outgoing[i].clear();
    }

    bool canDo(ll c) {
        //fprintf(stderr,"canDo: %lld\n", c);
        FO(i,0,M) {
            //fprintf(stderr,"%lld ", globalAm[i]);
        }
        vector<ll> am;
        FO(i,0,M) am.push_back(globalAm[i]);
        am[0] -= c;
        // TODO: actually check this isn't stupid.
        while(true) {
            //fprintf(stderr,"things:\n");
            FO(i,0,M) {
                //fprintf(stderr,"%lld ", am[i]);
            }
            //fprintf(stderr,"\n");
            bool isPos = true;
            ll stsum = 0;
            FO(i,0,M) {
                if (am[i] < 0) isPos = false;
                stsum += am[i];
            }
            if (isPos) return true;
            if (stsum < 0) return false;
            vector<bool> seen;
            vector<int> deg;
            queue<int> myq;
            FO(i,0,M) {
                seen.push_back(false);
                deg.push_back(2);
            }
            FO(i,0,M) {
                if (am[i] > 0) {
                    myq.push(i);
                }
            }
            vector<int> ordering;
            while (!myq.empty()) {
                int c = myq.front();
                myq.pop();
                if (seen[c]) continue;
                seen[c] = true;
                ordering.push_back(c);
                for (int nxt : outgoing[c]) {
                    deg[nxt]--;
                    if (deg[nxt] == 0) myq.push(nxt);
                }
            }
            reverse(ordering.begin(), ordering.end());
            FO(i,0,M) {
                if (!seen[i] && am[i] < 0) return false;
            }
            for (int c : ordering) {
                if (am[c] < 0) {
                    if (am[c] < -MAXSUM) return false;
                    ll oldam = am[c];
                    am[c] = 0;
                    am[r1[c]] += oldam;
                    am[r2[c]] += oldam;
                }
            }
        }
    }

    void solve() {
        scanf("%d", &M);
        init();
        FO(i,0,M) {
            scanf("%d %d", &r1[i], &r2[i]);
            r1[i]--; r2[i]--;
            outgoing[r1[i]].push_back(i);
            outgoing[r2[i]].push_back(i);
        }
        FO(i,0,M) scanf("%lld", &globalAm[i]);
        ll lo = 0;
        ll hi = MAXSUM;
        ll bSoFar = 0;
        while(lo <= hi) {
            ll mid = (lo+hi)/2;
            if (canDo(mid)) {
                bSoFar = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        printf("%lld\n", bSoFar);
    }
};

int T;

int main() {
    scanf("%d", &T);
    FO (_z,0,T) {
        cout << "Case #" << _z+1 << ": ";
        soln s;
        s.solve();
    }
    return 0;
}
