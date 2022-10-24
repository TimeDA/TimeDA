#include<iostream>
 #include<cstdio>
 #include<string>
 #include<cstring>
 
 using namespace std;
 
 const int MAXN = 200;
 const char DC[5] = ">v^<";
 const int DIR[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
 
 int n, m;
 char a[MAXN][MAXN];
 
 void init()
 {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i)
       scanf("%s\n", a[i]);
 }
 
 void solve()
 {
    int ans = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    if (a[i][j] != '.')
    {
       int dx, dy;
       for (int k = 0; k < 4; ++k)
       if (DC[k] == a[i][j])
          dx = DIR[k][0], dy = DIR[k][1];
       int x = i + dx, y = j + dy;
       bool ok = false;
       while (0 <= x && x < n && 0 <= y && y < m)
       {
          if (a[x][y] != '.') {ok = true; break;}
          x += dx, y += dy;
       }
       if (ok) continue;
       for (int k = 0; k < 4; ++k)
       {
          dx = DIR[k][0], dy = DIR[k][1];
          x = i + dx, y = j + dy;
          while (0 <= x && x < n && 0 <= y && y < m)
          {
             if (a[x][y] != '.') {ok = true; break;}
             x += dx, y += dy;
          }
       }
       if (ok) ++ans;
       else { printf("IMPOSSIBLE\n"); return;}
    }
    printf("%d\n", ans);
 }
 
 
 int main()
 {
    int ii, tt;
    scanf("%d", &tt);
    for (ii = 1; ii <= tt; ++ii)
    {
       init();
       printf("Case #%d: ", ii);
       solve();
    }
    return 0;
 }
