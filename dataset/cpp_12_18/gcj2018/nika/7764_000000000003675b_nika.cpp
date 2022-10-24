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
const int inf = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[100001], b[100001], d[100001], n1[100001], n2[100001], nx1[100001], nx2[100001];

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> n;
        F0(i, n) {
            scanf("%d%d%d", &d[i], &a[i], &b[i]);
            n1[i] = d[i] - b[i];
            n2[i] = d[i] + a[i];
        }
        int ans = 0, ans2 = 0;

        for (int i = n; i >= 0; i--) {
            if (i >= n-1) { nx1[i] = nx2[i] = n; } else {
                if (n1[i] == n1[i + 1]) nx1[i]=nx1[i+1]; else nx1[i]=i+1;
                if (n2[i] == n2[i + 1]) nx2[i]=nx2[i+1]; else nx2[i]=i+1;
            }
        }

        F0(i, n) {
            if (n - i < ans) break;

            int b = 0;
            int num1 = inf;
            int num2 = inf;


            {
                num1 = n1[i];
                int j = nx1[i];
                num2 = n2[j];
                for ( ; j < n; j++) {
                    if (n1[j] != num1 && n2[j] != num2) break;
                }
                b = max(b, j - i);
            }
            {
                num2 = n2[i];
                int j = nx2[i];
                num1 = n1[j];
                for ( ; j < n; j++) {
                    if (n1[j] != num1 && n2[j] != num2) break;
                }
                b = max(b, j - i);
            }

           //cout << i << " " << b << endl;
            if (b > ans) { ans = b; ans2 = 1; }
            else if (b == ans) ans2++;
        }
        printf("Case #%d: %d %d\n", tt, ans, ans2);
    }
    return 0;
}
