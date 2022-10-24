#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 //#include "testlib.h"
 #include <bits/stdc++.h>
 using namespace std;
 
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve(bool);
 void precalc();
 clock_t start;
 int main() {
 #ifdef AIM
     freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
     freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
     //freopen("out.txt", "w", stdout);
 #else
     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);
 #endif
     start = clock();
     int t = 1;
     cout.sync_with_stdio(0);
     cin.tie(0);
     precalc();
     cout.precision(10);
     cout << fixed;
     cin >> t;
     int testNum = 1;
     while (t--) {
         cout << "Case #" << testNum++ << ": ";
         solve(true);
       cerr << testNum - 1 << endl;
     }
     cout.flush();
 #ifdef AIM1
     while (true) {
         solve(false);
     }
 #endif
 
 #ifdef AIM
     cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
     return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 template<typename T>
 T binpow(T q, T w, T mod) {
   if (!w)
       return 1 % mod;
   if (w & 1)
       return q * 1LL * binpow(q, w - 1, mod) % mod;
   return binpow(q * 1LL * q % mod, w / 2, mod);
 }
 
 template<typename T>
 T gcd(T q, T w) {
   while (w) {
       q %= w;
       swap(q, w);
   }
   return q;
 }
 template<typename T>
 T lcm(T q, T w) {
   return q / gcd(q, w) * w;
 }
 
 void precalc() {
 
 }
 
 //const int mod = 1000000007;
 
 //#define int li
 
 int n, m;
 vector<string> s;
 
 struct Point {
   int x, y;
   Point() {}
   Point(int x, int y) : x(x), y(y) {}
   Point operator + (const Point& ot) const {
     return Point(x + ot.x, y + ot.y);
   }
   bool operator < (const Point& ot) const {
     return make_pair(x, y) < make_pair(ot.x, ot.y);
   }
   bool operator == (const Point& ot) const {
     return make_pair(x, y) == make_pair(ot.x, ot.y);
   }
   int& operator [](int c) {
     if (c == 0) {
       return x;
     }
     if (c == 1) {
       return y;
     }
     assert(false);
   }
 };
 
 bool correct(Point cur) {
   return cur.x >= 0 && cur.y >= 0 && cur.x < n && cur.y < m;
 }
 
 bool is_laser(char c) {
   return c == '-' || c == '|';
 }
 
 vector<Point> dirs = {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
 int get_dir(Point dir) {
   for (int i = 0; i < dirs.size(); ++i) {
     if (dirs[i] == dir) {
       return i;
     }
   }
 }
 vector<vector<vector<int>>> used_timer;
 int TIMER = 0;
 
 pair<Point, Point> get_last_cell(Point cur, Point dir) {
   int cur_dir = get_dir(dir);
   if (used_timer[cur.x][cur.y][cur_dir] == TIMER) {
     return {cur, dir};
   }
   used_timer[cur.x][cur.y][cur_dir] = TIMER;
   Point nex = cur + dir;
   if (!correct(nex) || s[nex.x][nex.y] == '#' || is_laser(s[nex.x][nex.y])) {
     return {nex, dir};
   }
   if (s[nex.x][nex.y] == '.') {
     return get_last_cell(nex, dir);
   }
   if (s[nex.x][nex.y] == '/') {
     if (dir.x == 1) {
       return get_last_cell(nex, Point(0, -1));
     }
     if (dir.x == -1) {
       return get_last_cell(nex, Point(0, 1));
     }
     if (dir.y == -1) {
       return get_last_cell(nex, Point(1, 0));
     }
     if (dir.y == 1) {
       return get_last_cell(nex, Point(-1, 0));
     }
   }
   if (s[nex.x][nex.y] == '\\') {
     if (dir.x == 1) {
       return get_last_cell(nex, Point(0, 1));
     }
     if (dir.x == -1) {
       return get_last_cell(nex, Point(0, -1));
     }
     if (dir.y == -1) {
       return get_last_cell(nex, Point(-1, 0));
     }
     if (dir.y == 1) {
       return get_last_cell(nex, Point(1, 0));
     }
   }
 }
 
 pair<Point, Point> get_ans(Point cur, Point dir) {
   ++TIMER;
   return get_last_cell(cur, dir);
 }
 
 vector<vector<int>> num;
 int get_laser(Point cur) {
   return correct(cur) ? num[cur.x][cur.y] : -1;
 }
 
 vector<vector<int>> g, revg;
 
 void add_edge(int a, int b) {
   //cout << "edge: " << a << " " << b << endl;
   g[a].push_back(b);
   g[b ^ 1].push_back(a ^ 1);
   revg[b].push_back(a);
   revg[a ^ 1].push_back(b ^ 1);
 }
 
 void impossible() {
   cout << "IMPOSSIBLE\n";
 }
 
 vector<bool> new_used;
 vector<int> order, comp;
 
 void dfs1 (int v) {
   new_used[v] = true;
   for (size_t i=0; i<g[v].size(); ++i) {
     int to = g[v][i];
     if (!new_used[to])
       dfs1 (to);
   }
   order.push_back (v);
 }
 
 void dfs2 (int v, int cl) {
   comp[v] = cl;
   for (size_t i=0; i<revg[v].size(); ++i) {
     int to = revg[v][i];
     if (comp[to] == -1)
       dfs2 (to, cl);
   }
 }
 
 void solve(bool read) {
   cin >> n >> m;
   s.resize(n);
   for (int i = 0; i < n; ++i) {
     cin >> s[i];
   }
   num.assign(n, vector<int>(m, -1));
   int cnt = 0;
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (is_laser(s[i][j])) {
         num[i][j] = cnt++;
       }
     }
   }
   g.clear();
   g.resize(2 * cnt);
   revg = g;
   used_timer.assign(n, vector<vector<int>>(m, vector<int>(dirs.size(), 0)));
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (s[i][j] != '.' && !is_laser(s[i][j])) {
         continue;
       }
       Point cur(i, j);
       vector<int> covers;
       for (int pos = 0; pos < 2; ++pos) {
         Point cur_dir(0, 0);
         cur_dir[pos] = -1;
         pair<Point, Point> up = get_ans(cur, cur_dir);
         cur_dir[pos] = 1;
         pair<Point, Point> down = get_ans(cur, cur_dir);
         int up_laser = get_laser(up.first), down_laser = get_laser(down.first);
         int hor_up = up.second.x == 0, hor_down = down.second.x == 0;
 
         if (is_laser(s[i][j])) {
           if (up_laser != -1 || down_laser != -1) {
             //cout << num[i][j] << " " << pos << " " << up_laser << " " << down_laser << endl;
             add_edge(2 * num[i][j] + pos, 2 * num[i][j] + (1 - pos));
           }
           continue;
         }
 
         if (up_laser != -1 && down_laser != -1) {
           add_edge(up_laser * 2 + hor_up, up_laser * 2 + (1 - hor_up));
           add_edge(down_laser * 2 + hor_down, down_laser * 2 + (1 - hor_down));
         } else if (up_laser != -1) {
           covers.push_back(up_laser * 2 + hor_up);
         } else if (down_laser != -1) {
           covers.push_back(down_laser * 2 + hor_down);
         }
       }
       if (is_laser(s[i][j])) {
         continue;
       }
       if (covers.empty()) {
         impossible();
         return;
       }
       if (covers.size() == 1) {
         int v = covers[0];
         add_edge(v ^ 1, v);
       } else {
         int v = covers[0], u = covers[1];
         add_edge(v ^ 1, u);
       }
     }
   }
 
   int N = 2 * cnt;
   new_used.assign (N, false);
   for (int i=0; i<N; ++i)
     if (!new_used[i])
       dfs1 (i);
 
   order.clear();
   comp.assign (N, -1);
   for (int i=0, j=0; i<N; ++i) {
     int v = order[N-i-1];
     if (comp[v] == -1)
       dfs2 (v, j++);
   }
 
   for (int i=0; i<N; ++i)
     if (comp[i] == comp[i^1]) {
       impossible();
       return;
     }
 
   auto res = s;
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (num[i][j] == -1) {
         continue;
       }
       int v = num[i][j];
       if (comp[2 * v] > comp[2 * v + 1]) {
         res[i][j] = '|';
       } else {
         res[i][j] = '-';
       }
     }
   }
 
   cout << "POSSIBLE\n";
   for (int i = 0; i < n; ++i) {
     cout << res[i] << endl;
   }
 
 
 }