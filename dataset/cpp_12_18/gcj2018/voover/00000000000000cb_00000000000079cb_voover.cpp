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

int A[111111], B[111111];

void scase() {
  int N;
  scanf("%d", &N);
  REP(i,N) scanf("%d", &A[i]);

  REP(k,2) {
    vector<int> tmp;
    REP(i,N) if (i%2 == k) tmp.pb(A[i]);
    sort(tmp.begin(), tmp.end());
    int j = 0;
    REP(i,N) if (i%2 == k) B[i] = tmp[j++];
  }

  sort(A, A+N);
  REP(i,N) if (A[i] != B[i]) {
    printf("%d\n", i);
    return;
  }
  printf("OK\n");
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
