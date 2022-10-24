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
     int n, D;
     scanf("%d", &n);
     vector<int> d(n), l(n);
     for (int i = 0; i < n; ++i)
         scanf("%d%d", &d[i], &l[i]);
     scanf("%d", &D);
     d.push_back(D);
     l.push_back(D);
 
     vector<int> used(n + 1);
     used[0] = d[0];
     for (int i = 1; i <= n; ++i)
     {
         used[i] = -1;
         for (int j = 0; j < i; ++j)
         {
             if (d[i] <= d[j] + used[j])
                 used[i] = max(used[i], min(l[i], d[i] - d[j]));
         }
 //        dbg("used[%d] = %d\n", i, used[i]);
     }
     printf("%s\n", used[n] != -1 ? "YES" : "NO"); 
 }
 
 int main()
 {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
 
     int tt;
     scanf("%d", &tt);
     for (int ii = 0; ii < tt; ++ii)
     {
        printf("Case #%d: ", ii + 1);
        solve(); 
     }
 
     return 0;
 }