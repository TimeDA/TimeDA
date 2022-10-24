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

int N;
char P2[100];
void optimize() {
  FORD(i,N-1,0) if (P2[i] == 'C' && P2[i+1] == 'S') {
    swap(P2[i], P2[i+1]);
    return;
  }
}

int value() {
  int c = 1;
  int res = 0;
  REP(i,N) if (P2[i] == 'S') res += c; else c *= 2;
  return res;
}

char P[100];

void scase() {
  int D;
  scanf("%d%s", &D, P);

  N = strlen(P);
  FOR(ch,0,N*N) {
    REP(i,N) P2[i] = P[i];
    REP(k,ch) optimize();
    if (value() <= D) {
      printf("%d\n", ch);
      return;
    }
  }

  printf("IMPOSSIBLE\n");
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
