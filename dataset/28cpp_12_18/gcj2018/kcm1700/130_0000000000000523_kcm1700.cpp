#include <cstdio>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <string>
#include <algorithm>
#include <thread>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T-->0) {
    int A, B;
    int N;
    scanf("%d%d", &A, &B);
    scanf("%d", &N);
    for (;;) {
      int guess = (A + 1 + B) / 2;
      printf("%d\n", guess);
      fflush(stdout);
      char verdictraw[256];
      scanf("%s", verdictraw);
      string verdict = verdictraw;
      if ("CORRECT" == verdict) {
        break;
      }
      else if ("TOO_SMALL" == verdict) {
        A = guess;
      }
      else if ("TOO_BIG" == verdict) {
        B = guess - 1;
      }
      else {
        return 0;
      }
    }
  }
  return 0;
}