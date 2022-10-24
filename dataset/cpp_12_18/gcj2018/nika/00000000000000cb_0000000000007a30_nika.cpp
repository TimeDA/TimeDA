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

int i, j, k, m, n, T;

int f[20][20];

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        cin >> T;
        int A = 1, B = 1;
        if (T == 10) { A = 4; B = 4; }
        if (T == 20) { A = 5; B = 4; }
        if (T == 200) { A = 15; B = 14; }
        
        CL(0, f);
        
        F0(it, 1000) {
            int best = 0;
            int qi = -1, qj = -1;
            for (int i = 2; i < A; i++) for (int j = 2; j < B; j++) {
                int cnt = 0;
                F0(dx, 3) F0(dy, 3) cnt += !f[i + dx - 1][j + dy - 1];
                if (cnt > best) {
                    best = cnt;
                    qi = i;
                    qj = j;
                } 
            }
            cout << qi << " " << qj << endl;
            cin >> qi >> qj;
            if (qi == 0 || qi == -1) break;
            f[qi][qj] = 1;
        }
    }
    return 0;
}