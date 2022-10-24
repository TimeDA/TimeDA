#include <cstdio>
 #include <map>
 #include <memory.h>
 using namespace std;
 
 const int N = 2050;
 
 int st[N];
 
 int id[N];
 char T[N];
 
 int n, pt;
 
 int ans;
 
 void go(int i, int o)
 {
     if (i == n)
     {
         int cur = 0;
         for (int j = 1; j <= pt; j++)
             cur += st[j] == 1;
         cur += o;
         ans = min(ans, cur);
         return;
     }
     if (T[i] == 'E')
     {
         if (id[i] == 0)
         {
             for (int j = 1; j <= pt; j++)
                 if (st[j] != 1)
                 {
                     int old = st[j];
                     st[j] = 1;
                     go(i + 1, o);
                     st[j] = old;
                 }
             go(i + 1, o + 1);
         }
         else
         {
             if (st[id[i]] == 1)
                 return;
             else
             {
                 int old = st[id[i]];
                 st[id[i]] = 1;
                 go(i + 1, o);
                 st[id[i]] = old;
             }
         }
     }
     else
     {
         if (id[i] == 0)
         {
             for (int j = 1; j <= pt; j++)
             {
                 if (st[j] != 0)
                 {
                     int old = st[j];
                     st[j] = 0;
                     go(i + 1, o);
                     st[j] = old;
                 }
             }
             go(i + 1, max(0, o - 1));
         }
         else
         {
             if (st[id[i]] == 0)
                 return;
             else
             {
                 int old = st[id[i]];
                 st[id[i]] = 0;
                 go(i + 1, o);
                 st[id[i]] = old;
             }
         }
     }
 }
 
 void solve(int cs)
 {
     memset(st, -1, sizeof(st));
     scanf("%d", &n);
     map<int, int> M;
     ans = 100000;
     for (int i = 0; i < n; i++)
     {
         char t;
         int x;
         scanf(" %c %d", &t, &x);
         T[i] = t, id[i] = x;
         if (x) M[x];
     }
     pt = 0;
     for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
         it->second = ++pt;
     for (int i = 0; i < n; i++)
         if (id[i])
             id[i] = M[id[i]];
     go(0, 0);
     if (ans >= 100000)
         printf("Case #%d: CRIME TIME\n", cs);
     else
         printf("Case #%d: %d\n", cs, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
     {
         solve(i + 1);
         fflush(stdout);
     }
 
 }
