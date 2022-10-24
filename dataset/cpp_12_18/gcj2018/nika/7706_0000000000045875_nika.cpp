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
#define P(x) cerr << #x << "=" << x << endl

const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
const int N = 101;
int a[N][N];
vector<int> adj[N];
int x[N], y[N], V[N];

int rec(int i) {
    V[i] = 1;
    for (int j : adj[i]) {
        if (y[j] == 0 || (V[y[j]] == 0 && rec(y[j]))) {
            x[i] = j;
            y[j] = i;
            return 1;
        }
    }
    return 0;
}

int solve(int color) {
    F1(i, n) adj[i].clear();
    F1(i, n) F1(j, n) if (a[i][j] == color) {
        adj[i].push_back(j);
    }
    int ret = 0;
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    F1(i, n) if (x[i] == 0) {
        F1(j, n) V[j] = 0;
        ret += rec(i);
    }
    return ret;
}


int main() {
   // freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> n;
        F1(i, n) F1(j, n) cin >> a[i][j];
        int ans = n * n;
        F1(i, n) ans -= solve(i);
        F1(i, n) ans -= solve(-i);

        printf("Case #%d: %d\n", tt, ans);                        
    }
    return 0;
}
