// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define dump(x) 
 #endif
 
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(12);
 }
 //}}}
 
 struct UnionFind {
     vector<int> data;
     UnionFind(int N) : data(N, -1) { }
     // xとyを併合する
     bool unite(int x, int y) {
         x = root(x); y = root(y);
         if (x != y) {
             if (data[x] > data[y]) swap(x, y);
             data[x] += data[y]; data[y] = x;
         }
         return x != y;
     }
     // xとyが同じ集合にあるか判定する
     bool same(int x, int y) {
         return root(x) == root(y);
     }
     // xを含む集合の要素数を求める
     int size(int x) {
         return -data[root(x)];
     }
     int root(int x) {
         return data[x] < 0 ? x : data[x] = root(data[x]);
     }
 };
 
 void solve() {
     cout << endl;
     int W, H;
     cin >> H >> W;
     function<int(int, int, int)> getID = [&](int x, int y, int r) {
         if(r == 0) {
             return (y+1) * (2 * W + 1) - (W + 1) + x;
         } else if(r == 1) {
             return y * (2 * W + 1) + x;
         } else if(r == 2) {
             return getID(x, y, 0) + 1;
         } else if(r == 3) {
             return getID(x, y+1, 1);
         }
         assert(false);
     };
     const int PS = 2*(W+H);
     vector<int> inputs(PS);
     REP(i, PS){
         cin >> inputs[i];
         inputs[i]--;
     }
     vector<int> rival(PS);
     REP(i, W+H) {
         int u = inputs[2*i];
         int v = inputs[2*i + 1];
         rival[u] = v;
         rival[v] = u;
     }
     const int ID = getID(W-1, H-1, 3) + 1;
     vector<int> ids; // person id -> edge id
     REP(x, W) ids.push_back(getID(x, 0, 1));
     REP(y, H) ids.push_back(getID(W-1, y, 2));
     REP(x, W) ids.push_back(getID(W-1-x, H-1, 3));
     REP(y, H) ids.push_back(getID(0, H-1-y, 0));
     // REP(i, PS) cout << ids[i] << " "; cout << endl;
     map<int, int> idsrev;
     REP(i, ids.size()) idsrev[ ids[i] ] = i; // edge id -> person id
     bool valid = false;
     REP(s, (1 << W * H)) {
         UnionFind uf(ID);
         int grid[16][16] = {};
         REP(y, H) REP(x, W) {
             int id = y * W + x;
             grid[y][x] = (s >> id & 1);
         }
         REP(y, H) REP(x, W) {
             if(grid[y][x] == 0) { // '\\'
                 uf.unite(getID(x, y, 0), getID(x, y, 3));
                 uf.unite(getID(x, y, 1), getID(x, y, 2));
             } else { // '//'
                 uf.unite(getID(x, y, 0), getID(x, y, 1));
                 uf.unite(getID(x, y, 2), getID(x, y, 3));
             }
         }
         bool ok = true;
         REP(u, PS) REP(v, PS) if(u < v) {
             int eu = ids[u];
             int ev = ids[v];
             if((v == rival[u] && !uf.same(eu, ev)) || (v != rival[u] && uf.same(eu, ev))) {
                 // cout << u << " " << v << endl;
                 // cout << eu << " " << ev << endl;
                 // cout << (v == rival[u]) << endl;
                 // cout << uf.same(eu, ev) << endl;
                 ok = false;
             }
         }
         if(ok) {
             valid = true;
             REP(y, H) {
                 REP(x, W) {
                     cout << (grid[y][x] ? "/" : "\\");
                 }
                 cout << endl;
             }
             break;
         }
     }
     if(!valid) {
         cout << "IMPOSSIBLE" << endl;
     }
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     REP(casenum, T) {
         cout << "Case #" << casenum + 1 << ": ";
         solve();
     }
 
     return 0;
 }
 
