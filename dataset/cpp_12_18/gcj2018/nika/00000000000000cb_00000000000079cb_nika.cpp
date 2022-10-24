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
        cin >> n;
        vector<vector<int> > v(2);
        F0(i, n) {
            cin >> j;
            v[i % 2].push_back(j);
        }
        F0(i, 2) sort(v[i].begin(), v[i].end());
        vector<int> w;
        F0(i, n / 2) {
            w.push_back(v[0][i]);
            w.push_back(v[1][i]);
        }
        if (n & 1) w.push_back(v[0][n / 2]);
        F0(i, n) {
            if (i == n - 1) cout << "OK" << endl;
            else if (w[i] > w[i + 1]) { cout << i << endl; break; }
        }
    }
    return 0;
}