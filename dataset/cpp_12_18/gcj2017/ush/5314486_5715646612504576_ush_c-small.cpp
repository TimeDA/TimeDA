
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <iostream>
 #include <cassert>
 #include <vector>
 #include <set>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 const int DI[4] = {1, 0, -1, 0};
 const int DJ[4] = {0, 1, 0, -1};
 const int SLASH[4] = {3, 2, 1, 0};
 const int BACKSLASH[4] = {1, 0, 3, 2};
 
 int nRow, nCol;
 char buf[60][60];
 int toId[60][60];
 const char *IMPOSSIBLE = "IMPOSSIBLE";
 const char *POSSIBLE = "POSSIBLE";
 
 vector<int> g[210];
 int states[110];
 
 struct P {
   int i, j;
   P(int i, int j): i(i), j(j) {}
   P() {}
 };
 struct K {
   P p;
   int d;
   K(P p, int d): p(p), d(d) {}
   K() {}
   bool isPossible() {
     if(p.i < 0 || p.j < 0 || d < 0) return false;
     int id = toId[p.i][p.j];
     return !!(states[id] & (1 << d%2));
   }
 };
 vector<P> ps;
 
 // 光源に衝突したら衝突したマスを返す。そうでない時は(-1,-1)を返す
 K go(int si, int sj, int dir) {
   int ci = si;
   int cj = sj;
   int cd = dir;
   for(;;) {
     // cerr << ci << " " << cj << " " << cd << endl;
     ci += DI[cd];
     cj += DJ[cd];
     if(ci < 0 || cj < 0 || ci >= nRow || cj >= nCol)
       break;
     if(buf[ci][cj] == '#')
       break;
     if(buf[ci][cj] == '|' || buf[ci][cj] == '-' || buf[ci][cj] == '?')
       return K(P(ci, cj), cd);
     if(buf[ci][cj] == '.') {
       // nothing
     } else if(buf[ci][cj] == '/') {
       cd = SLASH[cd];
     } else if(buf[ci][cj] == '\\') {
       cd = BACKSLASH[cd];
     } else {
       cerr << ">>>>>>>>>>> " << buf[ci][cj] << endl;
       assert(false);
     }
   }
   return K(P(-1, -1), -1);
 }
 
 bool gogo(int u, vector<int>& before) {
   if(states[u/2] == 3) {
     before.push_back(u/2);
     states[u/2] = 1 << u%2;
     REP(i, g[u].size()) {
       if(!gogo(g[u][i], before)) {
         return false;
       }
     }
   } else if(states[u/2] != (1 << u%2)) {
     return false;
   }
   return true;
 }
 
 bool solve2SAT(int id) {
   // cerr << "> solve2SAT(" << id << ")" << endl;
   if(id == (int)ps.size())
     return true;
   if(states[id] != 3)
     return solve2SAT(id+1);
   REP(b, 2) {
     vector<int> before;
     bool ok = gogo(id*2+b, before);
     if(ok == false || solve2SAT(id+1) == false) {
       REP(i, before.size()) {
         states[before[i]] = 3;
       }
     } else {
       return true;
     }
   }
   return false;
 }
 
 void solve() {
   ps.clear();
   // 光源同士の衝突を確かめる
   REP(i, nRow) REP(j, nCol) {
     if(buf[i][j] == '-' || buf[i][j] == '|') {
       int id = toId[i][j] = ps.size();
       ps.push_back(P(i, j));
       g[id*2].clear();
       g[id*2+1].clear();
       states[id] = 3;
       bool bs[4];
       REP(d, 4) {
         bs[d] = go(i, j, d).p.i >= 0;
       }
       if(bs[1] || bs[3]) { // -だと衝突
         states[id] &= 1 << 0;
       }
       if(bs[0] || bs[2]) { // |だと衝突
         states[id] &= 1 << 1;
       }
     }
   }
   // 各マスを照らせるかを確かめる
   REP(i, nRow) REP(j, nCol) {
     if(buf[i][j] == '.') {
       K ks[4];
       REP(d, 4) {
         ks[d] = go(i, j, d);
       }
       K kH = ks[1].isPossible() ? ks[1] : ks[3];
       K kV = ks[0].isPossible() ? ks[0] : ks[2];
       if(!kH.isPossible() && !kV.isPossible()) {
         puts(IMPOSSIBLE);
         return;
       } else if(!kH.isPossible()) {
         int id = toId[kV.p.i][kV.p.j];
         states[id] &= 1 << (kV.d % 2);
       } else if(!kV.isPossible()) {
         int id = toId[kH.p.i][kH.p.j];
         states[id] &= 1 << (kH.d % 2);
       } else {
         int id1 = toId[kV.p.i][kV.p.j];
         int d1 = kV.d % 2;
         int id2 = toId[kH.p.i][kH.p.j];
         int d2 = kH.d % 2;
         g[id1*2+!d1].push_back(id2*2+d2);
         g[id2*2+!d2].push_back(id1*2+d1);
       }
     }
   }
   // どっちにしても照らせないマスが出るなら無理
   REP(id, ps.size()) {
     if(states[id] == 0) {
       puts(IMPOSSIBLE);
       return;
     }
   }
   bool possible = solve2SAT(0);
   if(possible) {
     REP(id, ps.size()) {
       int s = states[id];
       if(s == (1 << 0)) {
         buf[ps[id].i][ps[id].j] = '|';
       } else if(s == (1 << 1)) {
         buf[ps[id].i][ps[id].j] = '-';
       } else {
         assert(false);
       }
     }
     // 各マスを照らせるかを確かめる
     REP(i, nRow) REP(j, nCol) {
       if(buf[i][j] == '.') {
         K ks[4];
         REP(d, 4) {
           ks[d] = go(i, j, d);
         }
         K kH = ks[1].isPossible() ? ks[1] : ks[3];
         K kV = ks[0].isPossible() ? ks[0] : ks[2];
         if(!kH.isPossible() && !kV.isPossible()) {
           puts(IMPOSSIBLE);
           return;
         }
       }
     }
   }
   if(possible) {
     puts(POSSIBLE);
     REP(i, nRow)
       puts(buf[i]);
   } else {
     puts(IMPOSSIBLE);
   }
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     printf("Case #%d: ", iCase+1);
     scanf("%d%d", &nRow, &nCol);
     REP(i, nRow) {
       scanf("%s", buf[i]);
     }
     solve();
   }
   return 0;
 }
