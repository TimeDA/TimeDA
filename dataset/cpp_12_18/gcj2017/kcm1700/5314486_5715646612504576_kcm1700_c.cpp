#include <cstdio>
 #include <algorithm>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <queue>
 #include <numeric>
 #include <functional>
 #include <set>
 #include <map>
 
 using namespace std;
 
 char buffer[1048576];
 
 struct TwoSat
 {
   int n;
   int var;
   vector<vector<int>> graph;
   vector<vector<int>> grev;
 
   int vcnt;
   vector<int> v;
 
   void init(int var_) {
     var = var_;
     n = var_ * 2;
     graph.clear(); graph.resize(n);
     grev.clear(); grev.resize(n);
 
     vcnt = 0;
     v.clear(); v.resize(n);
   }
 
   int negation(int nod) const {
     return nod >= var ? nod - var : nod + var;
   }
 
   // p implies q. p -> q
   void add(int p, int q) {
     graph[p].push_back(q);
     graph[negation(q)].push_back(negation(p));
     grev[q].push_back(p);
     grev[negation(p)].push_back(negation(q));
   }
 
   // and (p or q)
   void addCNF(int p, int q) {
     add(negation(p), q);
   }
 
   vector<int> emit;
   void dfs(int nod, vector<vector<int>> &graph) {
     v[nod] = vcnt;
     for (int next : graph[nod]) {
       if (v[next] == vcnt) continue;
       dfs(next, graph);
     }
     emit.push_back(nod);
   }
 
   vector<bool> solve() {
     vector<bool> solution(var);
     vector<int> scc_check(n);
     int scc_index = 0;
 
     ++vcnt;
     emit.clear();
     for (int i = 0; i < n; i++) {
       if (v[i] == vcnt) continue;
       dfs(i, graph);
     }
 
     ++vcnt;
     for (auto start : vector<int>(emit.rbegin(), emit.rend())) {
       if (v[start] == vcnt) continue;
       emit.clear();
       dfs(start, grev);
       ++scc_index;
       for (auto node : emit) {
         scc_check[node] = scc_index;
         if (scc_check[negation(node)] == scc_index) {
           // contradiction found
           solution.clear();
           return solution;
         }
         solution[node >= var ? node - var : node] = (node < var);
       }
     }
 
     return solution;
   }
 };
 
 vector<string> board;
 vector<vector<int>> shoot;
 
 const int dir[4][2] = {
   -1, 0,
   0, 1,
   1, 0,
   0, -1
 };
 
 int turn_dir(int d, char mirror) {
   if (mirror == '/') {
     // 0,1,2,3
     // 1,0,3,2
     return d ^ 1;
   }
   else {
     // 0,1,2,3
     // 3,2,1,0
     return 3 - d;
   }
 }
 
 int follow_path(const TwoSat &ts, int r, int c, int d) {
   int n = board.size(), m = board[0].length();
   for(int cnt = 0;; cnt++) {
     if (r < 0 || c < 0 || r >= n || c >= m) return -1;
     if (board[r][c] == '#')
       return -1;
     if (board[r][c] == '-' || board[r][c] == '|') {
       if (cnt > 0) {
         if (d == 0 || d == 2) {
           return ts.negation(shoot[r][c]);
         }
         return shoot[r][c];
       }
     }
     if (board[r][c] == '/' || board[r][c] == '\\') {
       d = turn_dir(d, board[r][c]);
     }
     r += dir[d][0];
     c += dir[d][1];
   }
   return -1;
 }
 
 // 0: vert, 1: hori
 pair<int, int> find_other_shoot(const TwoSat &ts, int r, int c, int way) {
   int ans1 = -1, ans2 = -1;
   if (way == 0) {
     ans1 = follow_path(ts, r, c, 0);
     ans2 = follow_path(ts, r, c, 2);
   }
   else {
     ans1 = follow_path(ts, r, c, 1);
     ans2 = follow_path(ts, r, c, 3);
   }
   return make_pair(ans1, ans2);
 }
 
 int get_either(int a, int b) {
   if (a == -1) return b;
   return a;
 }
 vector<string> solve() {
   vector<string> ans;
   int n = board.size(), m = board[0].length();
   shoot.assign(n, vector<int>(m, -1));
   int shootcnt = 0;
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
       if (board[i][j] == '-' || board[i][j] == '|') {
         shoot[i][j] = shootcnt++;
       }
     }
   }
   TwoSat ts;
   ts.init(shootcnt);
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
       if (shoot[i][j] != -1) {
         pair<int, int> vert = find_other_shoot(ts, i, j, 0);
         pair<int, int> hori = find_other_shoot(ts, i, j, 1);
         if (vert.first != -1 || vert.second != -1) {
           ts.addCNF(shoot[i][j], shoot[i][j]);
         }
         if (hori.first != -1 || hori.second != -1) {
           ts.addCNF(ts.negation(shoot[i][j]), ts.negation(shoot[i][j]));
         }
       }
       else if (board[i][j] == '.') {
         pair<int, int> vert = find_other_shoot(ts, i, j, 0);
         pair<int, int> hori = find_other_shoot(ts, i, j, 1);
         int ver = get_either(vert.first, vert.second);
         int hor = get_either(hori.first, hori.second);
         if (ver == -1 && hor == -1) return ans;
         else if (ver == -1) {
           ts.addCNF(hor, hor);
         }
         else if (hor == -1) {
           ts.addCNF(ver, ver);
         }
         else {
           ts.add(ts.negation(ver), hor);
           ts.add(ts.negation(hor), ver);
         }
       }
     }
   }
   auto res = ts.solve();
   if (ts.n > 0 && res.empty()) return ans;
   ans = board;
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
       if (shoot[i][j] != -1) {
         if (res[shoot[i][j]]) {
           ans[i][j] = '-';
         }
         else {
           ans[i][j] = '|';
         }
       }
     }
   }
   return ans;
 }
 
 int main() {
   int TT;
   scanf("%d", &TT);
   for (int testcase = 1; testcase <= TT; testcase++) {
     int n, m;
     scanf("%d%d", &n, &m);
     vector<string> board;
     for (int i = 0; i < n; i++) {
       scanf("%s", buffer);
       board.emplace_back(buffer);
     }
     ::board = board;
     vector<string> ans = solve();
     if (ans.empty()) {
       printf("Case #%d: IMPOSSIBLE\n", testcase);
       continue;
     }
     else {
       printf("Case #%d: POSSIBLE\n", testcase);
       for (int i = 0; i < n; i++) {
         printf("%s\n", ans[i].c_str());
       }
     }
   }
   return 0;
 }