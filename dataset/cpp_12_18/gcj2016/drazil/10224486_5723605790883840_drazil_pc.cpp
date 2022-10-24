#include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 
 using namespace std;
 
 int r, c;
 char maze[16][17];
 int p[1000];
 
 char toPos(int id, int &x, int &y) {
     id--;
     if (id < c) {
         y = 0; x = id;
         return 'D';
     }
     id -= c;
     if (id < r) {
         y = id; x = c - 1;
         return 'L';
     }
     id -= r;
     if (id < c) {
         y = r - 1; x = c - id - 1;
         return 'U';
     }
     id -= c;
     y = r - id - 1; x = 0;
     return 'R';
 }
 
 int fromPos(int x, int y) {
     if (x == -1) return 2 * c + 2 * r - y;
     if (y == r) return 2 * c + r - x;
     if (x == c) return c + y + 1;
     return x + 1;
 }
 
 char Next(int &x, int &y, char dir) {
     if (maze[y][x] == '/') {
         if (dir == 'L') { y++; return 'D'; }
         if (dir == 'R') { y--; return 'U'; }
         if (dir == 'U') { x++; return 'R'; }
         if (dir == 'D') { x--; return 'L'; }
     } else {
         if (dir == 'L') { y--; return 'U'; }
         if (dir == 'R') { y++; return 'D'; }
         if (dir == 'U') { x--; return 'L'; }
         if (dir == 'D') { x++; return 'R'; }
     }
     return 'X';
 }
 
 bool OK() {
     for (int id = 1; id <= 2 * (r + c); id++) {
         int x, y;
         char dir;
         dir = toPos(id, x, y);
         while (x >= 0 && x < c && y >= 0 && y < r) {
             dir = Next(x, y, dir);
         }
         int tar = fromPos(x, y);
         if (p[id] != tar) return false;
     }
     return true;
 }
 
 int main() {
     int tc;
     cin >> tc;
     for (int t = 1; t <= tc; t++) {
         bool ans = false;
         cin >> r >> c;
         for (int i = 0; i < (r + c); i++) {
             int a, b;
             cin >> a >> b;
             p[a] = b;
             p[b] = a;
         }
         for (int i = 0; i < (1<<(r*c)); i++) {
             int id = i;
             for (int y = 0; y < r; y++) {
                 for (int x = 0; x < c; x++) {
                     maze[y][x] = ((id & 1) == 1) ? '/' : '\\';
                     id >>= 1;
                 }
                 maze[y][c] = '\0';
             }
             if (OK()) {
                 ans = true;
                 break;
             }
         }
         printf("Case #%d:\n", t);
         if (!ans) puts("IMPOSSIBLE");
         else {
             for(int y = 0; y < r; y++) {
                 puts(maze[y]);
             }
         }
     }
 
     return 0;
 }
 
