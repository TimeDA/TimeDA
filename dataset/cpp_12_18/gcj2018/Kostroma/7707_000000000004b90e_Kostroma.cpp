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

#define int li
//const int mod = 1000000007;

const ld eps = 1e-9;

bool eq(ld a, ld b) { return fabsl(a - b) < eps; }
bool ge(ld a, ld b) { return a - b > -eps; }
bool gt(ld a, ld b) { return a - b > eps; }
ld sqr(ld x) { return x * x; }

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int, int> pii;

#ifdef AIM
#define gassert assert
#else
void gassert(bool) {}
#endif

struct pt {
    ld x, y;

    pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
    ld operator*(const pt &p) const { return x * p.x + y * p.y; }
    ld operator%(const pt &p) const { return x * p.y - y * p.x; }

    pt operator*(const ld &a) const { return pt{x * a, y * a}; }
    pt operator/(const ld &a) const { gassert(!eq(a, 0)); return pt{x / a, y / a}; }
    void operator*=(const ld &a) { x *= a, y *= a; }
    void operator/=(const ld &a) { gassert(!eq(a, 0)); x /= a, y /= a; }

    bool operator<(const pt &p) const {
        if (eq(x, p.x)) return gt(p.y, y);
        return x < p.x;
    }

    bool operator==(const pt &p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator!=(const pt &p) const { return !(*this == p); }

    bool right() const { return pt{0, 0} < *this; }

    pt rot() { return pt{-y, x}; }
    ld abs() const { return hypotl(x, y); }
    ld abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

bool pointInsideSegment(pt p, pt a, pt b) {
    if (!eq((p - a) % (p - b), 0))
        return false;
    return ge(0, (a - p) * (b - p));
}

bool checkSegmentIntersection(pt a, pt b, pt c, pt d) {
    if (eq((a - b) % (c - d), 0)) {
        if (pointInsideSegment(a, c, d) ||
            pointInsideSegment(b, c, d) ||
            pointInsideSegment(c, a, b) ||
            pointInsideSegment(d, a, b)) {
            //intersection of parallel segments
            return true;
        }
        return false;
    }

    ld s1, s2;

    s1 = (c - a) % (b - a);
    s2 = (d - a) % (b - a);
    if (gt(s1, 0) && gt(s2, 0))
        return false;
    if (gt(0, s1) && gt(0, s2))
        return false;

    swap(a, c), swap(b, d);

    s1 = (c - a) % (b - a);
    s2 = (d - a) % (b - a);
    if (gt(s1, 0) && gt(s2, 0))
        return false;
    if (gt(0, s1) && gt(0, s2))
        return false;

    return true;
}

pair<bool, pt> segmentsIntersection(pt a, pt b, pt c, pt d) {
    if (!checkSegmentIntersection(a, b, c, d) ||
        eq(0, (b-a) % (c-d))) {
        return {false, {0,0}};
    }
    ld S = (b - a) % (d - c);
    ld s1 = (c - a) % (d - a);
    return {1, a + (b - a) / S * s1};
}

bool pointInsidePolygon(pt a, pt *p, int n) {
    double sumAng = 0;
    forn (i, n) {
        pt A = p[i], B = p[(i + 1) % n];
        if (pointInsideSegment(a, A, B))
            return true;
        sumAng += atan2((A - a) % (B - a), (A - a) * (B - a));
    }
    return fabs(sumAng) > 1;
}

const int maxn = 550;

// BEGIN_CODE
int m, n; // segs, points
pair<pt, pt> segs[maxn];
pt p[maxn], from, to;
map<pt, int> shr;
vi e[maxn]; // points adjacent to point

pt point_by_id[maxn];

int getPoint(pt x) {
    if (shr.count(x)) return shr[x];
    p[n] = x;
    point_by_id[n] = x;
    return shr[x] = n++;
}
// END_CODE
// BEGIN_CODE
// segIntersection: {bool, point}, true iff exactly one point
void genIntersections() {
    forn(i, m) {
        getPoint(segs[i].fi);
        getPoint(segs[i].se);
        forn(j, i) {
            auto t = segmentsIntersection(
                segs[i].fi, segs[i].se, segs[j].fi, segs[j].se);
            if (t.fi) getPoint(t.se);
        }
    }
    // END_CODE
    //cerr << m << " segments, " << n << " points" << endl;
    //forn(i, m) svg.line(segs[i].fi, segs[i].se);
//     forn(i, n) svg.point(p[i]);
    // BEGIN_CODE
}

void genGraph() {
    forn(i, m) {
        vi pts;
        forn(j, n) if (pointInsideSegment(
            p[j], segs[i].fi, segs[i].se)) {
            pts.push_back(j);
        }
        sort(all(pts), [](int i, int j) {
            return p[i] < p[j]; });
        forn(j, pts.size() - 1) {
            int u = pts[j], v = pts[j+1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    forn(i, n) {
        sort(all(e[i]), [i](int x, int y) {
            pt a = p[x] - p[i];
            pt b = p[y] - p[i];
            if (a.right() != b.right()) return a.right();
            return a % b > 0;
        });
    }
}

vector<pt> faces[maxn];
bool inner[maxn];
int nf;
map<pii, int> faceForEdge;
vector<pair<int, int>> ef[maxn]; // graph on faces

map<pair<pt, pt>, int> num_edge;

void genFaces() {
    forn(i, n) for (int to: e[i]) {
        if (faceForEdge.count({i, to})) continue;
        int f = nf++;
        int v = i, u = to;
        do {
            faces[f].push_back(p[v]);
            faceForEdge[{v, u}] = f;
            auto it = lower_bound(all(e[u]), v,
                                  [u] (int x, int y) {
                                      pt a = p[x] - p[u];
                                      pt b = p[y] - p[u];
                                      if (a.right()!=b.right()) return a.right();
                                      return a % b > 0;
                                  });
            assert(*it == v);
            if (it == e[u].begin()) it = e[u].end();
            v = u;
            u = *--it;
        } while (v != i || u != to);
    }
    forn(i, nf) {
        ld s = 0;
        forn(j, faces[i].size()) {
            s += faces[i][j] % faces[i][(j+1)%faces[i].size()];
        }
        inner[i] = gt(s, 0);
    }
    // END_CODE
    //cerr << nf << " faces" << endl;
    int nInner = accumulate(inner, inner + nf, 0);
    //cerr << nInner << " inner, " << nf - nInner << " outer\n";
    // BEGIN_CODE
    forn(v, n) for (int to: e[v]) {
        int f1 = faceForEdge[{v, to}];
        int f2 = faceForEdge[{to, v}];
        int cur_id = num_edge[{point_by_id[v], point_by_id[to]}];
        if (f1 != f2) {
            ef[f1].push_back({f2, cur_id});
            ef[f2].push_back({f1, cur_id});
            //cout << "edge: " << f1 << " " << f2 << " " << cur_id << "\n";
        }
    }
}
// END_CODE

int locate(pt p) {
    forn(i, nf) if (inner[i]) {
        if (pointInsidePolygon(
            p, faces[i].data(), faces[i].size())) {
            return i;
        }
    }
    return -1;
}

void clean_data() {
    n = 0;
    nf = 0;
    shr.clear();
    num_edge.clear();
    faceForEdge.clear();
    for (int i = 0; i < maxn; ++i) {
        e[i].clear();
        faces[i].clear();
        ef[i].clear();
    }
}

/*int q[maxn], d[maxn];

int bfs(int from, int to) {
    forn(i, nf) d[i] = -1;
    int lq = 0, rq = 0;
    if (from != -1) {
        q[rq++] = from;
        d[from] = 0;
    } else {
        forn(i, nf) if (!inner[i]) {
            q[rq++] = i;
            d[i] = 0;
        }
    }
    while (lq != rq) {
        int v = q[lq++];
        for (int to: ef[v]) if (d[to] == -1) {
                d[to] = d[v] + 1;
                q[rq++] = to;
            }
    }
    if (to != -1) {
        return d[to];
    } else {
        int res = maxn;
        forn(i, nf) if (!inner[i]) res = min(res, d[i]);
        return res;
    }
}*/

void kill_sol() {
    genIntersections();
    genGraph();
    genFaces();
    //svg.point(from, -1, "red");
    //svg.point(to, -1, "blue");
    //cout << bfs(locate(from), locate(to)) << endl;
}

vector<vector<pair<int, int>>> final_g;

vector<int> res;

void dfs_final(int v) {
    for (auto item : final_g[v]) {
        dfs_final(item.first);
        res.push_back(item.second);
    }
}

void solve(__attribute__((unused)) bool read) {
    clean_data();
    int n_fixed;
    cin >> m >> n_fixed;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> segs[i].fi >> segs[i].se;
        num_edge[make_pair(segs[i].fi, segs[i].se)] = i;
    }
    vector<int> fixed(n_fixed);
    for (int i = 0; i < n_fixed; ++i) {
        fixed[i] = i;
    }

    kill_sol();

    int outer_face = -1;
    for (int i = 0; i < nf; ++i) {
        if (!inner[i]) {
            outer_face = i;
            break;
        }
    }
    assert(outer_face != -1);

    vector<char> is_used(m, false);
    res.clear();
    for (int e_id : fixed) {
        is_used[e_id] = true;
        res.push_back(e_id);
    }

    /*for (int i = 0; i < nf; ++i) {
        cout << faces[i].size() << " points:\n";
        for (auto x : faces[i]) {
            cout << x.x << " " << x.y << "\n";
        }
    }*/

    vector<pair<int, int>> parent_face(nf, {-1, -1});
    parent_face[outer_face] = {outer_face, -1};
    queue<int> q;
    q.push(outer_face);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto item : ef[v]) {
            int to = item.first;
            int edge = item.second;
            if (is_used[edge]) {
                continue;
            }
            if (parent_face[to].first == -1) {
                q.push(to);
                parent_face[to] = {v, edge};
            }
        }
    }

    set<int> last_edges;
    for (int i = 0; i < nf; ++i) {
        last_edges.insert(parent_face[i].second);
    }
    for (int i = 0; i < m; ++i) {
        if (!is_used[i] && !last_edges.count(i)) {
            is_used[i] = true;
            res.push_back(i);
        }
    }
    final_g.clear();
    final_g.resize(nf);

    //cout << nf << "\n";

    for (int i = 0; i < nf; ++i) {
        int p = parent_face[i].first;
        if (i != outer_face) {
            final_g[p].push_back({i, parent_face[i].second});
            //cout << "edge " << p << " " << i << " " << parent_face[i].second << "\n";
        }
    }
    dfs_final(outer_face);

    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}