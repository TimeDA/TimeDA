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

int DP[501][120]; // rows, jugglers
void scase() {
  int R, B;
  scanf("%d%d", &R, &B);
  REP(r,R+1)REP(j,120) DP[r][j] = B + 1;
  REP(r,R+1)DP[r][0] = 0;

  REP(reds_taken,35) REP(blue_taken,35) if(reds_taken+blue_taken) {
    FORD(reds,R-reds_taken+1,0)FORD(jugglers_before,120,0) {
      DP[reds+reds_taken][jugglers_before+1] =
        min(DP[reds+reds_taken][jugglers_before+1],
            DP[reds][jugglers_before]+blue_taken);
    }
    
    // printf("%d %d:\n", R, B);
    // REP(r,R+)
  }

  FORD(j,120,0) {
    if (DP[R][j] <= B) {
      printf("%d\n", j);
      return;
    }
  }
  // printf("%d\n", DP[R][B]);
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
