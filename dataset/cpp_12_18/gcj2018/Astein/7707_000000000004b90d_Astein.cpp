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
    vector<long long> x(N), y(N), h(N);
    for (int i = 0; i < N; ++i)
    {
      int xx, yy, hh;
      scanf("%d%d%d", &xx, &yy, &hh);
      x[i] = xx, y[i] = yy, h[i] = hh;
    }
    printf("Case #%d:", cn);
    vector<int> order;
    for (int i = 0; i < N; ++i)
      order.push_back(i);
    do
    {
      long long A, B, C, D;
      bool found = true;
      vector<int> check(N, 0);
/*
      for (int i = 0; i < N; ++i)
        printf("%d ", order[i]);
    printf(" --> ");
*/    
   check[order[0]] = 1;
   check[order[1]] = 1;
      for (int i = 2; i < N; ++i)
      {
        check[order[i]] = 1;
        long long x1 = x[order[i - 2]], y1 = y[order[i - 2]], z1 = h[order[i - 2]];
        long long x2 = x[order[i - 1]], y2 = y[order[i - 1]], z2 = h[order[i - 1]];
        long long x3 = x[order[i - 0]], y3 = y[order[i - 0]], z3 = h[order[i - 0]];

        A = y1 * (z2 - z3) + y2 * (z3 - z1) + y3 * (z1 - z2);
        B = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
        C = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        D = -(x1 * (y2 * z3 - y3 * z2) + x2 * (y3 * z1 - y1 * z3) + x3 * (y1 * z2 - y2 * z1));

        bool ispos = true;
        for (int j = 0; j < N; ++j)
        {
		    if (check[j] == 0) continue;
	        long long right = -D - A * x[j] - B * y[j];
	        double zz = right * 1.0 / C;
			if (zz <= 0) ispos = false;
			if (h[j] > zz) ispos = false;
//			printf("%Ld,%.3lf//", h[j], zz);
        }
        if (!ispos)
        {
          
          found = false;
          break;
        }
      }
//      printf("\n");
      if (found)
      {
        for (int i = 0; i < N; ++i)
          printf(" %d", order[i] + 1);
        printf("\n");
        break;
      }
    }
    while (next_permutation(order.begin(), order.end()));
  }
}