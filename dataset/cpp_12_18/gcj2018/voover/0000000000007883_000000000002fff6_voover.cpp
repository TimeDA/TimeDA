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

int R, B, C;
int M[2000], S[2000], P[2000];

bool can(LL T) {
  vector<LL> cnts;
  REP(i,C) {
    cnts.pb(min((LL)M[i], max(0LL, (T - P[i])) / S[i]));
  }
  sort(cnts.rbegin(), cnts.rend());

  LL S = 0;
  REP(i,min(R,C)) S += cnts[i];

  return S >= B;
}

void scase() {
  scanf("%d%d%d", &R, &B, &C);
  REP(i,C) scanf("%d%d%d", &M[i], &S[i], &P[i]);

  LL L = 0, R = 1e18;
  while (L < R) {
    LL S = (L+R)/2;
    if (can(S)) R = S;
    else L = S + 1;
  }
  printf("%lld\n", L);
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
