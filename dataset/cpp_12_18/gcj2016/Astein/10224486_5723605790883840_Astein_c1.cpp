#include <cstdio>
 #include <algorithm>
 
 using namespace std;
 
 char table[17][17];
 int a[205];
 char pics[66][66];
 int R, C;
 
 pair<int, int> getPos(int v)
 {
   if (v <= C)
     return make_pair(0, 4 * (v - 1) + 2);
   if (v <= R + C)
     return make_pair(4 * (v - C - 1) + 2, 4 * C);
   if (v <= C + R + C)
     return make_pair(4 * R, 4 * (C + R + C - v) + 2);
 
   return make_pair(4 * (C + R + C + R - v) + 2, 0);
 }
 
 int dx[4] = {-1, 0, 1, 0};
 int dy[4] = {0, 1, 0, -1};
 int slash[4] = {1, 0, 3, 2};
 int backsl[4] = {3, 2, 1, 0};
 
 pair<int, int> makeRay(int x, int y, int dir)
 {
   while (true)
   {
     x = x + dx[dir];
     y = y + dy[dir];
     if (pics[x][y] == '/')
       dir = slash[dir];
     if (pics[x][y] == '\\')
       dir = backsl[dir];
     if (x == 0 || y == 0 || x == 4 * R || y == 4 * C)
       break;
   }
   return make_pair(x, y);
 }
 
 bool found;
 
 void backtr(int x, int y)
 {
   if (found) return;
   if (x == R)
   {
     bool ispos = true;
     for (int i = 0; i < 2 * (R + C); i += 2)
     {
       pair<int, int> gp = getPos(a[i]);
       int initd = 0;
       if (gp.first == 0) initd = 2;
       if (gp.second == 4 * C) initd = 3;
       if (gp.first == 4 * R) initd = 0;
       if (gp.second == 0) initd = 1;
 
       pair<int, int> dest = makeRay(gp.first, gp.second, initd);
       pair<int, int> gp2 = getPos(a[i + 1]);
       if (dest.first == gp2.first && dest.second == gp2.second) ; else ispos = false;
     }
     if (ispos)
     {
       for (int i = 0; i < R; ++i)
       {
         for (int j = 0; j < C; ++j)
           printf("%c", pics[4 * i + 2][4 * j + 2]);
         printf("\n");
       }
       found = true;
     }
     return;
   }
   pics[4 * x + 2][4 * y + 2] = '/';
   if (y != C - 1)
     backtr(x, y + 1);
   else
     backtr(x + 1, 0);
 
   pics[4 * x + 2][4 * y + 2] = '\\';
   if (y != C - 1)
     backtr(x, y + 1);
   else
     backtr(x + 1, 0);
 }
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     scanf("%d%d", &R, &C);
     for (int i = 0; i < 2 * (R + C); ++i)
     {
       scanf("%d", &a[i]);
     }
     for (int i = 0; i <= 4 * R; ++i)
     {
       for (int j = 0; j <= 4 * C; ++j)
         pics[i][j] = '*';
       pics[i][4 * C + 1] = 0;
     }
     found = false;
     printf("Case #%d:\n", cn);
     backtr(0, 0);
     if (!found)
       printf("IMPOSSIBLE\n");
   }
 }
