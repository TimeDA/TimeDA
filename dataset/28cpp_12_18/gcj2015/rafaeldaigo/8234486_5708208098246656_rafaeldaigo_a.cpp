#include<cstdio>
 #include<cstdlib>
 #include<vector>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 char table[110][110];
 int dx[4] = {0, 1, 0, -1};
 int dy[4] = {1, 0, -1, 0};
 char d[5] = ">v<^";
 
 int main()
 {
     int t, test;
     scanf("%d", &test);
     for (t = 0; t < test; t++)
     {
         int r, c;
         scanf("%d %d", &r, &c);
         for (int i = 0 ; i < r; i++)
         {
             scanf("%s", table[i]);
         }
         int resp = 0;
         bool impossible = false;
         for (int i = 0; i < r && impossible == false; i++)
         {
             for (int j = 0; j < c && impossible == false; j++)
             {
                 if (table[i][j] == '.')
                     continue;
                 int cost = 1000;
                 for (int a = 0; a < 4; a++)
                 {
                     int x = i + dx[a];
                     int y = j + dy[a];
                     while(x >= 0 && x < r && y >= 0 && y < c)
                     {
                         if (table[x][y] != '.')
                         {
                             int cand = (table[i][j] == d[a]) ? 0 : 1;
                             cost = min(cost, cand);
                             break;
                         }
                         x += dx[a];
                         y += dy[a];
                     }
                 }
                 if (cost >= 1000)
                 {
                     impossible = true;
                 }
                 else
                 {
                     resp += cost;
                 }
             }
         }
 
         if (impossible)
             printf("Case #%d: IMPOSSIBLE\n", t+1);
         else
             printf("Case #%d: %d\n", t+1, resp);
     }
     return 0;
 }
