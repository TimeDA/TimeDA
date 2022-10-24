
 
 
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
 
 const int MaxN = 1050;
 const int dx[4] = {-1,  0,  0,  1};
 const int dy[4] = { 0, -1,  1,  0};
 
 int T, m, r, c, s, t;
 string city[35];
 int sx[15], sy[15], tx[15], ty[15], d[35][35], qx[MaxN], qy[MaxN];
 int ss[MaxN][MaxN], tt[MaxN][MaxN];
 bool f[MaxN][MaxN], check[MaxN][15][15], v[35][35], p[35][35];
 
 int count(int num) {
     int res = 0;
     while (num) {
         ++ res;
         num -= (num & -num);
     }
     return res;
 }
 
 bool bfs(int dt, int ti, int si) {
     if (dt & (1 << ti)) return false;
     memset(v, 0, sizeof v);
     memset(p, 1, sizeof p);
     for (int k = 0; k < t; ++ k) {
         int px = tx[k], py = ty[k];
         if (k == ti) {
             for (int j = py; j >= 0; -- j) {
                 if (city[px][j] == '#') break;
                 v[px][j] = true;
             }
             for (int j = py; j < c; ++ j) {
                 if (city[px][j] == '#') break;
                 v[px][j] = true;
             }
             for (int i = px; i >= 0; -- i) {
                 if (city[i][py] == '#') break;
                 v[i][py] = true;
             }
             for (int i = px; i < r; ++ i) {
                 if (city[i][py] == '#') break;
                 v[i][py] = true;
             }
         }
         if (!(dt & (1 << k))) {
             for (int j = py; j >= 0; -- j) {
                 if (city[px][j] == '#') break;
                 p[px][j] = false;
             }
             for (int j = py; j < c; ++ j) {
                 if (city[px][j] == '#') break;
                 p[px][j] = false;
             }
             for (int i = px; i >= 0; -- i) {
                 if (city[i][py] == '#') break;
                 p[i][py] = false;
             }
             for (int i = px; i < r; ++ i) {
                 if (city[i][py] == '#') break;
                 p[i][py] = false;
             }
         }
     }
     
     qx[0] = sx[si]; qy[0] = sy[si];
     int ql = 0, qr = 1;
     memset(d, -1, sizeof d);
     d[qx[0]][qy[0]] = 0;
     while (ql < qr) {
         int cx = qx[ql], cy = qy[ql];
         ++ ql;
         if (v[cx][cy]) return d[cx][cy] <= m;
         if (p[cx][cy]) {
             for (int k = 0; k < 4; ++ k) {
                 int nx = cx + dx[k], ny = cy + dy[k];
                 if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                 if (city[nx][ny] == '#' || d[nx][ny] >= 0) continue;
                 qx[qr] = nx; qy[qr] = ny;
                 d[nx][ny] = d[cx][cy] + 1;
                 ++ qr;
             }
         }
     }
     
     return false;
 }
 
 void attack(int ct, int cs) {
     if (ct == 0 || cs == 0) return;
     attack(ct ^ (1 << tt[ct][cs]), cs ^ (1 << ss[ct][cs]));
     printf("%d %d\n", ss[ct][cs] + 1, tt[ct][cs] + 1);
     
     return;
 }
 
 void print(int ans) {
     for (int k = 0; k < (1 << t); ++ k)
         for (int q = 0; q < (1 << s); ++ q)
             if (f[k][q] && count(k) == ans) {
                 attack(k, q);
                 return;
             }
     return;
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
         cin >> c >> r >> m;
         s = t = 0;
         for (int i = 0; i < r; ++ i) {
             cin >> city[i];
             for (int j = 0; j < c; ++ j) {
                 if (city[i][j] == 'S') {
                     sx[s] = i; sy[s] = j;
                     ++ s;
                 }
                 if (city[i][j] == 'T') {
                     tx[t] = i; ty[t] = j;
                     ++ t;
                 }
             }
         }
         
         for (int k = 0; k < (1 << t); ++ k)
             for (int i = 0; i < t; ++ i)
                 for (int j = 0; j < s; ++ j)
                     check[k][i][j] = bfs(k, i, j);
         memset(f, 0, sizeof f);
         memset(tt, 0, sizeof tt);
         memset(ss, 0, sizeof ss);
         f[0][0] = true;
         int ans = 0;
         for (int k = 0; k < (1 << t); ++ k)
             for (int q = 0; q < (1 << s); ++ q) {
                 for (int i = 0; i < t; ++ i) {
                     if (!(k & (1 << i))) continue;
                     int cc = k ^ (1 << i);
                     for (int j = 0; j < s; ++ j) {
                         if (!(q & (1 << j))) continue;
                         if (check[cc][i][j] && f[cc][q ^ (1 << j)]) {
                             f[k][q] = true;
                             tt[k][q] = i;
                             ss[k][q] = j;
                         }
                     }
                 }
                 if (f[k][q]) ans = max(ans, count(k));
             }
         
         printf("Case #%d: %d\n", testcase, ans);
         print(ans);
     }
     
     return 0;
 }
