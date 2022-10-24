
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

char buf[110][110];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int nRow, nCol, nHori, nVert;
    scanf("%d%d%d%d", &nRow, &nCol, &nHori, &nVert);
    int n = 0;
    REP(i, nRow) {
      scanf("%s", buf[i]);
      REP(j, nCol) {
        if(buf[i][j] == '@') {
          ++n;
        }
      }
    }
    int piece = (nHori+1) * (nVert+1);
    bool possible = true;
    if(n % piece != 0) {
      possible = false;
    }
    if(possible) {
      int each = n / piece;
      vector<int> horis, verts;

      {
        horis.push_back(0);
        int cur = 0;
        REP(i, nRow) {
          REP(j, nCol) {
            if(buf[i][j] == '@') {
              cur++;
            }
          }
          if(cur == each * (nVert+1)) {
            horis.push_back(i+1);
            cur = 0;
          } else if(cur > each * (nVert+1)) {
            possible = false;
            goto OUT;
          }
        }
        if(cur != 0) {
          possible = false;
          goto OUT;
        }
      }

      {
        verts.push_back(0);
        int cur = 0;
        REP(j, nCol) {
          REP(i, nRow) {
            if(buf[i][j] == '@') {
              cur++;
            }
          }
          if(cur == each * (nHori+1)) {
            verts.push_back(j+1);
            cur = 0;
          } else if(cur > each * (nHori+1)) {
            possible = false;
            goto OUT;
          }
        }
        if(cur != 0) {
          possible = false;
          goto OUT;
        }
      }

      // if((int)horis.size() != nHori+2 || (int)verts.size() != nVert+2) {
      //   cerr << "> " << horis.size() << " " << verts.size() << endl;
      //   possible = false;
      //   goto OUT;
      // }
      REP(i, horis.size() - 1) {
        REP(j, verts.size() - 1) {
          int cnt = 0;
          for(int ii = horis[i]; ii < horis[i+1]; ++ii) {
            for(int jj = verts[j]; jj < verts[j+1]; ++jj) {
              if(buf[ii][jj] == '@') {
                ++cnt;
              }
            }
          }
          if(cnt != each) {
            possible = false;
            goto OUT;
          }
        }
      }
    }
    OUT:
      ;
    printf("Case #%d: %s\n", iCase+1, possible ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}
