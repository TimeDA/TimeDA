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

const ll inf = 1e18;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

const int N = 100000;
int i, j, k, m, n, l, r, c;
int x[N], y[N];

int solve() {
}

int main() {
    //freopen("x.in", "r", stdin);


    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> n;
        F0(i, n) cin >> x[i] >> y[i];
        printf("Case #%d: ", tt);

        int dx = *max_element(x, x + n) - *min_element(x, x + n);
        int dy = *max_element(y, y + n) - *min_element(y, y + n);
        cout << (max(dx, dy) + 1) / 2 << endl;

    }
    return 0;
}
