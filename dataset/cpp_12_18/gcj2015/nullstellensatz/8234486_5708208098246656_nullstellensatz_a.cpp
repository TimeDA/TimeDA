
 
 
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
 using namespace std;
 
 const int MaxN = 105;
 
 int T, n, m;
 char grid[MaxN][MaxN];
 int cnt[MaxN][MaxN];
 
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
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> n >> m;
         for (int k = 0; k < n; ++ k)
             cin >> grid[k];
         
         memset(cnt, 0, sizeof cnt);
         int ans = 0;
         for (int i = 0; i < n; ++ i) {
             for (int j = 0; j < m; ++ j)
                 if (grid[i][j] != '.') {
                     ++ cnt[i][j];
                     if (grid[i][j] == '<') ++ ans;
                     break;
                 }
             for (int j = m - 1; j >= 0; -- j)
                 if (grid[i][j] != '.') {
                     ++ cnt[i][j];
                     if (grid[i][j] == '>') ++ ans;
                     break;
                 }
         }
         for (int j = 0; j < m; ++ j) {
             for (int i = 0; i < n; ++ i)
                 if (grid[i][j] != '.') {
                     ++ cnt[i][j];
                     if (grid[i][j] == '^') ++ ans;
                     break;
                 }
             for (int i = n - 1; i >= 0; -- i)
                 if (grid[i][j] != '.') {
                     ++ cnt[i][j];
                     if (grid[i][j] == 'v') ++ ans;
                     break;
                 }
         }
         
         bool check = false;
         for (int i = 0; i < n; ++ i)
             for (int j = 0; j < m; ++ j)
                 if (cnt[i][j] == 4) check = true;
             
         cout << "Case #" << testcase << ": ";
         if (check) cout << "IMPOSSIBLE\n"; else cout << ans << endl;
     }
     
     return 0;
 }
