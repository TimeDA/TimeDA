#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <sstream>
 #include <iostream>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt, n;
 
 char s[100][100];
 char t[100][100];
 
 int cost[200];
 char chr[] = ".+xo";
 
 set<int> d1, d2, h, v;
 
 int main()
 {
     cost[0] = 0;
     cost[1] = 1;
     cost[2] = 1;
     cost[3] = 2;
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		int m;
 		scanf("%d %d", &n, &m);
 
         for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++) s[i][j] = t[i][j] = 0;
 
         d1.clear();
         d2.clear();
         h.clear();
         v.clear();
         while(m--)
         {
             int x, y;
             char c;
             scanf(" %c %d %d",  &c, &x, &y); x--; y--;
             s[x][y] = t[x][y] = strchr(chr, c) - chr;
 
             if (t[x][y] & 1)
             {
                 d1.insert(x + y);
                 d2.insert(x - y);
             }
 
             if (t[x][y] & 2)
             {
                 h.insert(x);
                 v.insert(y);
             }
         }
 
         for(int d = n; d < n + n; d++)
         {
             for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
             {
                 int dij = 2 * n - abs(i - j) - abs(n - 1 - i - j) - 1;
                 if (dij != d) continue;
                 if (d1.count(i + j) || d2.count(i - j)) continue;
                 t[i][j] ^= 1;
                 d1.insert(i + j);
                 d2.insert(i - j);
             }
         }
 
         for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
         if (!h.count(i) && !v.count(j))
         {
             t[i][j] ^= 2;
             h.insert(i);
             v.insert(j);
         }
 
         int res = 0, changes = 0;
         for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
         {
             res += cost[t[i][j]];
             if (s[i][j] != t[i][j]) changes++;
         }
 
         // printf("%d\n", res);
         printf("%d %d\n", res, changes);
 
         for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
         {
             if (s[i][j] != t[i][j]) printf("%c %d %d\n", chr[t[i][j]], i + 1, j + 1);
         }
 	}
 	return 0;
 }
