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

struct soln{
    ll D;
    string s;
    ll score() {
        ll ret = 0;
        ll cpow = 1;
        for (char c : s) {
            if (c == 'C') cpow *= 2;
            else ret += cpow;
        }
        return ret;
    }
    void solve() {
        cin >> D >> s;
        int ans = 0;
        while (score() > D) {
            bool haveMove = false;
            for (int i = s.length()-2; i >= 0; i--) {
                if (s[i] == 'C' && s[i+1] == 'S') {
                    ans++;
                    swap(s[i], s[i+1]);
                    haveMove = true;
                    break;
                }
            }
            if (!haveMove) {
                break;
            }
        }
        if (score() > D) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
    }
};

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    FO (_z,0,T) {
        cout << "Case #" << _z+1 << ": ";
        soln s;
        s.solve();
    }
    return 0;
}
