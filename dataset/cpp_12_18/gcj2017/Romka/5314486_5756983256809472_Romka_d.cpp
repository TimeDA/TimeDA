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
 
 
 int n, m, k;
 
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
 
 // const Cell NOWHERE{-1, -1};
 
 
 char s[33][33];
 vector<Cell> soldiers, turrets;
 vector<int> id;
 int danger[1 << 10][31][31];
 vector<int> canKill[1 << 10][10];
 int uit[31][31], glIt, umask[1 << 10];
 pii pm[1 << 10];
 
 vector<pii> getSolution() {
     // memset(f, 0xff, sizeof(f));
     int am = (1 << turrets.size()) - 1;
     // f[0][am] = 0;
 
     vector<int> masks;
     masks.push_back(am);
     glIt++;
     umask[am] = glIt;
 
     int lastMask = am;
     forn(i, soldiers.size()) {
         vector<int> nmasks;
         // if (masks.size() > 100)
         //     cerr << i << " " << masks.size() << endl;
         for (int mask : masks) {
             for (int t : canKill[mask][id[i]]) {
                 // if (mask & (1 << t)) {
                 // cerr << "canKill " << mask << " " << id[i] << " " << t << endl;
                 int nm = mask ^ (1 << t);
                 if (umask[nm] != glIt) {
                     umask[nm] = glIt;
                     nmasks.push_back(nm);
                     pm[nm] = pii(i, t);
                     lastMask = nm;
                 }
                 // }
             }
         }
         if (!nmasks.empty()) masks = move(nmasks);
     }
 
     vector<pii> res;
     while (lastMask != am) {
         res.emplace_back(id[pm[lastMask].first], pm[lastMask].second);
         lastMask |= 1 << pm[lastMask].second;
     }
     // cerr << "res.size() = " << res.size() << endl;
     return res;
 }
 
 void goSoldier(int is, int mask, int dng[31][31]) {
     Cell cur = soldiers[is];
     vector<pair<Cell, int>> q;
     size_t qb = 0;
     q.emplace_back(cur, 0);
     glIt++;
     uit[cur.row][cur.col] = glIt;
     int ckmask = 0;
     // cerr << "goSoldier " << is << " mask " << mask << " from " << cur << endl;
 
     while (qb < q.size()) {
         cur = q[qb].first;
         int cd = q[qb].second;
         qb++;
         // cerr << "> " << cur << " " << cd << endl;
 
         if (dng[cur.row][cur.col] != 0) {
             forn(t, turrets.size())
                 if (dng[cur.row][cur.col] & (1 << t)) {
                     ckmask |= 1 << t;
                     // cerr << "canKill " << mask << " " << is << ": " << t << endl;
                     // canKill[mask][is].push_back(t);
                 }
         } else if (cd < k) {
             forn(w, 4) {
                 Cell nc = cur ^ w;
                 if (nc.inside() && s[nc.row][nc.col] != '#' && uit[nc.row][nc.col] != glIt) {
                     uit[nc.row][nc.col] = glIt;
                     q.emplace_back(nc, cd + 1);
                 }
             }
         }
     }
 
     forn(t, turrets.size())
         if (ckmask & (1 << t))
             canKill[mask][is].push_back(t);
 }
 
 void solve() {
     scanf("%d %d %d", &m, &n, &k);
     forn(i, n) scanf("%s", s[i]);
 
     soldiers.clear();
     turrets.clear();
     forn(i, n) forn(j, m) {
         if (s[i][j] == 'S') soldiers.push_back(Cell{i, j});
         if (s[i][j] == 'T') turrets.push_back(Cell{i, j});
     }
     cerr << soldiers.size() << " " << turrets.size() << endl;
 
     memset(danger, 0, sizeof(danger));
     forn(mask, 1 << turrets.size())
         forn(s, soldiers.size())
             canKill[mask][s].clear();
 
     forn(mask, 1 << turrets.size()) {
         forn(t, turrets.size())
             if ((1 << t) & mask) {
                 forn(q, 4) {
                     Cell cur = turrets[t] ^ q;
                     while (cur.inside()) {
                         if (s[cur.row][cur.col] == '#') break;
                         danger[mask][cur.row][cur.col] |= 1 << t;
                         cur ^= q;
                     }
                 }
             }
 
         forn(s, soldiers.size()) {
             goSoldier(s, mask, danger[mask]);
         }
     }
 
     id.resize(soldiers.size());
     forn(i, soldiers.size()) id[i] = i;
     cerr << "permutations..." << endl;
     vector<pii> ans;
     do {
         if (soldiers.size() == 10 && rand() % 3 != 2) continue;
         vector<pii> cur = getSolution();
         if (cur.size() > ans.size()) {
             ans = cur;
             if (ans.size() == min(soldiers.size(), turrets.size())) break;
         }
     } while (next_permutation(id.begin(), id.end()));
 
     printf("%d\n", (int)ans.size());
     reverse(ans.begin(), ans.end());
     for (const pii& p : ans)
         printf("%d %d\n", p.first + 1, p.second + 1);
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         fprintf(stderr, "%d / %d...\n", q, tc);
         printf("Case #%d: ", q);
         solve();
     }
     return 0;
 }
