#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 char a[105][105];
 int p[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
 int dir;
 int r , c;
 int vis[105][105];
 
 void dfs(int x , int y)
 {
     if (vis[x][y] == 1) return;
     vis[x][y] = 1;
 
     if (a[x][y] == '^')
     {
         dir = 0;
     }
     else if (a[x][y] == '>')
     {
         dir = 1;
     }
     else if (a[x][y] == 'v')
     {
         dir = 2;
     }
     else if (a[x][y] == '<')
     {
         dir = 3;
     }
     int xx = x , yy = y;
     while (1)
     {
         xx += p[dir][0];
         yy += p[dir][1];
         if (xx < 0 || xx >= r || yy < 0 || yy >= c)
         {
             vis[x][y] = 2; return;
         }
         if (a[xx][yy] != '.') break;
     }
     dfs(xx , yy);
 }
 int main()
 {
 	freopen("A-small-attempt1.in" , "r" , stdin);
 	freopen("A-small-attempt1.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         
         scanf("%d %d" , &r , &c);
         for (int i = 0; i < r; i ++) scanf("%s" , a[i]);
 
         int x[103] = {0};
         int y[103] = {0};
         for (int i = 0; i < r; i++)
         {
             x[i] = 0;
             for (int j = 0; j < c; j ++) if (a[i][j] != '.') x[i] ++;
         }
         for (int j = 0; j < c; j ++)
         {
             y[j] = 0;
             for (int i = 0; i < r; i ++) if (a[i][j] != '.') y[j] ++;
         }
         int ins = 0;
         for (int i = 0; i < r; i ++)
             if (x[i] == 1)
             {
                 for (int j = 0; j < c; j ++)
                     if (y[j] == 1 && a[i][j] != '.') {ins = 1; break;}
                 if (ins == 1) break;
             }
         if (ins == 1) {printf("IMPOSSIBLE\n"); continue;}
 
         memset(vis , 0 , sizeof(vis));
         for (int i = 0; i < r; i ++)
             for (int j = 0; j < c; j ++)
                 if (a[i][j] != '.' && vis[i][j] == 0)
                 {
                     dfs(i , j);
                 }
         int res = 0;
         for (int i = 0; i < r; i ++)
             for (int j = 0; j < c; j ++)
                 if (vis[i][j] == 2) res ++;
         printf("%d\n" , res);
     }
     return 0;
 }