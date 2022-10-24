#include <bits/stdc++.h>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 const int SIZE = 102;
 char ans[SIZE][SIZE];
 int n, m;
 int cnt;
 vector <int> perm;
 
 const int dx[4] = {-1, 0, 1, 0};
 const int dy[4] = {0, 1, 0, -1};
 
 struct Pos {
   int x, y, dir;
 
   Pos(int x, int y, int dir) : x(x), y(y), dir(dir) {}
   Pos go() const {
     return Pos(x + dx[dir], y + dy[dir], dir ^ 2);
   }
 
   bool operator == (const Pos & o) const {
     return x == o.x && y == o.y && dir == o.dir;
   }
   bool operator != (const Pos & o) const {
     return !(*this == o);
   }
 
   void print() const {
     //dbg("x %d y %d dir %d\n", x, y, dir);
   }
 };
 
 Pos getPos(int num) {
   if (num < m) {
     return Pos(0, num, 0);
   }
   num -= m;
   if (num < n) {
     return Pos(num, m - 1, 1);
   }
   num -= n;
   if (num < m) {
     return Pos(n - 1, m - 1 - num, 2);
   }
   num -= m;
   if (num < n) {
     return Pos(n - 1 - num, 0, 3);
   }
   assert(0);
 }
 
 Pos go(Pos pos) {
   //dbg("go ");
   pos.print();
   while (true) {
     if (ans[pos.x][pos.y] == '/') {
       pos.dir = 3 - pos.dir;
     } else {
       pos.dir ^= 1;
     }
     pos.print();
     Pos newPos = pos.go();
     newPos.print();
     if (!(0 <= newPos.x && newPos.x < n && 0 <= newPos.y && newPos.y < m)) {
       return pos;
     }
     pos = newPos;
   }
   assert(0);
 }
 
 char getLetter(int x) {
   if (x < 10) {
     return x + '0';
   }
   return x + 'a' - 10;
 }
 
 bool check() {
   for (int i = 0; i < cnt; i += 2) {
     Pos pos1 = getPos(perm[i]);
     Pos pos2 = getPos(perm[i + 1]);
     if (go(pos1) != pos2) {
       return false;
     }
   }
   return true;
 }
 
 bool brute(int x, int y) {
   if (x == n) {
     return check();
   }
   int x1 = x;
   int y1 = y + 1;
   if (y1 == m) {
     y1 = 0;
     x1++;
   }
   for (int i = 0; i < 2; ++i) {
     ans[x][y] = "/\\"[i];
     if (brute(x1, y1)) {
       return true;
     }
   }
   return false;
 }
 
 void debug(const vector <int> & num) {
   dbg(" ");
   for (int i = 0; i < m; ++i) {
     dbg("%c", getLetter(num[i]));
   }
   dbg("\n");
   for (int i = 0; i < n; ++i) {
     dbg("%c", getLetter(num[cnt - 1 - i]));
     for (int j = 0; j < m; ++j) {
       dbg("%c", ans[i][j]);
     }
     dbg("%c\n", getLetter(num[m + i]));
   }
   dbg(" ");
   for (int i = 0; i < m; ++i) {
     dbg("%c", getLetter(num[n + m + m - 1 - i]));
   }
   dbg("\n");
 }
 
 void solve() {
   scanf("%d%d", &n, &m);
   cnt = 2 * (n + m);
   perm.clear();
   perm.resize(cnt);
   for (int i = 0; i < cnt; ++i) {
     scanf("%d", &perm[i]);
     --perm[i];
   }
   vector <int> num(cnt);
   for (int i = 0; i < cnt; ++i) {
     num[perm[i]] = i / 2;
   }
   int sym = 0;
   if (0 && n > m) {
     sym = 1;
     swap(n, m);
     for (int i = 0; i < cnt; ++i) {
       perm[i] = cnt - 1 - perm[i];
     }
   }
 
 
   if (!brute(0, 0)) {
     memset(ans, ' ', sizeof(ans));
     debug(num);
     printf("\nIMPOSSIBLE\n");
     return;
   }
 
   if (sym) {
     for (int i = 0; i < n; ++i) {
       for (int j = 0; j < m; ++j) {
         swap(ans[i][j], ans[j][i]);
       }
     }
     swap(n, m);
   }
   printf("\n");
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       printf("%c", ans[i][j]);
     }
     printf("\n");
   }
 
 
   debug(num);
 }
 
 int main()
 {
 #ifdef DBG1
   assert(freopen("input.txt", "r", stdin));
   assert(freopen("output.txt", "w", stdout));
   assert(freopen("err.txt", "w", stderr));
 #endif
 
   int tt;
   assert (scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case %d\n", ii);
     printf("Case #%d:", ii);
     solve();
     fflush(stdout);
   }
 
   return 0;
 }
 
