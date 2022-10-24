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

int B[200];
char out[300][205];

void scase() {
  int C;
  scanf("%d", &C);
  REP(i,C) scanf("%d", &B[i]);
  REP(i,300) {
    REP(j, C) out[i][j] = '.';
    out[i][C] = 0;
  }

  int S = 0;
  REP(i,C) S += B[i];
  if (S != C || B[0] < 1 || B[C-1] < 1) {
    printf("IMPOSSIBLE\n");
    return;
  }

  vector<int> column;
  REP(i,C)REP(j, B[i]) column.pb(i);

  int nonempty = 0;
  REP(i,C) {
    if (column[i] < i) {
      REP(j, i - column[i]) {
        out[j][i-j] = '/';
        nonempty = max(nonempty, j+1);
      }
    } else  {
      REP(j, column[i] - i) {
        out[j][i+j] = '\\';
        nonempty = max(nonempty, j+1);
      }
    }
  }
  printf("%d\n", nonempty + 1);
  REP(i, nonempty +1) printf("%s\n", out[i]);
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
