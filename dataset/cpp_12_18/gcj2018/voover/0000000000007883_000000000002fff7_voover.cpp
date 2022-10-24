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

typedef pair<int, double> PID;

vector<PID> normalize(vector<PID>& v) {
  sort(v.begin(), v.end());
  vector<PID> res;
  for (auto p: v) {
    if (res.empty()) {
      res.pb(p);
      continue;
    }
    if (res.back().nd >= p.st) {
      res.back().nd = p.nd;
    } else {
      res.pb(p);
    }
  }
  return res;
}

void scase() {
  int N;
  double P;
  scanf("%d%lf", &N, &P);
  vector<PID> ints;
  int res = 0;
  REP(i,N) {
    int A, B;
    scanf("%d%d", &A, &B);
    res += 2 * A + 2 * B;
    ints.pb({ 2*min(A, B), 2*sqrt(A*A+B*B) });
  }

  vector<PID> poss = {{res, res}};
  REP(i,N) {
    int K = poss.size();
    REP(j,K) poss.pb({poss[j].st + ints[i].st, poss[j].nd + ints[i].nd});
    poss = normalize(poss);
  }

  double result = 0.0;
  for (auto p: poss) {
    if (p.st <= P) {
      result = max(result, min(p.nd, P));
    }
  }
  printf("%0.9lf\n", result);
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
