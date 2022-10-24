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

struct point3D {
    ll x, y, z;
    point3D() : x(0), y(0), z(0) {}
    point3D(ll x, ll y, ll z) : x(x), y(y), z(z) {}
    void read() {
        cin >> x >> y >> z;
    }
};

point3D operator + (point3D A, point3D B) {
    return point3D(A.x+B.x, A.y+B.y, A.z+B.z);
}
point3D operator - (point3D A, point3D B) {
    return point3D(A.x-B.x, A.y-B.y, A.z-B.z);
}
point3D operator ^ (point3D A, point3D B) {
    return point3D(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

struct plane {
    ll A, B, C, D;
    plane() {}
    plane(point3D X, point3D Y, point3D Z) {
        point3D q = (Y-X)^(Z-X);
        A = q.x; B = q.y; C = q.z;

        if (C < 0) {
            A = -A;
            B = -B;
            C = -C;
        }
        D = - (A*X.x + B*X.y + C*X.z);
    }
    ll eval(point3D p) {
        return A*p.x + B*p.y + C*p.z + D;
    }
};

point3D p[1001];
int id[1001];

int cc(int x, int y) {
    return p[x].z < p[y].z;
}

int ok() {
    for (int i = 2; i < n; i++) {
        plane pl(p[id[i - 2]], p[id[i - 1]], p[id[i]]);
        if (pl.C == 0) return 0;

        F0(j, i - 2) {
            point3D& d = p[id[j]];
            //double h = 1.0 * (-pl.D - pl.A * d.x - pl.B * d.y) / pl.C;
            //if (h <= d.z) return 0;

            //cerr << h << " " << d.z << endl;
            if (pl.eval(p[id[j]]) >= 0) return 0;
        }
    }
    return 1;
}

void slowsol() {
    do {
        if (ok()) {
            F0(i, n) cout << " " << id[i] + 1;
            return;
        }
    } while (next_permutation(id, id + n));
}

void fastsol() {
    sort(id, id + n, cc);
    if (ok()) {
        F0(i, n) cout << " " << id[i] + 1;
    }
}

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        printf("Case #%d:", tt);
        cin >> n;
        F0(i, n) p[i].read();

        F0(i, n) id[i] = i;

        if (n <= 10) slowsol();
        else fastsol();

        cout << endl;

    }
    return 0;
}
