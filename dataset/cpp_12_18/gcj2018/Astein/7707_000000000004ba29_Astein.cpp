#include <bits/stdc++.h>

using namespace std;

vector<int> graph[55];
int table[55][55], table2[55][55];

int N;

int main()
{
  int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; ++cn)
  {
    int L, U;
    scanf("%d", &L);
    if (L == -1)
    {
      return 0;
    }
    scanf("%d", &U);
    fprintf(stderr, "L = %d, U = %d\n", L, U);
    // easy
    printf("10\n");
    int a[40] = {1, 2, 1, 3, 1, 4, 1, 7, 2, 4, 2, 5, 2, 6, 3, 5, 3, 6, 4, 7, 4, 8, 5, 8, 5, 9, 6, 9, 6, 10, 3, 10, 7, 8, 8, 9, 9, 10, 7, 10};
    memset(table, 0, sizeof(table));
    memset(table2, 0, sizeof(table2));
    for (int i = 0; i < 40; i += 2)
    {
      printf("%d %d\n", a[i], a[i + 1]);
      table[a[i] - 1][a[i + 1] - 1] = 1;
      table[a[i + 1] - 1][a[i] - 1] = 1;
    }
    fflush(stdout);

    scanf("%d", &N);
    vector<int> b(40);
    for (int i = 0; i < 40; i += 2)
    {
      scanf("%d%d", &b[i], &b[i + 1]);
      table2[b[i] - 1][b[i + 1] - 1] = 1;
      table2[b[i + 1] - 1][b[i] - 1] = 1;
    }

    vector<int> aa(N);
    for (int i = 0; i < N; ++i)
    {
      aa[i] = i;
    }
    do
    {
      bool ispos = true;
      for (int i = 0; i < 10; ++i)
      {
        if (!ispos) break;
        for (int j = i + 1; j < 10; ++j)
          if (table[i][j] != table2[aa[i]][aa[j]]) { ispos = false; break;}
    }
    if (ispos)
    {
      for (int i = 0; i < N; ++i)
        printf("%d ", aa[i] + 1);
    printf("\n");
    break;
    }
    }
    while (next_permutation(aa.begin(), aa.end()));
	fflush(stdout);
  }
}
