
#include <cstdio>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int guess(int x) {
  printf("%d\n", x);
  fflush(stdout);
  char buf[20];
  scanf("%s", buf);
  return buf[0] == 'C' ? 0 : buf[4] == 'S' ? -1 : 1;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int a, b;
    scanf("%d%d", &a, &b);
    int limit;
    scanf("%d", &limit);

    while(a+1 < b) {
      int md = (a + b) / 2;
      int res = guess(md);
      if(res == 0) {
        goto NEXT_CASE;
      } else if(res == -1) {
        a = md;
      } else {
        b = md;
      }
    }
    guess(b);
  NEXT_CASE:
    ;
  }
  return 0;
}
