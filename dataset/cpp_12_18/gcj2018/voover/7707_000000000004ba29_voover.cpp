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

int deg[20];
int G[20][20];
int G2[20][20];

bool findone() {
  REP(i,10) deg[i] = 0;
  REP(i,10)REP(j,10) G[i][j] = 0;

  REP(e,20) {
    int u, v;
    int tries = 0;
    do {
      ++tries;
      if (tries == 10000) {
        printf(":(\n");
        return false;
      }

      u = rand() % 10;
      v = (rand() % 9 + 1 + u) % 10;
    } while (deg[u] == 4 || deg[v] == 4 || G[u][v]);

    G[u][v] = G[v][u] = 1;
    ++deg[u];
    ++deg[v];
  }

  vector<int> perm(10);
  REP(i,10) perm[i] = i;
  set<LL> masks;
  int expected = 0;
  do {
    REP(i,10)REP(j,10) G2[i][j] = G[perm[i]][perm[j]];
    LL m = 0;
    REP(i,10)REP(j,i) m = m * 2 + G2[i][j];
    masks.insert(m);

    ++expected;
  } while (next_permutation(perm.begin(), perm.end()));

  printf("%d %d\n", masks.size(), expected);

  return masks.size() == expected;
}

vector<string> data = {
  "0011000101",
  "0000111100",
  "1000001011",
  "1000101010",
  "0101010010",
  "0100101001",
  "0111010000",
  "1100000011",
  "0011100100",
  "1010010100"
};

int main() {
  // ios_base::sync_with_stdio(0);

  // while (!findone()) {}
  //
  // REP(i,10) {
  //   printf("\"");
  //   REP(j,10) printf("%d", G[i][j]);
  //   printf("\"\n");
  // }

  printf("10\n");
  REP(i,10)REP(j,i) if (data[i][j] == '1') printf("%d %d\n", i+1, j+1);
  fflush(stdout);

  REP(i,10)REP(j,10) G[i][j] = data[i][j] == '1';

  scanf("%*d");
  REP(i,20) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    G2[a][b] = G2[b][a] = 1;
  }

  vector<int> perm(10);
  REP(i,10) perm[i] = i;
  do {
    bool ok = true;
    REP(i,10)REP(j,10) ok = ok && G2[perm[i]][perm[j]] == G[i][j];
    if (ok) {
      REP(i,10) printf("%d ", perm[i] + 1);
      printf("\n");
      return 0;
    }
  } while (next_permutation(perm.begin(), perm.end()));

}
