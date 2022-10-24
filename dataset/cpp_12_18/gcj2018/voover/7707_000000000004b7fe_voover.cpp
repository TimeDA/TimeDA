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
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

void scase() {
  int N;
  scanf("%d", &N);

  LL maxSum = -2*MOD, minSum = 2*MOD, maxDiff = -2*MOD, minDiff = 2*MOD;
  REP(i,N) {
    LL R, C;
    scanf("%lld%lld", &R, &C);
    maxSum = max(maxSum, R);
    minSum = min(minSum, R);
    maxDiff = max(maxDiff, C);
    minDiff = min(minDiff, C);
  }

  LL res = max((maxSum - minSum + 1) / 2, (maxDiff-minDiff+1) / 2);
  printf("%lld\n", res);  
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
