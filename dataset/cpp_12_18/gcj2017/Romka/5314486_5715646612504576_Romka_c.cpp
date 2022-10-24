#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <unordered_map>
 #include <unordered_set>
 #include <sstream>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define sqr(x) (x) * (x)
 template <class T> ostream& operator<<(ostream& out, const vector<T>& v) { forn(i, v.size()) { if (i) out << " "; out << v[i]; } return out; }
 template <class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) { out << "{" << p.first << ", " << p.second << "}"; return out; }
 
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
 const int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
 int n, m;
 
 struct Cell {
     int row, col;
 
     bool inside() const {
         return row >= 0 && col >= 0 && row < n && col < m;
     }
 
     Cell operator^(int q) const {
         return {row + di[q], col + dj[q]};
     }
 
     Cell& operator^=(int q) {
         row += di[q];
         col += dj[q];
         return *this;
     }
 
     Cell moveTo(int q, int d) const {
         return {row + di[q] * d, col + dj[q] * d};
     }
 };
 
 bool operator<(const Cell& lhs, const Cell& rhs) {
     if (lhs.row != rhs.row) return lhs.row < rhs.row;
     return lhs.col < rhs.col;
 }
 
 bool operator==(const Cell& lhs, const Cell& rhs) {
     return lhs.row == rhs.row && lhs.col == rhs.col;
 }
 
 bool operator!=(const Cell& lhs, const Cell& rhs) {
     return !(lhs == rhs);
 }
 
 ostream& operator<<(ostream& out, const Cell& cell) {
     return out << "(" << cell.row << "," << cell.col << ")";
 }
 
 int dist(const Cell& a, const Cell& b) {
     return abs(a.row - b.row) + abs(a.col - b.col);
 }
 
 const Cell NOWHERE{-1, -1};
 
 int V;
 char s[55][55];
 vector<pii> covers[55][55];
 vector<Cell> pos;
 
 vector<vector<int>> g, gt;
 vector<bool> used;
 vector<int> order, comp;
 vector<bool> ans;
 
 void dfs1(int v) {
     used[v] = true;
     for (int to : g[v]) if (!used[to]) dfs1(to);
     order.push_back(v);
 }
 
 void dfs2(int v, int color) {
     comp[v] = color;
     for (int to : gt[v]) if (comp[to] == -1) dfs2(to, color);
 }
 
 bool sat() {
     used.assign(V, false);
     order.clear();
     forn(i, V) if (!used[i]) dfs1(i);
 
     comp.assign(V, -1);
     int j = 0;
     forn(i, V) {
         int v = order[V - i - 1];
         if (comp[v] == -1) dfs2(v, j++);
     }
 
     forn(i, V)
         if (comp[i] == comp[i ^ 1])
             return false;
 
     // cerr << comp << endl;
 
     ans.clear();
     forn(i, V / 2 -1) {
         ans.push_back(comp[i * 2] > comp[i * 2 + 1]);
     }
 
     return true;
 }
 
 void edge(int a, int b) {
     // cerr << "edge " << a << " -> " << b << endl;
     g[a].push_back(b);
     gt[b].push_back(a);
 }
 
 int uit[55][55], glIt;
 
 vector<Cell> go(Cell c, int d) {
     vector<Cell> res;
     while (true) {
         c ^= d;
         // cerr << "go " << c << endl;
         if (!c.inside() || s[c.row][c.col] == '#') return res;
         if (s[c.row][c.col] == '|' || s[c.row][c.col] == '-') {
             // cerr << "hit source at " << c << endl;
             return {NOWHERE};
         }
         if (s[c.row][c.col] == '.') {
             res.push_back(c);
         } else if (s[c.row][c.col] == '\\') {
             d ^= 1;
         } else if (s[c.row][c.col] == '/') {
             d ^= 3;
         }
     }
 }
 
 vector<Cell> get(int i, int j, int d) {
     // cerr << "get " << i << " " << j << " " << d << endl;
     vector<Cell> a = go(Cell{i, j}, d);
     if (!a.empty() && a.front() == NOWHERE) return a;
     vector<Cell> b = go(Cell{i, j}, d + 2);
     if (!b.empty() && b.front() == NOWHERE) return b;
     vector<Cell> res;
     glIt++;
     for (const Cell& c : a)
         if (uit[c.row][c.col] != glIt) {
             uit[c.row][c.col] = glIt;
             res.push_back(c);
         }
     for (const Cell& c : b)
         if (uit[c.row][c.col] != glIt) {
             uit[c.row][c.col] = glIt;
             res.push_back(c);
         }
     return res;
 }
 
 bool solve() {
     scanf("%d %d", &n, &m);
     forn(i, n) scanf("%s", s[i]);
 
     pos.clear();
     forn(i, n) forn(j, m) covers[i][j].clear();
     vector<pii> bad;
 
     forn(i, n)
         forn(j, m) {
             if (s[i][j] != '-' && s[i][j] != '|') continue;
             vector<Cell> visited = get(i, j, 0);
             if (!visited.empty() && visited.front() == NOWHERE) {
                 // cerr << i << " " << j << " 0 - not ok" << endl;
                 bad.emplace_back(pos.size(), 0);
             } else {
                 // cerr << i << " " << j << " 0 - ok" << endl;
                 for (const Cell& c : visited) {
                     covers[c.row][c.col].emplace_back(pos.size(), 0);
                 }
             }
             visited = get(i, j, 1);
             if (!visited.empty() && visited.front() == NOWHERE) {
                 // cerr << i << " " << j << " 1 - not ok" << endl;
                 bad.emplace_back(pos.size(), 1);
             } else {
                 // cerr << i << " " << j << " 1 - ok" << endl;
                 for (const Cell& c : visited) {
                     covers[c.row][c.col].emplace_back(pos.size(), 1);
                 }
             }
 
             pos.push_back(Cell{i, j});
         }
 
     // cerr << pos.size() << endl;
     V = pos.size() * 2 + 2;
     g.assign(V, vector<int>());
     gt.assign(V, vector<int>());
 
     for (const pii& x : bad) {
         int v = x.first * 2 + x.second;
         edge(V - 2, v ^ 1);
         edge(V - 1, v ^ 1);
         edge(v, V - 1);
         edge(v, V - 2);
     }
 
     forn(i, n)
         forn(j, m)
             if (s[i][j] == '.') {
                 const auto& c = covers[i][j];
                 if (c.empty()) {
                     // cerr << "no cover: " << i << " " << j << endl;
                     return false;
                 }
                 int f = c[0].first * 2 + c[0].second;
                 if (c.size() == 1) {
                     edge(V - 2, f);
                     edge(V - 1, f);
                     edge(f ^ 1, V - 1);
                     edge(f ^ 1, V - 2);
                 } else {
                     int s = c[1].first * 2 + c[1].second;
                     edge(f ^ 1, s);
                     edge(s ^ 1, f);
                 }
             }
 
     // cerr << "go sat" << endl;
     return sat();
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         if (solve()) {
             printf("POSSIBLE\n");
             forn(i, pos.size()) {
                 s[pos[i].row][pos[i].col] = ans[i] ? '|' : '-';
             }
             forn(i, n)
                 puts(s[i]);
         } else {
             printf("IMPOSSIBLE\n");
         }
     }
     return 0;
 }
