#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
    cin >> t;
    int testNum = 1;
    while (t--) {
        cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

struct Point {
    double x, y, z;
    Point() {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

const double EPS = 1e-9;

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 100;
    return 1;
}

vector<vector<double>> data;
vector<double> ans;

bool is_bad(Point cur, Point a, Point b, Point c) {
    data.resize(3);
    data[0] = {a.x, b.x, c.x, cur.x};
    data[1] = {a.y, b.y, c.y, cur.y};
    data[2] = {1, 1, 1, 1};
    gauss(data, ans);
    double val = ans[0] * a.z + ans[1] * b.z + ans[2] * c.z;
    //cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    return val < cur.z;
}

bool is_good(vector<Point> points) {
    for (int i = 1; i + 3 <= points.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (is_bad(points[j], points[i], points[i + 1], points[i + 2])) {
                return false;
            }
        }
    }
    return true;
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    do {
        vector<Point> cur_points(n);
        for (int i = 0; i < n; ++i) {
            cur_points[i] = points[perm[i]];
        }
        if (is_good(cur_points)) {
            for (int i = 0; i < n; ++i) {
                cout << perm[i] + 1 << " \n"[i + 1 == n];
            }
            return;
        }
    }
    while (next_permutation(all(perm)));

    assert(false);

}