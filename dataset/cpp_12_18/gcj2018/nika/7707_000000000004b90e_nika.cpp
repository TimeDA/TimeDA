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
vector<int> ans;
map<pii, int> M;
int p[10001], par[10001];
vector<int> adj[601];
int dist[601][601];

int getid(pii p) {
    if (M.count(p)) return M[p];
    ++m;
    M[p] = m;
    return m;
}

struct seg {
    int id;
    int added;
    int u, v;
    pii p1;
    pii p2;
    void read() {
        added = 0;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        u = getid(p1);
        v = getid(p2);
        //cerr << "read " << u << " " << v  << endl;
    }

    int distance() {
        if (dist[u][v] != dist[v][u]) throw 12;
        return dist[u][v];
    }


    void addtree() {
        int x = u; while (p[x] != x) x = p[x];
        int y = v; while (p[y] != y) y = p[y];
        if (x == y) return;

        adj[u].push_back(v);
        adj[v].push_back(u);

        added = 1;
        ans.push_back(id);
        if (rand()&1) swap(x, y);
        p[x] = y;
    }
    void add() {
        added = 1;
        ans.push_back(id);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void calcdist() {
    CL(-1, dist);
    for(int start = 1; start <= m; start++) {
        queue<int> Q;
        dist[start][start] = 0;
        Q.push(start);
        while (!Q.empty()) {
            int i = Q.front(); Q.pop();
            for (int j : adj[i]) if (dist[start][j] == -1) {
                dist[start][j] = dist[start][i] + 1;
                Q.push(j);
            }
        }
    }
}

seg a[10001];

int main() {
    //freopen("x.in", "r", stdin);

    int tt, tn; cin >> tn;
    F1(tt, tn) {
        m = 0; M.clear();
        cin >> n >> k;
        F1(i, n) {
            a[i].read();
            a[i].id = i;
        }
        F1(i, m) p[i] = i;
        ans.clear();
        F1(i, m) adj[i].clear();
        F1(i, n) if (i <= 2) a[i].addtree();
        for (int i = n; i >= 1; i--) a[i].addtree();

        while (1) {
            calcdist();
            int bi = -1;
            int minlca = 10000000;
            F1(i, n) if (!a[i].added) {
                int v = a[i].distance();
                if (v < minlca) {
                    minlca = v;
                    bi = i;
                }
            }


            //P(minlca);
            if (bi == -1) break;
            a[bi].add();
        }

        printf("Case #%d:", tt);
        for (int x : ans) {
            cout << " " << x;
        }
        cout << endl;

    }
    return 0;
}
