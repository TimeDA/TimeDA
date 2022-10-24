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

int i, j, k, m, n, l, C;
int a[101], b[101];

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> C;
        F1(i, C) cin >> a[i];
        if (a[1] == 0 || a[C] == 0) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
        } else {
            vector<string> ans;
            ans.push_back(string(C, '.'));

            while (1) {
                int dest = 1;
                string s(C, '.');
                F1(i, C) b[i] = 0;
                F1(i, C) F0(j, a[i]) {
                    if (i < dest) {
                        b[i + 1]++;
                        s[i] = '/';
                    } else if (i > dest) {
                        b[i - 1]++;
                        s[i - 2] = '\\';
                    } else b[i]++;
                    dest++;
                }
                F1(i, C) a[i] = b[i];
                if (s == string(C, '.')) break;
                ans.push_back(s);
            }

            reverse(ans.begin(), ans.end());
            printf("Case #%d: %d\n", tt, SZ(ans));
            for (string s : ans) cout << s << endl;
        }
    }
    return 0;
}
