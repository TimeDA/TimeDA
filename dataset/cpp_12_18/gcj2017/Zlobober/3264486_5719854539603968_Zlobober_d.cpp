#include <cstdio>
 #include <cassert>
 #include <tuple>
 #include <vector>
 using namespace std;
 
 struct kuhn {
     vector<int> to;
     vector<vector<int>> E;
     vector<int> was;
     int curver;
     int n, m;
     kuhn(int n, int m) {
         init(n, m);
     }
     void init(int n, int m) {
         this->n = n;
         this->m = m;
         to.assign(m, -1);
         E.assign(n, vector<int>());
         curver = 0;
         was.assign(n, 0);
     }
     void add_edge(int a, int b) {
         E[a].push_back(b);
     }
     bool DFS(int x) {
         was[x] = curver;
         for (int y : E[x]) {
             if (to[y] == -1) {
                 to[y] = x;
                 return true;
             }
         }
         for (int y : E[x]) {
             if (to[y] == -1 || (was[to[y]] != curver && DFS(to[y]))) {
                 to[y] = x;
                 return true;
             }
         }
         return false;
     }
     void run() {
         vector<char> exclude(n, false);
         for (int i = 0; i < m; i++) {
             if (to[i] != -1)
                 exclude[to[i]] = true;
         }
         for (int i = 0; i < n; i++) {
             if (!exclude[i]) {
                 DFS(i);
                 ++curver;
             }
         }
     }
     vector<pair<int, int>> matching() {
         vector<pair<int, int>> ans;
         for (int i = 0; i < m; i++) {
             if (to[i] != -1)
                 ans.emplace_back(to[i], i);
         }
         return ans;
     }
 };
 
 void solve(int cs) {
     int n, m;
     scanf("%d %d", &n, &m);
     kuhn VH(n, n), D(2 * n - 1, 2 * n - 1);
     vector<vector<char>> F(n, vector<char>(n, '.'));
     vector<char> VHur(n, false), VHuc(n, false), Dup(2 * n - 1, false), Dum(2 * n - 1, false);
     for (int i = 0; i < m; i++) {
         char t;
         int r, c;
         scanf(" %c %d %d", &t, &r, &c);
         --r, --c;
         F[r][c] = t;
         if (t == 'x' || t == 'o') {
             VHur[r] = VHuc[c] = true;
         }
         if (t == '+' || t == 'o') {
             Dum[r - c + n - 1] = Dup[r + c] = true;
         }
     }
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (!VHur[i] && !VHuc[j])
                 VH.add_edge(i, j);
             if (!Dup[i + j] && !Dum[i - j + n - 1])
                 D.add_edge(i + j, i - j + n - 1);
         }
     }
     VH.run();
     D.run();
     auto VHm = VH.matching();
     auto Dm = D.matching();
     vector<vector<char>> nF = F;
     for (const auto& pr : VHm) {
         int r, c;
         tie(r, c) = pr;
         if (nF[r][c] == '.') {
             nF[r][c] = 'x';
         } else if (nF[r][c] == '+') {
             nF[r][c] = 'o';
         }
     }
     for (const auto& pr : Dm) {
         int rpc, rmc;
         tie(rpc, rmc) = pr;
         rmc -= n - 1;
         assert((rpc + rmc) % 2 == 0);
         int r, c;
         r = (rpc + rmc) / 2;
         c = (rpc - rmc) / 2;
         assert(0 <= r && r < n);
         assert(0 <= c && c < n);
         if (nF[r][c] == '.') {
             nF[r][c] = '+';
         } else if (nF[r][c] == 'x') {
             nF[r][c] = 'o';
         }
     }
     vector<tuple<char, int, int>> subst;
     int tot = 0;
     for (int i = 0; i < n; i++) {
         nF[i].push_back(0);
         fprintf(stderr, "%s\n", nF[i].data());
         for (int j = 0; j < n; j++) {
             tot += 2 * (nF[i][j] == 'o') + (nF[i][j] == 'x') + (nF[i][j] == '+');
             if (F[i][j] != nF[i][j]) {
                 subst.emplace_back(nF[i][j], i, j);
             }
         }
     }
     printf("Case #%d: %d %d\n", cs, tot, (int)subst.size());
     for (const auto& tp : subst) {
         char t;
         int r, c;
         tie(t, r, c) = tp;
         ++r, ++c;
         printf("%c %d %d\n", t, r, c);
     }
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
         fprintf(stderr, "%d\n", i);
     }
 }
