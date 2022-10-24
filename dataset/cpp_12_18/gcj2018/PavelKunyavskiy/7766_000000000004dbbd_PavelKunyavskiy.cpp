#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef long double ld;

void PreCalc() {
}

struct rect {
  int x1, y1, x2, y2;
};

class MaxFlow {
public:
  typedef long long flow_type;
  static const flow_type FLOW_INF = 1LL << 60;
private:
  struct Edge {
    int to, next;
    flow_type f, c;
  };

  vector<Edge> es;
  int n;
  vector<int> head;
  vector<int> d;
  vector<int> ptr;

  flow_type dfs(int s, int t, flow_type have, flow_type min_edge) {
    if (s == t) {
      return have;
    }
    flow_type res = 0;
    for (int &i = ptr[s]; i != -1; i = es[i].next) {
      int to = es[i].to;
      if (d[to] != d[s] + 1) continue;
      if (es[i].c < min_edge) continue;
      flow_type done = dfs(to, t, min(have, es[i].c), min_edge);
      pushFlow(i, done);
      have -= done;
      res += done;
      if (have == 0) break;
    }
    return res;
  }

  bool bfs(int s, int t, flow_type min_edge) {
    queue<int> q;
    d = vector<int>(n, -1);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      int e = head[v];
      while (e != -1) {
        if (es[e].c >= min_edge) {
          int to = es[e].to;
          if (d[to] == -1) {
            d[to] = d[v] + 1;
            q.push(to);
          }
        }
        e = es[e].next;
      }
    }
    return d[t] != -1;
  }

public:
  explicit MaxFlow(int n) : n(n), head(n, -1) {}

  int addVertex() {
    int id = n++;
    head.push_back(-1);
    return id;
  }

  int addEdge(int from, int to, flow_type c, flow_type rc = 0) {
    int id = (int) es.size();
    es.push_back({to, head[from], 0, c});
    head[from] = id;
    es.push_back({from, head[to], 0, rc});
    head[to] = id ^ 1;
    return id;
  }

  void pushFlow(int eid, flow_type val) {
    es[eid].f += val, es[eid].c -= val;
    es[eid ^ 1].f -= val, es[eid ^ 1].c += val;
  }

  flow_type getFlow(int s, int t) {
    flow_type res = 0;
    for (flow_type i = FLOW_INF; i >= 1; i /= 2) {
      while (bfs(s, t, i)) {
        ptr = head;
        res += dfs(s, t, FLOW_INF, i);
      }
    }
    return res;
  }
};

struct LRFlow {
  MaxFlow f;
  int s, t;
  ll total;
public:
  LRFlow(int n) : f(n + 2), s(n), t(n + 1), total(0) {}

  void addEdge(int u, int v, ll l, ll r) {
    if (l) {
      f.addEdge(s, v, l);
      f.addEdge(u, t, l);
    }
    f.addEdge(u, v, r - l);
    total += l;
  }

  bool check(int s, int t) {
    f.addEdge(t, s, MaxFlow::FLOW_INF);
    ll res = f.getFlow(this->s, this->t);
    return res == total;
  }
};


void solve() {
  int R, C, s;
  scanf("%d%d%d", &R, &C, &s);
  vector<rect> v(s);

  vector<pair<int, int>> init;

  for (int i = 0; i < s; i++) {
    int x0, y0, d;
    scanf("%d%d%d", &x0, &y0, &d);
    --x0, --y0;
    init.push_back({x0, y0});
    v[i].x1 = max(0, x0 - d);
    v[i].y1 = max(0, y0 - d);
    v[i].x2 = min(R, x0 + d + 1);
    v[i].y2 = min(C, y0 + d + 1);
  }

  vector<int> xs = {0, R}, ys = {0, C};
  for (const rect &r : v) {
    xs.push_back(r.x1);
    xs.push_back(r.x2);
    ys.push_back(r.y1);
    ys.push_back(r.y2);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  R = xs.size() - 1;
  C = ys.size() - 1;

  vector<vector<int>> mask(R, vector<int>(C));

  auto convert = [](const vector<int> &a, int b) -> int {
    return (int) (lower_bound(a.begin(), a.end(), b) - a.begin());
  };

  for (int i = 0; i < s; i++) {
    int xlf = convert(xs, v[i].x1);
    int xrg = convert(xs, v[i].x2);
    int ylf = convert(ys, v[i].y1);
    int yrg = convert(ys, v[i].y2);

    for (int j = xlf; j < xrg; j++) {
      for (int k = ylf; k < yrg; k++) {
        mask[j][k] |= (1 << i);
      }
    }
  }

  vector<vector<ll>> size(R, vector<ll>(C));
  for (int j = 0; j < R; j++) {
    for (int k = 0; k < C; k++) {
      size[j][k] = (xs[j + 1] - xs[j]) * 1LL * (ys[k + 1] - ys[k]);
    }
  }

  for (auto x : init) {
    int xx = (int) (upper_bound(xs.begin(), xs.end(), x.first) - xs.begin() - 1);
    int yy = (int) (upper_bound(ys.begin(), ys.end(), x.second) - ys.begin() - 1);
    size[xx][yy]--;
  }

  vector<ll> mins;

  for (int m = 1; m < (1 << s); m++) {
    ll tot = 0;
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        if (mask[j][k] & m) {
          tot += size[j][k];;
        }
      }
    }
    mins.push_back(tot / __builtin_popcount(m));
  }
  sort(mins.begin(), mins.end());
  mins.erase(unique(mins.begin(), mins.end()), mins.end());
//  eprintf("%d\n", (int)mins.size());

  ll ans = MaxFlow::FLOW_INF;

  auto check = [&](ll min, ll cand) {
    LRFlow f(s + R * C + 2);
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          if (mask[j][k] & (1 << i)) {
            f.addEdge(i, s + j * C + k, 0, MaxFlow::FLOW_INF);
          }
        }
      }
    }
    for (int i = 0; i < s; i++) {
      f.addEdge(s + R * C, i, min, min + cand);
    }
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        if (mask[j][k]) {
          f.addEdge(s + j * C + k, s + R * C + 1, size[j][k], size[j][k]);
        }
      }
    }

    return f.check(s + R * C, s + R * C + 1);
  };

  for (ll min : mins) {
//    eprintf("mins = %lld, ans = %lld\n", min, ans);
    ll lf = -1;
    ll rg = ans;
    if (!check(min, rg)) {
      continue;
    }
    assert(min == mins[0]);
    while (rg - lf > 1) {
      ll cand = (lf + rg) / 2;
      if (check(min, cand)) {
        rg = cand;
      } else {
        lf = cand;
      }
    }
    assert(min == mins[0] || ans == rg);
    ans = rg;
    break; // why??
  }

  printf("%lld\n", ans);
}


int main() {
#ifdef LOCAL
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
#endif


  PreCalc();
  TIMESTAMP(PreCalc);

  char buf[1000];
  int testNum;
  fgets(buf, sizeof buf, stdin);
  sscanf(buf, "%d", &testNum);

  for (int testId = 1; testId <= testNum; testId++) {
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
      TIMESTAMPf("Test %d", testId);
    printf("Case #%d: ", testId);
    solve();
  }

  TIMESTAMP(end);
  return 0;
}
