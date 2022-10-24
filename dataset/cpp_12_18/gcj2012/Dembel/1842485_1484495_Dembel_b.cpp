#include <cstdio>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <set>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <cstdarg>
 #include <algorithm>
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
     va_list args;
     va_start(args, fmt);
     vfprintf(stderr, fmt, args);
     va_end(args);
 
     fflush(stderr);
     fflush(stdout);
 #endif
 }
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<int,int> pii;
 
 void solve()
 {
     int n, w, l;
     scanf("%d%d%d", &n, &w, &l);
     vector <pii> r(n);
     for (int ii = 0; ii < n; ++ii)
     {
         scanf("%d", &r[ii].first);
         r[ii].second = ii;
     }
     sort(r.begin(), r.end());
     reverse(r.begin(), r.end());
 
     vector <pii> p(n);
     p[r[0].second] = pii(0, 0);
     int i = 1;
     int curX = r[0].first;
     while (i < n && curX + r[i].first <= w)
     {
         curX += r[i].first;
         p[r[i].second] = pii(curX, 0);
         curX += r[i].first;
         ++i;
     }
     int curY = r[0].first;
     while (i < n && curY + r[i].first <= l)
     {
         curY += r[i].first;
         p[r[i].second] = pii(0, curY);
         curY += r[i].first;
         ++i;
     }
 
     for (int i = 0; i < n; ++i)
         printf(" %d %d", p[i].first, p[i].second);
     printf("\n");
 
     if (i != n)
     {
         printf("error. i = %d\n", i);
     }
 }
 
 int main()
 {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
 
     int tt;
     scanf("%d", &tt);
     for (int ii = 0; ii < tt; ++ii)
     {
        printf("Case #%d:", ii + 1);
        solve(); 
     }
 
     return 0;
 }