
 
 
 /*
     Prob:
     Author: 
     Time:   
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <string>
 using namespace std;
 
 const int MaxN = 205;
 
 int T, n, m, row, col, score;
 string str;
 char cell[MaxN][MaxN], ans[MaxN][MaxN];
 int cnt[4][MaxN], cr[2][MaxN][MaxN], match[2][MaxN];
 bool v[MaxN];
 
 bool dfs(int idx, int size, int cur) {
     for (int k = 1; k <= size; ++ k) {
         if (cr[idx][cur][k] && !v[k]) {
             v[k] = true;
             if (match[idx][k] < 0 || dfs(idx, size, match[idx][k])) {
                 match[idx][k] = cur;
                 return true;
             }
         }
     }
     return false;
 }
 
 int maxmatch(int idx, int size) {
     int res = 0;
     memset(match[idx], -1, sizeof match[idx]);
     for (int k = 1; k <= size; ++ k) {
         memset(v, 0, sizeof v);
         if (dfs(idx, size, k)) ++ res;
     }
     return res;
 }
 
 int main(int argc, char* argv[]) { 
     if (argc >= 2) {
         string post = argv[1][0] == 's' ? 
                       "-small-attempt" + string(argv[2]):
                       "-large";  
         string input_file  = string(argv[0]) + post + ".in",
                output_file = string(argv[0]) + post + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> n >> m;
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j)
                 cell[i][j] = ans[i][j] = '.';
         memset(cnt, 0, sizeof cnt);
         score = 0;
         for (int k = 1; k <= m; ++ k) {
             cin >> str >> row >> col;
             cell[row][col] = ans[row][col] = str[0];
             if (str[0] != '+') {
                 ++ cnt[0][row];
                 ++ cnt[1][col];
             }
             if (str[0] != 'x') {
                 ++ cnt[2][row - col + n];
                 ++ cnt[3][row + col];
             }
             score += (str[0] == 'o' ? 2 : 1);
         }
         
         memset(cr, 0, sizeof cr);
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j) {
                 if (cell[i][j] != 'x' && cell[i][j] != 'o')
                     cr[0][i][j] = (!cnt[0][i] && !cnt[1][j]);
                 if (cell[i][j] != '+' && cell[i][j] != 'o')
                     cr[1][i - j + n][i + j] = (!cnt[2][i - j + n] && !cnt[3][i + j]);
             }
         score += maxmatch(0, n);
         for (int k = 1; k <= n; ++ k) {
             if (match[0][k] < 0) continue;
             row = match[0][k]; col = k;
             ans[row][col] = (ans[row][col] == '.' ? 'x' : 'o');
         }
         score += maxmatch(1, n + n);
         for (int k = 1; k <= n + n; ++ k) {
             if (match[1][k] < 0) continue;
             row = (k + match[1][k] - n) >> 1;
             col = (k - match[1][k] + n) >> 1;
             ans[row][col] = (ans[row][col] == '.' ? '+' : 'o');
         }
         
         int num = 0;
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j)
                 if (cell[i][j] != ans[i][j]) ++ num;
         printf("Case #%d: %d %d\n", testcase, score, num);
         for (int i = 1; i <= n; ++ i)
             for (int j = 1; j <= n; ++ j)
                 if (cell[i][j] != ans[i][j]) printf("%c %d %d\n", ans[i][j], i, j);
     }
     
     return 0;
 }
