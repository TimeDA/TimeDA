#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 char s[1005][2];
 int a[1005];
 int ans = 1000, N;
 int u[2005];
 
 void go(int x, int cnt, int frees) {
   if(x == N) {
     ans = min(ans, cnt);
     return;
   }
   if(s[x][0]=='E') {
     if(a[x] == 0) {
       go(x+1, cnt+1, frees+1);
 
       for(int i=0;i<N;i++) if(a[i] && u[a[i]]!=1) {
         int last = u[a[i]];
         u[a[i]] = 1;
         go(x+1, cnt+1, frees);
         u[a[i]] = last;
       }
     } else if(u[a[x]]!=1) {
       int last = u[a[x]];
       u[a[x]] = 1;
       go(x+1, cnt+1, frees);
       u[a[x]] = last;
     }
   } else {
     if(a[x] == 0) {
       go(x+1, cnt-(frees>0), max(0, frees-1));
       
       for(int i=0;i<N;i++) if(a[i] && u[a[i]]!=0) {
         int last = u[a[i]];
         u[a[i]] = 0;
         go(x+1, cnt-(last == 1), frees);
         u[a[i]] = last;
       }
 
     } else if(u[a[x]]!=0) {
       int last = u[a[x]];
       u[a[x]] = 0;
       go(x+1, cnt-(last == 1), frees);
       u[a[x]] = last;
     }
   }
 }
 
 void solve() {
   scanf("%d", &N);
   for(int i=0;i<N;i++) scanf("%s%d", s[i], &a[i]);
   ans = 1000;
   memset(u, -1, sizeof(u));
   go(0, 0, 0);
   if(ans > N) {
     printf("Case #%d: CRIME TIME\n", cs);
     fprintf(stderr, "Case #%d: CRIME TIME\n", cs);
     return;
   } else {
     printf("Case #%d: %d\n", cs, ans);
     fprintf(stderr, "Case #%d: %d\n", cs, ans);
   }
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
