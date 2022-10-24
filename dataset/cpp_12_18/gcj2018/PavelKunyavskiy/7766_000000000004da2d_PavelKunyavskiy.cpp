#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef long double ld;



void PreCalc() {

}

void solve() {
  eprintf("HERE!!\n");
  int s;
  scanf("%d", &s);
  int l = 1;
  int r = 1e6 + 1;
  vector<int> result;
  while (r - l > 1) {
    int m = (l + r) / 2;
    for (int i = 0; i < 25; i++) {
      printf("%d\n", m);
    }
    fflush(stdout);
    bool any = false;
    for (int i = 0; i < 25; i++) {
      int x;
      scanf("%d", &x);
//      eprintf("x = %d\n", x);
      result.push_back(x);
      if (x == 0) {
        any = true;
      }
    }
//    eprintf("m = %d, any = %d\n", m, any);
    if (any) {
      l = m;
    } else {
      r = m;
    }
  }

  int old_size = (int)result.size();

  eprintf("l = %d, r = %d\n", l, r);

  while ((int)result.size() < s) {
    int ops = min(1000, s - (int)result.size());
    for (int i = 0; i < ops; i++) {
      printf("%d\n", l);
    }
    fflush(stdout);

    for (int i = 0; i < ops; i++) {
      int x;
      scanf("%d", &x);
      result.push_back(x);
    }
  }


  for (int i = 2; i <= 25; i++) {
    bool fail = false;
    for (int j = (old_size + i - 1) / i * i; j + i < (int)result.size(); j += i) {
      int cnt = 0;
      for (int k = 0; k < i; k++) {
        if (result[j + k] == 0) {
          cnt++;
        }
      }
//      eprintf("i = %d, j = %d, cnt = %d\n", i, j, cnt);
      if (cnt != 1) {
        fail = true;
        break;
      }
    }
    if (!fail) {
      printf("%d\n", -i);
      fflush(stdout);
      return;
    }
  }

  assert(0);

}


int main() {

  PreCalc();
  TIMESTAMP(PreCalc);

  char buf[1000];
  int testNum;
  fgets(buf, sizeof buf, stdin);
  sscanf(buf, "%d", &testNum);

  for (int testId = 1; testId <= testNum; testId++) {
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
      TIMESTAMPf("Test %d", testId);
//    printf("Case #%d: ", testId);
    solve();
  }

  TIMESTAMP(end);
  return 0;
}
