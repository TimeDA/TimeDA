#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 template<typename T>
 using pair2 = pair<T, T>;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 #define set set_sdklf
 
 const int maxn = 55;
 const int maxbeams = 105;
 
 char p[maxn][maxn];
 int id[maxn][maxn];
 vector<pair2<int>> beamers;
 int ans[maxbeams];
 bool was[2 * maxbeams];
 bool isset[maxbeams], needset[maxbeams];
 bool whatset[maxbeams][2];
 vector<int> order;
 int color[2 * maxbeams];
 vector<int> gr[2 * maxbeams], grr[2 * maxbeams];
 int n, m;
 bool poss;
 
 void set(int id, int t)
 {
     needset[id] = true;
     whatset[id][t] = true;
 }
 
 void applyset(int cur)
 {
     if (isset[cur / 2])
     {
         if (cur != (cur / 2) * 2 + ans[cur / 2])
         {
             poss = false;
         }
         return;
     }
     isset[cur / 2] = true;
     if (needset[cur / 2] && whatset[cur / 2][1 - cur % 2])
     {
         poss = false;
         return;
     }
     ans[cur / 2] = cur % 2;
     for (auto t : gr[cur]) applyset(t);
 }
 
 void toorder(int cur)
 {
     if (was[cur]) return;
     was[cur] = true;
     for (auto t : gr[cur]) toorder(t);
     order.pb(cur);
 }
 
 void ccolor(int cur, int curc)
 {
     if (was[cur]) return;
     was[cur] = true;
     color[cur] = curc;
     for (auto t : grr[cur]) ccolor(t, curc);
 }
 
 void adde(int i1, int t1, int i2, int t2)
 {
     gr[i1 * 2 + (1 - t1)].pb(i2 * 2 + t2);
     gr[i2 * 2 + (1 - t2)].pb(i1 * 2 + t1);
 }
 
 const int dx[4] = {-1, 0, 1, 0};
 const int dy[4] = {0, 1, 0, -1};
 
 pair<int, int> findend(int cx, int cy, int cd, int cturns = 0)
 {
     if (cx < 0 || cy < 0 || cx >= n || cy >= m) return {-1, -1};
     if (p[cx][cy] == '#') return {-1, -1};
     if (p[cx][cy] == '-') return {id[cx][cy], cturns};
     if (p[cx][cy] == '\\')
     {
         int nd = (2 + (cd ^ 1)) % 4;
         return findend(cx + dx[nd], cy + dy[nd], nd, 1 - cturns);
     }
     if (p[cx][cy] == '/')
     {
         int nd = (2 + (cd ^ 3)) % 4;
         return findend(cx + dx[nd], cy + dy[nd], nd, 1 - cturns);
     }
     return findend(cx + dx[cd], cy + dy[cd], cd, cturns);
 }
 
 int check(int cx, int cy, int cd, int cturns = 0)
 {
     if (cx < 0 || cy < 0 || cx >= n || cy >= m) return 0;
 //     cout << "check " << cx << ' ' << cy << ' ' << cd << ' ' << cturns << ' ' << p[cx][cy] << endl;
     if (p[cx][cy] == '#') return 0;
     if (p[cx][cy] == '-') return cturns == 0;
     if (p[cx][cy] == '|') return cturns == 1;
     if (p[cx][cy] == '\\')
     {
         int nd = (2 + (cd ^ 1)) % 4;
         return check(cx + dx[nd], cy + dy[nd], nd, 1 - cturns);
     }
     if (p[cx][cy] == '/')
     {
         int nd = (2 + (cd ^ 3)) % 4;
         return check(cx + dx[nd], cy + dy[nd], nd, 1 - cturns);
     }
     return check(cx + dx[cd], cy + dy[cd], cd, cturns);
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
         scanf("%d%d", &n, &m);
         beamers.resize(0);
         for (int i = 0; i < n; i++)
         {
             scanf("%s", p[i]);
             for (int j = 0; j < m; j++)
             {
                 if (p[i][j] == '|') p[i][j] = '-';
                 if (p[i][j] == '-')
                 {
                     id[i][j] = beamers.size();
                     beamers.pb({i, j});
                 }
             }
         }
         poss = true;
         for (int i = 0; i < (int)beamers.size(); i++)
         {
             isset[i] = false;
             needset[i] = false;
             whatset[i][0] = false;
             whatset[i][1] = false;
         }
         for (int i = 0; i < (int)beamers.size(); i++)
         {
             auto t = beamers[i];
             int toup = findend(t.fi - 1, t.se, 0).fi;
             int toright = findend(t.fi, t.se + 1, 1).fi;
             int todown = findend(t.fi + 1, t.se, 2).fi;
             int toleft = findend(t.fi, t.se - 1, 3).fi;
             if ((toup != -1 || todown != -1) && (toright != -1 || toleft != -1))
             {
                 poss = false;
                 break;
             }
             isset[i] = false;
             if (toup != -1 || todown != -1)
             {
                 set(i, 0);
             }
             if (toleft != -1 || toright != -1)
             {
                 set(i, 1);
             }
         }
         if (!poss)
         {
             printf("IMPOSSIBLE\n");
             continue;
         }
         int k = 2 * (int)beamers.size();
         for (int i = 0; i < k; i++) gr[i].clear(), grr[i].clear();
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++) if (p[i][j] == '.')
             {
                 auto toup = findend(i, j, 0);
                 auto toright = findend(i, j, 1);
                 auto todown = findend(i, j, 2);
                 auto toleft = findend(i, j, 3);
 //                 cout << i << ' ' << j << ' ' << toleft.fi << ' ' << toright.fi << endl;
                 if (toup.fi >= 0 && todown.fi >= 0)
                 {
                     toup.fi = -1;
                     todown.fi = -1;
                 }
                 if (toleft.fi >= 0 && toright.fi >= 0)
                 {
                     toleft.fi = -1;
                     toright.fi = -1;
                 }
                 toup = max(toup, todown);
                 toleft = max(toleft, toright);
                 if (toup.fi == -1 && toleft.fi == -1)
                 {
                     poss = false;
                     continue;
                 }
                 if (toup.fi == -1)
                 {
                     set(toleft.fi, toleft.se);
                 } else if (toleft.fi == -1)
                 {
                     set(toup.fi, 1 - toup.se);
                 } else adde(toleft.fi, toleft.se, toup.fi, 1 - toup.se);
             }
         }
         for (int i = 0; i < k / 2; i++) if (needset[i] && !isset[i])
         {
             if (whatset[i][0] && whatset[i][1])
             {
                 poss = false;
                 break;
             }
             if (whatset[i][0]) applyset(i * 2);
             else applyset(i * 2 + 1);
         }
         if (!poss)
         {
             printf("IMPOSSIBLE\n");
             continue;
         }
         for (int i = 0; i < k; i++) was[i] = false;
         order.resize(0);
         for (int i = 0; i < k; i++) if (!was[i] && !isset[i / 2]) toorder(i);
         reverse(all(order));
         for (int i = 0; i < k; i++) was[i] = false;
         int ccomp = 0;
         for (auto t : order) if (!was[t] && !isset[t / 2])
         {
             ccolor(t, ccomp++);
         }
         for (int i = 0; i < (int)beamers.size(); i++) if (!isset[i])
         {
             if (color[2 * i] == color[2 * i + 1]) poss = false;
             else if (color[2 * i] < color[2 * i + 1])
             {
                 ans[i] = 1;
             } else ans[i] = 0;
         }
         if (!poss)
         {
             printf("IMPOSSIBLE\n");
             continue;
         }
         for (int i = 0; i < (int)beamers.size(); i++)
         {
             auto t = beamers[i];
             if (ans[i] == 1) p[t.fi][t.se] = '|';
             else p[t.fi][t.se] = '-';
         }
         printf("POSSIBLE\n");
         for (int i = 0; i <n ; i++)
         {
             printf("%s\n", p[i]);
         }
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++)
             {
                 if (p[i][j] == '.')
                 {
 //                     cout << (check(i, j, 0, 1)) + (check(i, j, 1)) + (check(i, j, 2, 1)) + (check(i, j, 3)) << endl;
                     assert((check(i, j, 0, 1)) + (check(i, j, 1)) + (check(i, j, 2, 1)) + (check(i, j, 3)) >= 1);
                 }
                 if (p[i][j] == '-') assert(check(i, j - 1, 3) == 0 && check(i, j + 1, 1) == 0);
                 if (p[i][j] == '|') assert(check(i - 1, j, 0, 1) == 0 && check(i + 1, j, 2, 1) == 0);
             }
         }
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
