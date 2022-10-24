// by tmt514
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 class Graph {
   public:
     int g[205][205];
     int r[205], c[205];
     int yx[205];
     int u[205];
     int n, ucs, flag;
     Graph(int _flag=0) {
       memset(g, 0, sizeof(g));
       memset(r, 0, sizeof(r));
       memset(c, 0, sizeof(c));
       memset(u, 0, sizeof(u));
       ucs = 0;
       flag = _flag;
     }
     void add(int x, int y) {
       g[x][y] = 1;
       r[x] = 1;
       c[y] = 1;
     }
 
     bool valid(int x, int y) {
       if(!flag) return 1<=x && x<=n && 1<=y && y<=n;
       if((x+y-n)%2) return false;
       int xx = (x+(y-n))/2;
       int yy = (x-(y-n))/2;
       return 1<=xx && xx<=n && 1<=yy && yy<=n;
     }
 
     
     int dfs(int x) {
       u[x] = ucs;
       if(r[x]!=0) return 0;
       for(int i=1;i<=2*n;i++) if(valid(x, i) && yx[i]==-1 && c[i]==0) {
         yx[i] = x;
         return 1;
       }
       for(int i=1;i<=2*n;i++) if(valid(x, i) && c[i]==0 && u[yx[i]]!=ucs && dfs(yx[i])) {
         yx[i] = x;
         return 1;
       }
       return 0;
     }
     int matching(int _n) {
       n = _n;
       int xd=0;
       ++ucs;
       memset(yx, -1, sizeof(yx));
       int ret=0;
       for(int i=1;i<=2*n;i++) {
         if(r[i] == 0 && dfs(i)) {
           ret++;
         }
         ++ucs;
       }
       for(int i=1;i<=2*n;i++) if(yx[i]!=-1 && valid(yx[i], i)) {
         ++xd;
         g[yx[i]][i] = 2;
       }
       if(xd != ret) fprintf(stderr, "WHAAAA");
       return ret;
     }
     
 };
 
 
 void solve() {
   static int cs=0;
   Graph gp(1), gc(0);
   int n, k;
   char a[10];
   char w[105][105];
   scanf("%d%d", &n, &k);
   int ans=0;
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) w[i][j] = '.';
   for(int i=0;i<k;i++) {
     int x, y;
     scanf("%s%d%d", a, &x, &y);
     w[x][y] = a[0];
     if(a[0]=='o' || a[0]=='+') {
       ++ans;
       gp.add(x+y, x-y+n);
     }
     if(a[0]=='o' || a[0]=='x') {
       ++ans;
       gc.add(x, y);
     }
   }
 
   ans += gp.matching(n);
   ans += gc.matching(n);
 
   char v[105][105];
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v[i][j] = gc.g[i][j]? 'x': '.';
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
     if(gp.g[i+j][i-j+n]) {
       if(v[i][j] == '.')
         v[i][j] = '+';
       else
         v[i][j] = 'o';
     }
   }
   int cnt=0;
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(v[i][j] != w[i][j]) ++cnt;
 
   printf("Case #%d: %d %d\n", ++cs, ans, cnt); 
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(v[i][j] != w[i][j]) printf("%c %d %d\n", v[i][j], i, j);
 
 
   int o=0;
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(v[i][j]=='+') ++o; else if(v[i][j]=='x') ++o; else if(v[i][j]=='o') o+=2;
   if(ans != o) fprintf(stderr, "%d: ERROR! %d=%d", cs, o, ans);
 
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=j+1;k<=n;k++) {
     if(v[i][j] != '.' && v[i][k] != '.' && v[i][j] !='+' && v[i][k] != '+') {
       fprintf(stderr, "%d: ERROR!", cs);
     }
     if(v[j][i] != '.' && v[k][i] != '.' && v[j][i] != '+' && v[k][i] != '+') {
       fprintf(stderr, "%d: ERROR!", cs);
     }
   }
 
 
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
