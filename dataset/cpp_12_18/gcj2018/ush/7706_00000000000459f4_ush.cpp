
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

struct UF {
  vector<int> data;
  int nDistinct;
  UF() {}
  UF(int n) : data(n, -1), nDistinct(n) {}
  void init(int n) { data.assign(n, -1); nDistinct = n; }
  int size(void) const { return nDistinct; }
  int rootOf(int a) { return data[a] >= 0 ? data[a] = rootOf(data[a]) : a; }
  int count(int a) { return -data[rootOf(a)]; }
  bool isSameGroup(int a, int b) { return rootOf(a) == rootOf(b); }
  bool unify(int a, int b) {
    int ra = rootOf(a), rb = rootOf(b);
    if(ra == rb) return false;
    if(data[ra] < data[rb]) swap(ra, rb);
    data[rb] += data[ra]; data[ra] = rb; --nDistinct;
    return true;
  }
};

int nRow, nCol;
char board[22][22];
bool used[22][22];

int pos2id[22][22];


int solve(void) {
  int res = 1;
  REP(pat, 1 << (nRow*nCol)) {
    int cur = 0;
    REP(i, nRow) REP(j, nCol) {
      if(pat & (1 << (i*nCol + j))) {
        used[i][j] = true;
        pos2id[i][j] = cur;
        ++cur;
      } else {
        used[i][j] = false;
        pos2id[i][j] = -1;
      }
    }
    if(cur <= res) {
      continue;
    }
    // connected?
    UF uf(cur);
    REP(i, nRow) REP(j, nCol) if(used[i][j]) {
      if(i+1 < nRow && used[i+1][j]) {
        assert(pos2id[i][j] >= 0);
        assert(pos2id[i+1][j] >= 0);
        uf.unify(pos2id[i][j], pos2id[i+1][j]);
      }
      if(j+1 < nCol && used[i][j+1]) {
        assert(pos2id[i][j] >= 0);
        assert(pos2id[i][j+1] >= 0);
        uf.unify(pos2id[i][j], pos2id[i][j+1]);
      }
    }
    if(uf.size() != 1) {
      continue;
    }
    // appear?
    int ok = 0;
    for(int t = 1, p = 2; t <= 7; ++t, p *= 2) {
      int r = nRow * p;
      int c = nCol * p;
      for(int i = -4; i < r; ++i) for(int j = -4; j < c; ++j) {
        bool yes = true;
        REP(ii, nRow) REP(jj, nCol) {
          if(used[ii][jj]) {
            if(i+ii >= 0 && i+ii < r && j+jj >= 0 && j+jj < c && board[(i+ii)/p][(j+jj)/p] == board[ii][jj]) {
              // yes
            } else {
              yes = false;
              goto FOO;
            }
          }
        }
      FOO:
        if(yes) {
          ok++;
          if(ok >= 2) {
            goto HOGE;
          }
        }
      }
    }
  HOGE:
    if(ok >= 2) {
      // fprintf(stderr, "> %x\n", pat);
      // REP(i, nRow) {
      //   REP(j, nCol) {
      //     fprintf(stderr, "%d", used[i][j]);
      //   }
      //   fprintf(stderr, "\n");
      // }
      res = max(res, cur);
    }
  }
  return res;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d%d", &nRow, &nCol);
    REP(i, nRow) {
      scanf("%s", board[i]);
    }
    int res = solve();
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
