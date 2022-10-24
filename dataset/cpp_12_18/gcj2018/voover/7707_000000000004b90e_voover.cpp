#include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

typedef LL T;
const LL EPS = 0;
bool ccw(PII a, PII b, PII c) {
  T A[] = {a.st-b.st,a.nd-b.nd,b.st-c.st,b.nd-c.nd};
  T det = A[0]*A[3] - A[1]*A[2];
  T cro = A[0]*A[2] + A[1]*A[3];
  return (det > EPS) || ((det>=-EPS) && (cro < -EPS));
}

bool is_inside(const vector<PII>& poly, PII pt) {
  int left = 0;
  REP(i,poly.size()) {
    PII p1 = poly[i];
    PII p2 = poly[(i+1)%poly.size()];
    if (p1.nd > p2.nd) swap(p1, p2);
    if (p1.nd < pt.nd && pt.nd <= p2.nd && ccw(p1, pt, p2)) ++left;
  }
  return left % 2;
}

vector<pair<PII, PII>> fences;

PII point[1000];
map<PII, int> point_name;
vector<PII> adj[1000];

int point_visited[1000];
int fence_visited[1000];
int parent[1000];

int dfstime = 1;

void go(int v) {
  point_visited[v] = dfstime++;
  for (auto p: adj[v]) {
    if (!point_visited[p.st]) {
      fence_visited[p.nd] = true;
      printf("%d ", p.nd + 1);

      go(p.st);
      parent[p.st] = v;
    }
  }
}

void scase() {
  int F, K;
  scanf("%d%d", &F, &K);
  fences.clear();
  point_name.clear();
  REP(i,1000) {
    adj[i].clear();
    point_visited[i] = fence_visited[i] = false;
  }

  REP(i,F) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a *= 2, b *= 2, c *= 2, d *= 2;
    fences.pb({{a,b}, {c,d}});
  }

  int N = 2;
  point_name[fences[0].st] = 0;
  point_name[fences[0].nd] = 1;
  REP(i,F) {
    if (point_name.find(fences[i].st) == point_name.end()) {
      point_name[fences[i].st] = N++;
    }
    if (point_name.find(fences[i].nd) == point_name.end()) {
      point_name[fences[i].nd] = N++;
    }
    point[point_name[fences[i].st]] = fences[i].st;
    point[point_name[fences[i].nd]] = fences[i].nd;

    int u = point_name[fences[i].st];
    int v = point_name[fences[i].nd];

    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }
  go(0);

  vector<int> after[1000];
  vector<int> befc(1000);

  // printf(" | ");

  REP(i,F)REP(j,F) if (i != j) {
    if (fence_visited[i] || fence_visited[j]) continue;

    vector<PII> poly;
    {
      int u = point_name[fences[i].st];
      int v = point_name[fences[i].nd];

      if (point_visited[u] < point_visited[v]) swap(u, v);
      poly.pb({point[u]});
      do {
        u = parent[u];
        poly.pb({point[u]});
      } while (u != v);
    }

    if (is_inside(poly, {
      (fences[j].st.st + fences[j].nd.st) / 2,
      (fences[j].st.nd + fences[j].nd.nd) / 2
    })) {
      after[j].pb(i);
      befc[i]++;
      // printf("(%d->%d) ", j+1, i+1);
    }
  }

  queue<int> Q;
  REP(i,F) if (befc[i] == 0) {
    if (!fence_visited[i]) printf("%d ", i + 1);
    Q.push(i);
  }
  while (!Q.empty()) {
    for (int j: after[Q.front()]) {
      if (!(--befc[j])) {
        if (!fence_visited[j]) printf("%d ", j + 1);
        Q.push(j);
      }
    }
    Q.pop();
  }

  printf("\n");
}

int main() {
  // ios_base::sync_with_stdio(0);

  int C;
  scanf("%d",&C);
  FOR(i,1,C+1) {
    printf("Case #%d: ", i);
    scase();
  }
}
