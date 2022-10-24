#include <iostream>
 #include <memory.h>
 #include <vector>
 #include <cstdio>
 using namespace std;
 
 const int N = 101;
 
 int was[N][N];
 
 int s;
 bool good(int a, int b)
 {
     return a >= 1 && a < 2 * s && b >= 1 && b < 2 * s && abs(a - b) < s;
 }
 
 int vi[] = {-1, 0, 1, 1, 0, -1};
 int vj[] = {-1, -1, 0, 1, 1, 0};
 
 int iter = 0;
 
 int Q[N][N];
 
 int DFS(int i, int j, int q)
 {
     if (Q[i][j] != q || was[i][j] == iter)
         return 0;
     was[i][j] = iter;
     int ans = 1;
     for (int v = 0; v < 6; v++)
     {
         int ti = i + vi[v];
         int tj = j + vj[v];
         if (good(ti, tj) && was[ti][tj] != iter && Q[ti][tj] == q)
             ans += DFS(ti, tj, q);
     }
     return ans;
 }
 
 int sDFS(int i, int j, int q)
 {
     return DFS(i, j, q);
 }
 
 void solve(int Case)
 {
     memset(Q, 0, sizeof(Q));
     memset(was, 0, sizeof(was));
     iter = 0;
     int m;
 
     scanf("%d %d", &s, &m);
     vector<pair<int, int> > edge;
     #define mp make_pair
     vector<pair<int, int> > corn = {
         mp(1, 1),
         mp(1, s),
         mp(s, 1),
         mp(2 * s - 1, s),
         mp(s, 2 * s - 1),
         mp(2 * s - 1, 2 * s - 1)
     };
     for (int i = 1; i < s - 1; i++)
     {
         edge.push_back(mp(i + 1, 1));
         edge.push_back(mp(1, i + 1));
         edge.push_back(mp(i + 1, i + s));
         edge.push_back(mp(i + s, i + 1));
         edge.push_back(mp(2 * s - 1, i + s));
         edge.push_back(mp(i + s, 2 * s - 1));
     }
     bool fin = false;
     cout << "Case #" << Case << ": ";
     for (int t = 0; t < m; t++)
     {
         int a, b;
         scanf("%d %d", &a, &b);
         Q[a][b] = 1;
         if (fin)
             continue;
         ++iter;
         bool isbridge = false;
         for (pair<int, int> p : corn)
         {
             if (was[p.first][p.second] == iter)
                 isbridge = true;
             sDFS(p.first, p.second, 1);
         }
         bool isfork = false;
         for (pair<int, int> p : edge)
         {
             ++iter;
             sDFS(p.first, p.second, 1);
             bool type[6];
             memset(type, 0, sizeof(type));
             for (int i = 0; i < edge.size(); i++)
             {
                 if (was[edge[i].first][edge[i].second] == iter)
                     type[i % 6] = 1;
             }
             int cnt = 0;
             for (int i = 0; i < 6; i++)
                 cnt += type[i];
             if (cnt >= 3)
                 isfork = true;
         }
         ++iter;
 
         bool isring = false;
         for (int i = 1; i <= 2 * s; i++)
             for (int j = 1; j <= 2 * s; j++)
                 if (good(i, j) && !Q[i][j] && was[i][j] != iter)
                 {
                     iter++;
                     sDFS(i, j, 0);
                     bool gd = 0;
                     for (auto p : corn)
                         gd |= was[p.first][p.second] == iter;
                     for (auto p : edge)
                         gd |= was[p.first][p.second] == iter;
                     if (!gd)
                         isring = true;
                 }
         next:;
         if (isring || isfork || isbridge)
         {
             string res;
             if (isbridge)
                 res += "bridge-";
             if (isfork)
                 res += "fork-";
             if (isring)
                 res += "ring-";
             res.resize(res.size() - 1);
             cout << res << " in move " << t + 1 << endl;
             fin = true;
         }
     }
     if (!fin)
         cout << "none" << endl;
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
