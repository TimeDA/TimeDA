#include <bits/stdc++.h>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 const int N = 12;
 char ans[(1 << N) + 100];
 char tmp[(1 << N) + 100];
 
 char getWinner(int R, int P, int S) {
   if (R) { return 'R'; }
   if (P) { return 'P'; }
   if (S) { return 'S'; }
   assert(0); 
 }
 
 bool solve(int n, int R, int P, int S, int step) {
   dbg("n %d R %d P %d S %d step %d\n", n, R, P, S, step);
   assert(R + P + S == (1 << n));
   if (n == 0) {
     ans[0] = getWinner(R, P, S);
     return true;
   }
   int p = (1 << (n - 1)) - S; // RP => P
   int r = (1 << (n - 1)) - P; // RS => R
   int s = (1 << (n - 1)) - R; // PS => S
   if (r < 0 || s < 0 || p < 0) { return false; }
   if (!solve(n - 1, r, p, s, step * 2)) {
     return false;
   }
   dbg("ans %s\n", ans);
   for (int i = 0; i < (1 << n) * step; i += step * 2) {
     if (ans[i] == 'R') {
       ans[i] = 'R';
       ans[i + step] = 'S';
     } else if (ans[i] == 'P') {
       ans[i] = 'P';
       ans[i + step] = 'R';
     } else if (ans[i] == 'S') {
       ans[i] = 'P';
       ans[i + step] = 'S';
     } else {
       assert(0);
     }
   }
   dbg("ans %s\n", ans);
   return true;
 }
 
 void sortAns(int L, int R) {
   if (L + 1 == R) {
     return;
   }
   int M = (L + R) / 2;
   sortAns(L, M);
   sortAns(M, R);
   int n = M - L;
   dbg("L %d R %d s %s\n", L, R, ans);
   if (strncmp(ans + L, ans + L + n, n) > 0) {
     memcpy(tmp, ans + L + n, n);
     memcpy(ans + L + n, ans, n);
     memcpy(ans, tmp, n);
   }
   dbg("L %d R %d s %s\n", L, R, ans);
 }
 
 char check(const char *L, const char *R) {
 //  dbg("%d %d\n", int(L - ans), int(R - ans));
   if (L + 1 == R) {
     return L[0];
   }
   const char *M = L + (R - L) / 2;
   char X = check(L, M);
   char Y = check(M, R);
   if (X == Y || X == 0 || Y == 0) { return 0; }
   char Z = X ^ Y ^ 'R' ^ 'P' ^ 'S';
   if (Z == 'S') {
     return 'P';
   } else if (Z == 'R') {
     return 'S';
   } else if (Z == 'P') {
     return 'R';
   }
   assert(0);
 }
 
 void solveStupid(int R, int P, int S) {
   int k = 0;
   while (P) {
     ans[k++] = 'P';
     --P;
   }
   while (R) {
     ans[k++] = 'R';
     --R;
   }
   while (S) {
     ans[k++] = 'S';
     --S;
   }
   ans[k] = 0;
   do {
     char winner = check(ans, ans + k);
     dbg("%s => %c\n", ans, winner ? winner : '0');
     if (winner) {
       printf("%s\n", ans);
       return;
     }
   } while (next_permutation(ans, ans + k));
   printf("IMPOSSIBLE\n");
 }
 
 void solve() {
   int n, R, P, S;
   scanf("%d%d%d%d", &n, &R, &P, &S);
   solveStupid(R, P, S);
   return;
   for (int i = 0; i < (1 << n); ++i) {
     ans[i] = '?';
   }
   ans[1 << n] = 0;
   if (solve(n, R, P, S, 1)) {
     sortAns(0, 1 << n);
     printf("%s\n", ans);
   } else {
     printf("IMPOSSIBLE\n");
   }
 }
 
 int main()
 {
 #ifdef DBG1
   assert(freopen("input.txt", "r", stdin));
   assert(freopen("output.txt", "w", stdout));
   assert(freopen("err.txt", "w", stderr));
 #endif
 
   int tt;
   assert (scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case %d\n", ii);
     printf("Case #%d: ", ii);
     solve();
     fflush(stdout);
   }
 
   return 0;
 }
 
