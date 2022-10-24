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

char B[500][500];

const char* IMPOSSIBLE = "IMPOSSIBLE";

void scase() {
  int R, C, H, V;
  scanf("%d%d%d%d", &R, &C, &H, &V);
  REP(i,R) scanf("%s", B[i]);
  int K = 0;
  REP(i,R)REP(j,C) K += (B[i][j] == '@');
  if (K % ((H+1)*(V+1))) {
    printf("%s\n", IMPOSSIBLE); return;
  }
  K /= ((H+1)*(V+1));

  vector<int> horizontal, vertical;

  horizontal.pb(0);

  int X = 0;
  REP(r,R) {
    REP(c,C) X += (B[r][c] == '@');
    if (X > (horizontal.size()) * K * (V+1)) {
      printf("%s\n", IMPOSSIBLE); return;
    } else if ((horizontal.size()) * K * (V+1) == X) {
      horizontal.pb(r+1);
    }
  }

  vertical.pb(0);
  X = 0;
  REP(c,C) {
    REP(r,R) X += (B[r][c] == '@');
    if (X > (vertical.size()) * K * (H+1)) {
      printf("%s\n", IMPOSSIBLE); return;
    } else if ((vertical.size()) * K * (H + 1)== X) {
      vertical.pb(c+1);
    }
  }

  REP(v,V)REP(h,H) {
    int cnt = 0;
    FOR(r,horizontal[h],horizontal[h+1])
      FOR(c, vertical[v], vertical[v+1]) {
        cnt += (B[r][c] == '@');
      }
    if (cnt != K) {
      printf("%s\n", IMPOSSIBLE); return;
    }
  }

  printf("POSSIBLE\n");
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
