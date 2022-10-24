
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int vs[2][100000+10];
int as[100000+10];
int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int n;
    scanf("%d", &n);
    REP(i, n) {
      scanf("%d", &vs[i%2][i/2]);
    }
    sort(vs[0], vs[0] + (n+1)/2);
    sort(vs[1], vs[1] + n/2);
    int res = -1;
    REP(i, n) {
      as[i] = vs[i%2][i/2];
    }
    REP(i, n-1) {
      if(as[i] > as[i+1]) {
        res = i;
        break;
      }
    }
    printf("Case #%d: ", iCase+1);
    if(res < 0) {
      printf("OK\n");
    } else {
      printf("%d\n", res);
    }
  }
  return 0;
}
