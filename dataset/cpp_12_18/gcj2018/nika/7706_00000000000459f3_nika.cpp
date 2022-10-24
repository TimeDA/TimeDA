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
#define CL(a,x) memset(x, a, sizeof(x))
#define P(x) cerr << #x << "=" << x << endl

const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;

const int K = 50;
const int N = 500;

char dp[K + 1][K + 1][N + 1][N + 1];

int main() {
    //freopen("x.in", "r", stdin);
    CL(-1, dp);
    dp[0][0][0][0] = 0;
    for (int a = 0; a < K; a++)
        for (int b = 0; b < K; b++)
             for (int A = 0; A <= N; A++)
                 for (int B = 0; B <= N; B++) if (dp[a][b][A][B] != -1) {
                     int na = a;
                     int nb = b + 1;
                     if (nb >= K) { na++; nb = 0; }
                     if (dp[na][nb][A][B] < dp[a][b][A][B]) dp[na][nb][A][B] = dp[a][b][A][B];
                     if (A + na <= N && B + nb <= N && dp[na][nb][A+na][B+nb] < dp[a][b][A][B]+1) {
                         dp[na][nb][A+na][B+nb] = dp[a][b][A][B] + 1;
                     }
                 }

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        int A, B;
        cin >> A >> B;
        char ans = 0;
        F0(a, K) F0(b, K) if (dp[a][b][A][B] != -1) {
            ans = max(ans, dp[a][b][A][B]);
        }

        printf("Case #%d: %d\n", tt, (int)ans);
    }
    return 0;
}
