#include <cstdio>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

struct vt3 {
    llong x, y, z;
    vt3(llong _x, llong _y, llong _z) {
        x = _x, y = _y, z = _z;
    }
    friend bool operator <(vt3 a, vt3 b) {
        return a.id < b.id;
    }
    friend vt3 operator -(vt3 a, vt3 b) {
        return vt3(a.x - b.x, a.y - b.y, a.z - b.z);
    }
    int id = -1;
};

llong det2d(vt3 a, vt3 b, vt3 c) {
    llong x1 = b.x - a.x, y1 = b.y - a.y;
    llong x2 = c.x - a.x, y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}

llong det(vt3 a, vt3 b, vt3 c) {
    return a.x * b.y * c.z + a.y * b.z * c.x + a.z * b.x * c.y - a.z * b.y * c.x - a.x * b.z * c.y - a.y * b.x * c.z;
}

llong det(vt3 a, vt3 b, vt3 c, vt3 d) {
    if (det2d(a, b, c) < 0) {
        swap(b, c);
    }
    return det(d - a, d - b, d - c);
}

bool check(vector<vt3> P) {
    for (int i = 2; i < (int)P.size(); i++) {
        vt3 a = P[i], b = P[i - 1], c = P[i - 2];
        for (int j = 0; j < i - 2; j++) {
            vt3 d = P[j];
            llong dt = det(a, b, c, d);
            if (dt > 0) {
                return false;
            }
        }
    }
    return true;
}

void solve(int cs) {
    int n;
    scanf("%d", &n);
    vector<vt3> P;
    for (int i = 0; i < n; i++) {
        llong x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        P.emplace_back(vt3{x, y, z});
        P.back().id = i;
    }
    sort(P.begin(), P.end());
    do {
        if (check(P)) {
            printf("Case #%d:", cs);
            for (int i = 0; i < (int)P.size(); i++) {
                printf(" %d", (int)P[i].id + 1);
            }
            printf("\n");
            return;
        }
    } while (next_permutation(P.begin(), P.end()));
    assert(false);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
