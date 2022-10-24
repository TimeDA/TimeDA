#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <cassert>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 int a[2005][2005];
 int c[2005][2005];
 bool u[2005][2005];
 
 int xabs(int x) { return x<0? -x: x; }
 
 int W, H, B, m, n;
 int q[2005][4];
 int qh[2005];
 int chk(int x, int y, int xu, int yu) {
   if(x>=0&&y>=0&&a[x][y]) return true;
   if(xu>=0&&yu>=0&&a[xu][yu]) return true;
   return false;
 }
 void solve() {
   deque<int> Q;
   scanf("%d%d%d", &W, &H, &B);
   memset(qh, 0, sizeof(qh));
   n = 0;
   for(int i=0;i<B;i++) {
     scanf("%d%d%d%d", &q[i][0], &q[i][1], &q[i][2], &q[i][3]);
     q[i][2]++; q[i][3]++;
     qh[n++] = q[i][1];
     qh[n++] = q[i][3];
   }
   qh[n++] = 0;
   qh[n++] = H;
   sort(qh, qh+n);
   
   
   for(int i=0;i<=H;i++) qh[i] = i;
   n = H+1;
 
   n = unique(qh, qh+n) - qh - 1;
   m = W;
   memset(a, 0, sizeof(a));
   for(int i=0;i<B;i++) {
     int xl = q[i][0], yl = lower_bound(qh, qh+n+1, q[i][1]) - qh;
     int xr = q[i][2], yr = lower_bound(qh, qh+n+1, q[i][3]) - qh;
     for(int x=xl;x<xr;x++)
       for(int y=yl;y<yr;y++)
         a[x][y] = 1;
   }
   memset(c, -1, sizeof(c));
   for(int j=0;j<=n;j++) {
     c[0][j] = 0;
     Q.push_back(0);
     Q.push_back(j);
     //c[j][0] = 0;
     //Q.push_back(j); Q.push_back(0);
   }
   const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
   const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
     while(!Q.empty()) {
       int x = Q.front(); Q.pop_front();
       int y = Q.front(); Q.pop_front();
       int d = c[x][y];
       assert(d >= 0);
       //printf("x=%d, y=%d, d=%d\n", x, y, d);
       for(int f=0;f<8;f++) {
         int nx = x + dx[f];
         int ny = y + dy[f];
         if(nx<0||nx>m||ny<0||ny>n) continue;
         int nd = d + (f==1||f==3? 1 : xabs((int)(qh[y]-qh[ny])));
         if(f==0 && chk(x, y, x-1, y)) nd = d;
         if(f==1 && chk(x, y, x, y-1)) nd = d;
         if(f==2 && chk(x, y-1, x-1, y-1)) nd = d;
         if(f==3 && chk(x-1, y-1, x-1, y)) nd = d;
         if(f==4 && chk(x, y, x, y)) nd = d;
         if(f==5 && chk(x, y-1, x, y-1)) nd = d;
         if(f==6 && chk(x-1, y, x-1, y)) nd = d;
         if(f==7 && chk(x-1, y-1, x-1, y-1)) nd = d;
         //printf(">>>>> %d %d %d\n", nx, ny, nd);
         if((c[nx][ny] > nd || c[nx][ny] == -1)) {
           c[nx][ny] = nd;
           if(nd > d) {
             Q.push_back(nx);
             Q.push_back(ny);
           } else {
             Q.push_front(ny);
             Q.push_front(nx);
           }
         }
       }
     
   }
   int ans = -1;
   //for(int i=0;i<=W;i++) if(c[i][n] > -1 && (ans == -1 || ans > c[i][n])) ans = c[i][n];
   for(int i=0;i<=n;i++) if(c[m][i] > -1 && (ans == -1 || ans > c[m][i])) ans = c[m][i];
   //for(int i=0;i<=m;i++,puts("")) for(int j=0;j<=n;j++) printf("%d ", c[i][j]);
   printf("Case #%d: %d\n", cs, ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
