#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

int send(int x) {
  printf("%d\n", x);
  fflush(stdout);
  static char buffer[200];
  scanf("%s",  buffer);
  if (!strcmp(buffer, "CORRECT")) return 0;
  if (!strcmp(buffer, "TOO_SMALL")) return -1;
  if (!strcmp(buffer, "TOO_BIG")) return 1;
  exit(0);
}

void solve() {
  int l, r;
  scanf("%d%d%*d", &l, &r);
  r++;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int res = send(m);
    if (!res) return;
    if (res == -1) l = m;
    else r = m;
  }
  assert(0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t-->0) {
    solve();
  }
}
