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

int R, C;
char B[30][30];

bool visited[30][30];

char pattern[2][2];
int Mr, Mc;
int go(int r, int c) {
  if (r >= R || r < 0 || c >= C || c < 0) return 0;
  if (visited[r][c]) return 0;
  visited[r][c] = true;

  if (B[r][c] != pattern[r>=Mr][c>=Mc]) {
    return 0;
  }

  return 1 + go(r-1,c) + go(r+1, c) + go(r, c-1) + go(r, c+1);
}

int result = 0;
void scan() {
  REP(r,R)REP(c,C) visited[r][c] = false;

  REP(r,R)REP(c,C) if (!visited[r][c]) {
    result = max(result, go(r,c));
  }
}

void scase() {
  scanf("%d%d", &R, &C);

  REP(r,R) scanf("%s", B[r]);
  REP(r,R)REP(c,C) B[r][c] = (B[r][c] == 'B');

  result = 0;

  Mr = R, Mc = C;
  pattern[0][0] = 0;
  scan();

  pattern[0][0] = 1;
  scan();

  REP(a,2) {
    pattern[0][0] = a;
    pattern[0][1] = 1-a;

    bool has_pattern = false;
    REP(r,R)REP(c,C-1) if (B[r][c] == pattern[0][0] && B[r][c+1] == pattern[0][1])
      has_pattern = true;

    if (!has_pattern) {
      continue;
    }
    REP(c,C) {
      Mr = R, Mc = c;
      scan();
    }
  }

  REP(a,2) {
    pattern[0][0] = a;
    pattern[1][0] = 1-a;

    bool has_pattern = false;
    REP(r,R-1)REP(c,C) if (B[r][c] == pattern[0][0] && B[r+1][c] == pattern[1][0])
      has_pattern = true;

    if (!has_pattern) {
      continue;
    }
    REP(r,R) {
      Mr = r, Mc = C;
      scan();
    }
  }

  REP(m,16) {
    int m2 = m;
    REP(i,2)REP(j,2) {
      pattern[i][j] = m2&1;
      m2 >>= 1;
    }

    bool has_pattern = false;
    REP(r,R-1)REP(c,C-1) {
      bool ok = true;
      REP(i,2)REP(j,2) ok = ok && B[r+i][c+j] == pattern[i][j];
      if (ok) has_pattern = true;
    }

    if (has_pattern) {
      REP(r,R)REP(c,C) {
        Mr = r, Mc = c;
        scan();
      }
    }
  }

  printf("%d\n", result);
}

int main() {
  // ios_base::sync_with_stdio(0);

  int CC;
  scanf("%d",&CC);
  FOR(i,1,CC+1) {
    printf("Case #%d: ", i);
    scase();
  }
}
