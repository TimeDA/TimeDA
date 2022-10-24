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
 
 int cs=0;
 int R, C;
 int a[555];
 
 int b[105][105];
 int target[555], current[555];
 
 bool crossing(int p, int q, int r, int s) {
   if(p>q) swap(p, q);
   if(r>s) swap(r, s);
   if(p>r) { swap(p, r); swap(q, s); }
   return p<r && r<q && q<s;
 }
 
 const int UP=0, RIGHT=1, DOWN=2, LEFT=3;
 const int dx[4]={-1, 0, 1, 0};
 const int dy[4]={0, 1, 0, -1};
 int cur[105][105][4];
 bool inside(int x, int y) {
   return x>=1 && x<=R && y>=1 && y<=C;
 }
 
 void trace(int x, int y, int face, int id) {
   while (inside(x, y) || b[x][y] == id) {
     cur[x][y][face] = id;
     x += dx[face];
     y += dy[face];
     face=(face+2)%4;
     if (b[x][y] == 0) {
       if(face==UP) face=LEFT;
       else if(face==LEFT) face=UP;
       else if(face==DOWN) face=RIGHT;
       else if(face==RIGHT) face=DOWN;
     } else {
       if(face==UP) face=RIGHT;
       else if(face==RIGHT) face=UP;
       else if(face==DOWN) face=LEFT;
       else if(face==LEFT) face=DOWN;
     }
   }
   current[id] = b[x][y];
   //printf("%d <=> %d\n", id, b[x][y]);
 }
 void build() {
   memset(cur, 0, sizeof(cur));
   target[0] = -1;
   for(int i=1;i<=C;i++) trace(0, i, DOWN, i);
   for(int i=1;i<=R;i++) trace(i, C+1, LEFT, C+i);
   for(int i=1;i<=C;i++) trace(R+1, C+1-i, UP, R+C+i);
   for(int i=1;i<=R;i++) trace(R+1-i, 0, RIGHT, C+R+C+i);
 
 /*  printf("current= ");
   for(int i=1;i<=2*(R+C);i++) printf("(%d->%d) ", i, current[i]);
   puts("");*/
 }
 
 int dist() {
   int mismatch=0;
   for(int i=1;i<=R+C+R+C;i++) if(current[i] != target[i]) ++mismatch;
   return mismatch;
 }
 
 bool swap_is_better(int i, int j) {
   int now=0, after=0;
 
     now += (target[cur[i][j][UP]] == cur[i][j][LEFT]) + (target[cur[i][j][DOWN]] == cur[i][j][RIGHT])
          + (target[cur[i][j][LEFT]] == cur[i][j][UP]) + (target[cur[i][j][RIGHT]] == cur[i][j][DOWN]);
     after += (target[cur[i][j][UP]] == cur[i][j][RIGHT]) + (target[cur[i][j][DOWN]] == cur[i][j][LEFT])
          + (target[cur[i][j][RIGHT]] == cur[i][j][UP]) + (target[cur[i][j][LEFT]] == cur[i][j][DOWN]);
 
   if (cur[i][j][UP] == cur[i][j][DOWN]) return true;
   
   if (b[i][j]) swap(now, after);
 //  printf("i=%d, j=%d; now=%d, after=%d; ", i, j, now, after);
 //  printf("up=%d, left=%d, right=%d, down=%d\n", cur[i][j][UP], cur[i][j][LEFT], cur[i][j][RIGHT], cur[i][j][DOWN]);
   return (now < after);
 }
 
 void solve() {
   ++cs;
   fprintf(stderr, "Case #%d: ", cs);
   printf("Case #%d: ", cs);
 
   scanf("%d%d", &R, &C);
   for(int i=0;i<2*(R+C);i++) scanf("%d", &a[i]);
   for(int i=0;i<2*(R+C);i+=2)
     for(int j=i+2;j<2*(R+C);j+=2) {
       if (crossing(a[i], a[i+1], a[j], a[j+1])) {
         printf("\nIMPOSSIBLE\n");
         fprintf(stderr, "IMPOSSIBLE\n");
         return;
       }
     }
 
   for(int i=0;i<2*(R+C);i++) target[a[i]] = a[i^1];
 
   memset(b, 0, sizeof(b));
   for(int i=1;i<=C;i++) b[0][i] = i;
   for(int i=1;i<=R;i++) b[i][C+1] = C+i;
   for(int i=1;i<=C;i++) b[R+1][C+1-i] = R+C+i;
   for(int i=1;i<=R;i++) b[R+1-i][0] = C+R+C+i;
   
   int d=100;
   for(int i=0;i<(1<<(R*C));i++) {
     for(int j=0;j<R*C;j++) {
       int x = j/C+1, y = j%C+1;
       b[x][y] = ((i&(1<<j))? 1: 0);
     }
     build();
     if((d=dist()) == 0) 
       break;
   }
 /*
   int d = dist();
   int change=1;
   while (change) {
     change = 0;
     for(int i=1;i<=R;i++)
       for(int j=1;j<=C;j++) {
         if(swap_is_better(i, j)) {
           b[i][j] ^= 1;
           change=1;
           goto Done;
         }
       }
 
 Done:
     if (change) build();
     d = dist();
   }
   */
 
   if (d != 0) {
     printf("\nIMPOSSIBLE\n");
     fprintf(stderr, "IMPOSSIBLE\n");
   } else {
     printf("\n");
     for(int i=1;i<=R;i++,puts(""))
       for(int j=1;j<=C;j++)
         if(b[i][j] == 0) putchar('/');
         else putchar('\\');
     fprintf(stderr, "OK\n");
   }
 }
 
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();  
   return 0;
 }
