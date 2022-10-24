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
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

namespace graph {
  const int N = 10000;
  int n1,n2;          // INPUT
  vector<int> g[N];   // INPUT
  int m1[N], m2[N];   // OUTPUT
  bool c[N];

  bool dfs(int u) {
      if (u<0) return true;
      if (c[u]) return false; else c[u]=true;
      for (auto v: g[u])
          if (dfs(m2[v])) { m1[u] = v; m2[v] = u; return true; }
      return false;
  }

  int matching() {
      REP(i,n1) m1[i]=-1;
      REP(i,n2) m2[i]=-1;
      bool changed;
      do {
          changed = 0;
          REP(i,n1) c[i]=false;
          REP(i,n1) if (m1[i]<0) changed |= dfs(i);
      } while(changed);
      int siz = 0;
      REP(i,n1) siz += (m1[i]!=-1);
      return siz;
  }
};

vector<PII> pairs[200];

void scase() {
  int N;
  scanf("%d", &N);
  REP(i,2*N) pairs[i].clear();

  REP(i,N)REP(j,N) {
    int c;
    scanf("%d", &c);
    if (c < 0) c += N;
    else c += N-1;

    pairs[c].pb({i, j});
  }

  int result = N*N;
  REP(c,2*N) {
    graph::n1 = N;
    graph::n2 = N;
    REP(i,N) graph::g[i].clear();

    for (auto p: pairs[c]) graph::g[p.st].pb(p.nd);
    result -= graph::matching();
  }

  printf("%d\n", result);
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
