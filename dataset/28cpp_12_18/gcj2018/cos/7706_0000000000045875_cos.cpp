#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

typedef int Weight;
struct Edge {
  int index;
  int src;
  int dest;
  Weight weight;
  Edge(int index, int src, int dest, Weight weight) : index(index), src(src), dest(dest), weight(weight) {;}
  bool operator<(const Edge &rhs) const {
    if (weight != rhs.weight) { return weight > rhs.weight; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void PrintMatrix(const Matrix &matrix) {
  for (int y = 0; y < (int)matrix.size(); y++) {
    for (int x = 0; x < (int)matrix[y].size(); x++) {
      cout << matrix[y][x] << " ";
      // printf("%d ", matrix[y][x]);
    }
    puts("");
  }
}

Weight augment(const Graph &g, Array &capacity, const vector<int> &level, vector<bool> &finished, int from, int t, Weight cur) {
  if (from == t || cur == 0) { return cur; }
  if (finished[from]) { return 0; }
  for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
    int to = it->dest;
    if (level[to] != level[from] + 1) { continue; }
    Weight f = augment(g, capacity, level, finished, to, t, min(cur, capacity[it->index]));
    if (f > 0) {
      capacity[it->index] -= f;
      capacity[it->index^1] += f;
      return f;
    }
  }
  finished[from] = true;
  return 0;
}

// index^1 is reverse edge
Weight MaxFlow(const Graph &g, int e, int s, int t) {
  int n = g.size();
  Array capacity(e);
  for (int from = 0; from < n; from++) {
    for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
      capacity[it->index] += it->weight;
    }
  }
  int ans = 0;
  while (true) {
    vector<int> level(n, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    for (int d = n; !que.empty() && level[que.front()] < d; ) {
      int from = que.front();
      que.pop();
      if (from == t) { d = level[from]; }
      for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
        int to = it->dest;
        if (capacity[it->index] > 0 && level[to] == -1) {
          que.push(to);
          level[to] = level[from] + 1;
        }
      }
    }
    vector<bool> finished(n);
    bool end = true;
    while (true) {
      Weight f = augment(g, capacity, level, finished, s, t, 2000000000LL);
      if (f == 0) { break; }
      ans += f;
      end = false;
    }
    if (end) { break; }
  }
  return ans;
}

void AddEdge(Graph &g, int &e, int from, int to, Weight capacity) {
  g[from].push_back(Edge(e++, from, to, capacity));
  g[to].push_back(Edge(e++, to, from, 0));
}

int n;
int X(int x, int c) { return x + c * n; }
int Y(int y, int c) { return y + c * n + n * (2 * n); }
int SOURCE() { return 2 * n * (2 * n); }
int DEST() { return 2 * n * (2 * n) + 1; }
int SIZE() { return 2 * n * (2 * n) + 2; }

int field[110][110];
void solve() {
  scanf("%d", &n);
  Graph g = Graph(SIZE());
  int e = 0;
  REP(i, n) {
    REP(c, 2 * n) {
      AddEdge(g, e, SOURCE(), X(i, c), 1);
      AddEdge(g, e, Y(i, c), DEST(), 1);
    }
  }
  REP(y, n) {
    REP(x, n) {
      scanf("%d", &field[y][x]);
      int c = 0;
      if (field[y][x] > 0) {
        c = field[y][x] - 1;
      } else {
        c = n + (-field[y][x] - 1);
      }
      AddEdge(g, e, X(x, c), Y(y, c), 1);
    }
  }
  int flow = MaxFlow(g, e, SOURCE(), DEST());
  int ans = n * n - flow;
  printf("%d\n", ans);
}
