#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; ++cn)
  {
    int N;
    scanf("%d", &N);
    int rmin, rmax, cmin, cmax;

    for (int i = 0; i < N; ++i)
    {
      int r, c;
      scanf("%d%d", &r, &c);
      if (i == 0)
      {
        rmin = rmax = r;
        cmin = cmax = c;
      }
      else
      {
        if (r < rmin) rmin = r;
        if (r > rmax) rmax = r;
        if (c < cmin) cmin = c;
        if (c > cmax) cmax = c;
      }
    }
    int rdiff = rmax - rmin;
    int cdiff = cmax - cmin;
    int maxdiff = max(rdiff, cdiff);
    printf("Case #%d: %d\n", cn, (maxdiff + 1) / 2);
  }
}
