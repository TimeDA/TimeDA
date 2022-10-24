#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 const int dx[] = {-1, 1, 0, 0};
 const int dy[] = {0, 0, -1, 1};
 
 const int P = int(1e9) + 7;
 
 int r, c;
 int a[6][6];
 int res;
 
 void print() {
   for (int j = 0; j < r; ++j) {
     for (int i = 0; i < c; ++i) {
       dbg("%d ", a[i][j]);
     }
     dbg("\n");
   }
   dbg("-----\n"); 
 }
 
 bool check (int x, int y) {
   if (y < 0 || y >= r) {
     return 1;
   }
   if (a[x][y] == -1) {
     return 1;
   }
   int cnt = 0;
   for (int i = 0; i < 4; ++i) {
     int x0 = x + dx[i];
     int y0 = y + dy[i];
     if (x0 < 0) {
       x0 += c;
     }
     if (x0 >= c) {
       x0 -= c;
     }
     if (y0 < 0 || y0 >= r) {
       continue;
     }
     if (a[x0][y0] == -1) {
       return 1;
     }
     if (a[x][y] == a[x0][y0]) {
       ++cnt;
     }
   }
   return cnt == a[x][y];
 }
 
 vector < vector < vector < int > > > all;
 
 bool equals(const vector < vector <int> > & a, const vector < vector <int> > & b) {
   return a == b;
   for (int i = 0; i < c; ++i) {
     for (int j = 0; j < r; ++j) {
       if (a[i][j] != b[i][j]) {
         return 0;
       }
     }
   }
   return 1;
 }
 
 bool checkMinimal () {
   dbg("checkMinimal\n");
   print();
   vector < vector < int > > Z(c, vector <int> (r));
   for (int shift = 0; shift < c; ++shift) {
     for (int i = 0; i < c; ++i) {
       for (int j = 0; j < r; ++j) {
         Z[i][j] = a[(i + shift) % c][j];
       }
     }
     int p = 0;
     while (p < int(all.size()) && !equals(all[p], Z)) {
       ++p;
     }
     if (p < int(all.size())) {
       return 0;
     }
   }
   all.push_back(Z);
   return 1;
 }
 
 void brute (int x, int y);
 
 void brute2 (int x, int y) {
   if (!check(x, y)) {
     return;
   }
   for (int i = 0; i < 4; ++i) {
     int x0 = x + dx[i];
     int y0 = y + dy[i];
     if (x0 < 0) {
       x0 += c;
     }
     if (x0 >= c) {
       x0 -= c;
     }
     if (!check(x0, y0)) {
       return;
     }
   }
   brute (x, y + 1);
 }
 
 void brute (int x, int y) {
   if (y == r) {
     x ++;
     y = 0;
   }
   if (x == c) {
     if (checkMinimal()) {
       res++;
       print(); 
     }
     if (res >= P) {
       res -= P;
     }
     return;
   }
   for (int i = 1; i <= 3; ++i) {
     a[x][y] = i;
     brute2(x, y);
     a[x][y] = -1; 
   }
 }
 
 void solve() {
   scanf("%d%d", &r, &c);
   memset(a, 0xff, sizeof(a));
   res = 0;
   brute (0, 0);
   printf ("%d\n", res);
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     solve();
   }
 
   return 0;
 }
 
