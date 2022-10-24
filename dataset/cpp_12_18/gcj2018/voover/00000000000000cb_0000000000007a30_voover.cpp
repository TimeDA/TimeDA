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

bool taken[1000][1000];

void scase() {
  int N;
  scanf("%d", &N);

  int K = 3;
  while (K * K < N) ++K;
  FOR(i,1,K+1)FOR(j,1,K+1) taken[i][j] = 0;

  FOR(i,1,K+1)FOR(j,1,K+1) {
    int a = max(min(K-1,i),2), b = max(min(K-1,j),2);
    while (!taken[i][j]) {
      printf("%d %d\n", a, b);
      fflush(stdout);
      int aa, bb;
      scanf("%d%d", &aa, &bb);
      if (aa == 0 && bb == 0) return;
      taken[aa][bb] = 1;
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(0);

  int C;
  scanf("%d",&C);
  FOR(i,1,C+1) {
    // printf("Case #%d: ", i);
    scase();
  }
}
