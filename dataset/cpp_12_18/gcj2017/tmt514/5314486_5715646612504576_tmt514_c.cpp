// by tmt514
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <queue>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 
 char a[105][105];
 int ID[105][105];
 int nid=0;
 
 int dx[4]={1, 0, -1, 0};
 int dy[4]={0, -1, 0, 1};
 // D, L, U, R;
 
 int R, C;
 int trace(int x, int y, int f) {
   int tx=x;
   int ty=y;
   while(true) {
     if(x<0 || x>=R || y<0 || y>=C) return 0;
     if(a[x][y]=='-' || a[x][y]=='|') return ID[x][y] + ((f==0 || f==2)? 1 : 0);
     if(a[x][y]=='#') return 0;
     if(a[x][y]=='/') {
       if(f==0) f=1;
       else if(f==1) f=0;
       else if(f==2) f=3;
       else if(f==3) f=2;
     }
     if(a[x][y]=='\\') {
       if(f==0) f=3;
       else if(f==3) f=0;
       else if(f==1) f=2;
       else if(f==2) f=1;
     }
     x+=dx[f];
     y+=dy[f];
     if(x==tx && y==ty) {
       // cycle
       return 0;
     }
   }
 }
 
 void solve() {
   static int cs = 0;
   scanf("%d%d", &R, &C);
   nid = 0;
   for(int i=0;i<R;i++) scanf("%s", a[i]);
   for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
     if(a[i][j]=='-'|| a[i][j]=='|') {
       a[i][j]='|';
       nid += 2;
       ID[i][j] = nid;
     }
   }
   
   int must[305]={};
   int g[305][305]={};
   for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
     if(a[i][j]=='.') {
 
       int x = i, y = j;
       // D, L, U, R
       int gL=trace(x, y-1, 1);
       int gR=trace(x, y+1, 3);
       int gU=trace(x-1, y, 2);
       int gD=trace(x+1, y, 0);
 
 
       int c1 = 0, c2 = 0;
       if((gL!=0 && gR==0) || (gL==0 && gR!=0)) c1 = gL+gR;
       if((gU!=0 && gD==0) || (gU==0 && gD!=0)) c2 = gU+gD;
       if(c1==0 && c2==0) {
         printf("Case #%d: IMPOSSIBLE\n", ++cs);
         fprintf(stderr, "Case #%d: IMPOSSIBLE\n", cs);
         return ;
       }
       if(c1==0 && c2!=0) must[c2]=1;
       if(c2==0 && c1!=0) must[c1]=1;
       if(c1!=0 && c2!=0) {
         g[c1^1][c2] = 1;
         g[c2^1][c1] = 1;
       }
     } else if (a[i][j]=='-' || a[i][j]=='|') {
       int x = i, y = j;
       // D, L, U, R
       int gL=trace(x, y-1, 1);
       int gR=trace(x, y+1, 3);
       int gU=trace(x-1, y, 2);
       int gD=trace(x+1, y, 0);
 
       int c1 = 0, c2 = 0;
       if(gL==0 && gR==0) c1 = ID[i][j];
       if(gU==0 && gD==0) c2 = ID[i][j]+1;
       if(c1==0 && c2==0) {
         printf("Case #%d: IMPOSSIBLE\n", ++cs);
         fprintf(stderr, "Case #%d: IMPOSSIBLE\n", cs);
         return ;
       }
       if(c1==0 && c2!=0) must[c2]=1;
       if(c2==0 && c1!=0) must[c1]=1;
       /*if(c1!=0 && c2!=0) {
         g[c1^1][c2] = 1;
         g[c2^1][c1] = 1;
       }*/
 
     }
   }
   for(int k=2;k<=nid+1;k++)
     for(int i=2;i<=nid+1;i++)
       for(int j=2;j<=nid+1;j++)
         if(g[i][k] && g[k][j]) g[i][j] = 1;
   for(int i=2;i<=nid+1;i++)
     if((must[i] && g[i][i^1]) || (must[i] && must[i^1])) {
       printf("Case #%d: IMPOSSIBLE\n", ++cs);
       fprintf(stderr, "Case #%d: IMPOSSIBLE\n", cs);
       return ;
     }
 
   queue<int> q;
   
   for(int i=2;i<=nid+1;i++) if(must[i]==1) must[i^1] = -1;
   for(int i=2;i<=nid+1;i++) {
     if(must[i]!=0) q.push(i);
   }
 
 
   while(true) {
     
     while(!q.empty()) {
       int x = q.front();
       q.pop();
       if(must[x]==1) {
         for(int y=nid;y<=nid+1;y++)
           if(g[x][y] && must[y]==0) {
             must[y] = 1;
             must[y^1] = -1;
             q.push(y);
             q.push(y^1);
           }
       } else if (must[x] == -1) {
         for(int y=nid;y<=nid+1;y++)
           if(g[y][x] && must[y]==0) {
             must[y] = -1;
             must[y^1] = 1;
             q.push(y);
             q.push(y^1);
           }
       }
     }
     int finish=1;
     for(int i=2;i<=nid+1;i++)
       if(must[i]==0) {
         must[i] = 1;
         must[i^1] = -1;
         q.push(i);
         q.push(i^1);
         finish=0;
         break;
       }
     if(finish) break; 
   }
 
   for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
     if(a[i][j]=='-' || a[i][j]=='|') {
       if(must[ID[i][j]] == 1) a[i][j] = '-';
       else a[i][j] = '|';
     }
   } 
   
   printf("Case #%d: POSSIBLE\n", ++cs);
   fprintf(stderr, "Case #%d: POSSIBLE\n", cs);
   for(int i=0;i<R;i++,puts(""))
     for(int j=0;j<C;j++)
       printf("%c", a[i][j]);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
