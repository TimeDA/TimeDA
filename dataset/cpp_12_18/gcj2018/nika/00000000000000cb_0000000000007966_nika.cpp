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

int i, j, k, m, n, l;


int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        printf("Case #%d: ", tt);                        
        int D; string P;
        cin >> D >> P;
        
        int ans = 0;
        while (1) {
            int damage = 1;
            int dealt = 0;
            F0(i, SZ(P)) {
                if (P[i] == 'S') dealt += damage; else damage *= 2;
            }
            if (dealt <= D) break;
            int found = 0;
            for (int i = SZ(P) - 1; i >= 1; i--) if (P[i] == 'S' && P[i - 1] == 'C') { found = 1; swap(P[i], P[i - 1]); break; }
            if (!found) { ans = -1; break; }
            ans++;
        }
        if (ans == -1) cout << "IMPOSSIBLE" << endl; else cout << ans << endl;
    }
    return 0;
}
