
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

ll ms[1010];
ll ss[1010];
ll ps[1010];
ll buf[1010];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int nRobot, nCash;
    ll nBit;
    scanf("%d%lld%d", &nRobot, &nBit, &nCash);
    REP(i, nCash) {
      scanf("%lld%lld%lld", &ms[i], &ss[i], &ps[i]);
    }
    ll left = 0;
    ll right = 2e18;
    while(left + 1 < right) {
      ll med = (left + right) / 2;
      REP(i, nCash) {
        buf[i] = min(ms[i], max(0LL, (med - ps[i]) / ss[i]));
      }
      sort(buf, buf + nCash);
      reverse(buf, buf + nCash);
      ll sum = 0;
      REP(i, nRobot) {
        sum += buf[i];
      }
      if(sum >= nBit) {
        right = med;
      } else {
        left = med;
      }
    }
    printf("Case #%d: %lld\n", iCase+1, right);
  }
  return 0;
}
