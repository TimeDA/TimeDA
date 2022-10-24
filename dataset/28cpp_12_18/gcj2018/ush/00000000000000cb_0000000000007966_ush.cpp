
#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

char buf[50];
int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    ll limit;
    scanf("%lld %s", &limit, buf);
    int n = strlen(buf);
    printf("Case #%d: ", iCase+1);
    for(int res = 0; ; ++res) {
      ll damage = 0;
      ll attack = 1;
      REP(i, n) {
        if(buf[i] == 'S') {
          damage += attack;
        } else {
          attack *= 2;
        }
      }
      if(damage <= limit) {
        printf("%d\n", res);
        break;
      }
      bool ok = false;
      for(int i = n-2; i >= 0; --i) {
        if(buf[i] == 'C' && buf[i+1] == 'S') {
          ok = true;
          swap(buf[i], buf[i+1]);
          break;
        }
      }
      if(!ok) {
        printf("IMPOSSIBLE\n");
        break;
      }
    }
  }
  return 0;
}
