#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cassert>
 using namespace std;
 
 const int R = 0, U = 1, L = 2, D = 3;
 
 int vx[] = {1, 0, -1, 0};
 int vy[] = {0, -1, 0, 1};
 
 const int N = 405;
 
 char F[N][N];
 
 int curver = 0;
 int ver[N][N];
 
 int var_[4][N][N];
 
 int var(int dir, int y, int x) {
     int v = dir;
     int& res = var_[v][y][x];
     if (res != -2)
         return res;
     if (F[y][x] == '#') {
         return -1;
     }
     if (F[y][x] == '|' || F[y][x] == '-') {
         res = 2 * ver[y][x] + (v & 1);
     }
     if (F[y][x] == '.') {
         res = var(v, y + vy[v], x + vx[v]);
     }
     if (F[y][x] == '/') {
         int nv = v ^ 1;
         res = var(nv, y + vy[nv], x + vx[nv]);
     }
     if (F[y][x] == '\\') {
         int nv = v ^ 3;
         res = var(nv, y + vy[nv], x + vx[nv]);
     }
     assert(res != -2);
     return res;
 }
 
 vector<int> E[N];
 vector<int> RE[N];
 
 void add_edge(int x, int y) {
     E[x].push_back(y);
     RE[y].push_back(x);
 }
 
 void add_disj(int x, int y) {
     add_edge(x ^ 1, y);
     add_edge(y ^ 1, x);
 }
 
 void add_eq(int x) {
     add_edge(x ^ 1, x);
 }
 
 int any(int a, int b) {
     assert(a == -1 || b == -1);
     return (a == -1) ? b : a;
 }
 
 bool was[N];
 int col[N];
 int posy[N], posx[N];
 vector<int> topsort;
 
 void DFS(int x) {
     was[x] = true;
     for (int y : E[x]) {
         if (!was[y])
             DFS(y);
     }
     topsort.push_back(x);
 }
 
 void DFS2(int x, int c) {
     was[x] = true;
     col[x] = c;
     for (int y : RE[x]) {
         if (!was[y])
             DFS2(y, c);
     }
 }
 
 void check2sat() {
     topsort.clear();
     for (int i = 0; i < 2 * curver; i++) {
         was[i] = false;
     }
     for (int i = 0; i < 2 * curver; i++) {
         if (!was[i])
             DFS(i);
     }
     reverse(topsort.begin(), topsort.end());
     int curcol = 0;
     for (int i = 0; i < 2 * curver; i++) {
         was[i] = false;
     }
     for (int i : topsort) {
         if (!was[i]) {
             DFS2(i, curcol++);
         }
     }
 }
 
 void solve(int cs) {
     int r, c;
     scanf("%d %d", &r, &c);
     for (int i = 1; i <= r; i++) {
         scanf("%s", F[i] + 1);
     }
     for (int i = 0; i <= r + 1; i++) {
         F[i][0] = F[i][c + 1] = '#';
     }
     for (int j = 0; j <= c + 1; j++) {
         F[0][j] = F[r + 1][j] = '#';
     }
     curver = 0;
     for (int i = 0; i <= r + 1; i++) {
         for (int j = 0; j <= c + 1; j++) {
             ver[i][j] = -1;
             if (F[i][j] == '|' || F[i][j] == '-') {
                 ver[i][j] = curver;
                 posy[curver] = i;
                 posx[curver] = j;
                 curver++;
             }
         }
     }
     for (int i = 0; i < 2 * curver; i++) {
         E[i].clear();
         RE[i].clear();
     }
     for (int i = 0; i <= r + 1; i++) {
         for (int j = 0; j <= c + 1; j++) {
             for (int v = 0; v < 4; v++) {
                 var_[v][i][j] = -2;
             }
         }
     }
     for (int i = 0; i <= r + 1; i++) {
         for (int j = 0; j <= c + 1; j++) {
             for (int v = 0; v < 4; v++) {
                 var(v, i, j);
             }
         }
     }
     bool bad = false;
     for (int i = 0; i <= r + 1; i++) {
         for (int j = 0; j <= c + 1; j++) {
             if (F[i][j] == '|' || F[i][j] == '-') {
                 int vl = var(L, i + vy[L], j + vx[L]);
                 int vr = var(R, i + vy[R], j + vx[R]);
                 int vu = var(U, i + vy[U], j + vx[U]);
                 int vd = var(D, i + vy[D], j + vx[D]);
                 bool both = true;
                 if (vl != -1 || vr != -1) {
                     add_eq(2 * ver[i][j] + 1);
                 } else {
                     both = false;
                 }
                 if (vu != -1 || vd != -1) {
                     add_eq(2 * ver[i][j]);
                 } else {
                     both = false;
                 }
                 if (both) {
                     bad = true;
                     break;
                 }
             }
         }
         if (bad)
             break;
     }
     if (bad) {
         printf("Case #%d: IMPOSSIBLE\n", cs);
         fprintf(stderr, "laser twodir beams\n");
         return;
     }
     for (int i = 0; i <= r + 1; i++) {
         for (int j = 0; j <= c + 1; j++) {
             if (F[i][j] == '.') {
                 int vl = var(L, i, j);
                 int vr = var(R, i, j);
                 int vu = var(U, i, j);
                 int vd = var(D, i, j);
                 int vh = -1;
                 int vv = -1;
                 if ((vl == -1) ^ (vr == -1))
                     vh = any(vl, vr);
                 if ((vd == -1) ^ (vu == -1))
                     vv = any(vu, vd);
                 if (vh == -1 && vv == -1) {
                     bad = true;
                     break;
                 } else if (vh == -1 || vv == -1) {
                     int v = any(vh, vv);
                     add_eq(v);
                 } else {
                     add_disj(vh, vv);
                 }
             }
         }
         if (bad)
             break;
     }
     if (bad) {
         printf("Case #%d: IMPOSSIBLE\n", cs);
         fprintf(stderr, "empty nodir beams\n");
         return;
     }
 
     check2sat();
 
     for (int i = 0; i < curver; i++) {
         if (col[2 * i] == col[2 * i + 1]) {
             bad = true;
             break;
         } else if (col[2 * i] > col[2 * i + 1]) {
             F[posy[i]][posx[i]] = '-';
         } else {
             F[posy[i]][posx[i]] = '|';
         }
     }
 
     if (bad) {
         printf("Case #%d: IMPOSSIBLE\n", cs);
         fprintf(stderr, "2sat no solution\n");
         return;
     }
 
     printf("Case #%d: POSSIBLE\n", cs);
     for (int i = 1; i <= r; i++) {
         for (int j = 1; j <= c; j++) {
             printf("%c", F[i][j]);
         }
         printf("\n");
     }
 
     fprintf(stderr, "OK\n");
 
     return;
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fprintf(stderr, "%d\n", i);
         fflush(stdout);
     }
 }
