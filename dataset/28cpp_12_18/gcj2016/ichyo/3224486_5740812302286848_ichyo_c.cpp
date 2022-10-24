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
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(12);
 }
 //}}}
 
 struct P{
     double x, y, z;
     P() : x(0), y(0), z(0) {}
     P(double x_, double y_, double z_) : 
         x(x_), y(y_), z(z_) {}
 };
 typedef P Point;
 
 const double EPS = 1e-8;
 
 P operator + (P a, P b){ return P(a.x + b.x, a.y + b.y, a.z + b.z); }
 P operator - (P a, P b){ return P(a.x - b.x, a.y - b.y, a.z - b.z); }
 P operator * (double t, P a){ return P(t * a.x, t * a.y, t * a.z); }
 P operator * (P a, double t){ return P(t * a.x, t * a.y, t * a.z); }
 
 double dot(P a, P b){ return a.x * b.x + a.y * b.y + a.z * b.z; }
 double abs(P a){ return sqrt(dot(a, a)); }
 P cross(P a, P b){
     return P(
             a.y * b.z - a.z * b.y,
             a.z * b.x - a.x * b.z,
             a.x * b.y - a.y * b.x
             );
 }
 
 // 点aと点bを通る直線と，点cの距離
 double distanceLP(P a, P b, P c){
     b = b - a; c = c - a; 
     double t = dot(b, c) / dot(b, b);
     return abs(c - b * t);
 }
 
 // a, bを通る直線と，c, dを通る直線の距離
 double distanceLL(P a, P b, P c, P d){
     P v = cross(b - a, d - c); // 法線ベクトル
     P p = c - a;
     if(abs(v) < EPS) return distanceLP(a, b, c);
     double dst = abs(dot(v, p)) / abs(v);
     return dst;
 }
 
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
 
 const double INF = 1e9;
 int N, S;
 vector<Point> ps, vs;
 
 double minimalTime(int i, int j, double d) {
     Point p = ps[i], q = ps[j];
     Point v = vs[i], w = vs[j];
 
     // Small
     // double distance = abs(q - p);
     // cout << i << " " << j << " " << distance << endl;
     double dis2 = dot(q-p, q-p);
     if(dis2 <= d * d) return 0;
     else return INF;
 
     // Large
 }
 
 double connectedTime(double d) {
     vector<tuple<double, int, int>> tps;
     double times[1000][1000];
     UnionFind uf(N);
     for(int i = 0; i < N; i++) {
         for(int j = i+1; j < N; j++) {
             times[i][j] = times[j][i] = minimalTime(i, j, d);
             if(times[i][j] == 0.0) {
                 uf.unite(i, j);
             }
         }
     }
     return (uf.same(0, 1) ? 0 : INF);
 }
 
 void solve() {
     cin >> N >> S;
     ps.resize(N);
     vs.resize(N);
     REP(i, N) { cin >> ps[i].x >> ps[i].y >> ps[i].z; cin >> vs[i].x >> vs[i].y >> vs[i].z; }
     double lb = 0, ub = 3000.0;
 
     REP(_, 80) {
         double d = (lb + ub) / 2;
         if(connectedTime(d) < S) {
             ub = d;
         } else {
             lb = d;
         }
     }
 
     cout << (lb + ub) / 2 << endl;
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
 
