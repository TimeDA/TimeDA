#include <cstdio>
 #include <cassert>
 #include <tuple>
 #include <string>
 using namespace std;
 
 const int N = 12;
 
 string S[N + 1][3];
 char win[N + 1][3];
 
 char who(char x, char y) {
     if (x == y)
         return -1;
     if (x == 'P')
         return (y == 'R') ? x : y;
     if (x == 'R')
         return (y == 'S') ? x : y;
     if (x == 'S')
         return (y == 'P') ? x : y;
     assert(false);
 }
 
 void init() {
     S[0][0] = "P";
     S[0][1] = "R";
     S[0][2] = "S";
     win[0][0] = 'P';
     win[0][1] = 'R';
     win[0][2] = 'S';
     for (int d = 0; d < N; d++) {
         int  pt = 0;
         for (int i = 0; i < 3; i++) {
             for (int j = 0; j < i; j++) {
                 char ci = win[d][i];
                 char cj = win[d][j];
                 if (who(ci, cj) != -1) {
                     assert(pt < 3);
                     string si = S[d][i];
                     string sj = S[d][j];
                     S[d + 1][pt] = min(si, sj) + max(si, sj);
                     win[d + 1][pt++] = who(ci, cj);
                 }
             }
         }
     }
 }
 
 tuple<int, int, int> calc(string S) {
     int a = 0, b = 0, c = 0;
     for (char x : S) {
         if (x == 'P')
             a++;
         if (x == 'S')
             b++;
         if (x == 'R')
             c++;
     }
     return make_tuple(a, c, b);
 }
 
 void solve(int cs) {
     int n, p, r, s;
     scanf("%d %d %d %d", &n, &r, &p, &s);
     string best = "";
     for (int i = 0; i < 3; i++) {
         auto tp = calc(S[n][i]);
         if (tp == make_tuple(p, r, s)) {
             if (best.empty() || best > S[n][i])
                 best = S[n][i];
         }
     }
     if (best.empty()) {
         printf("Case #%d: IMPOSSIBLE\n", cs);
     } else {
         printf("Case #%d: %s\n", cs, best.data());
     }
 }
 
 int main() {
     init();
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
