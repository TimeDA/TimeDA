
#include <cstdio>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int n;
int rs[10000+10];
int cs[10000+10];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d", &n);
    REP(i, n) {
      scanf("%d%d", &rs[i], &cs[i]);
    }
    int dr = *max_element(rs, rs + n) - *min_element(rs, rs + n);
    int dc = *max_element(cs, cs + n) - *min_element(cs, cs + n);
    int res = (max(dr, dc)+1) / 2;
    
    printf("Case #%d: %d\n", iCase+1, res);
    
  }
  return 0;
}
