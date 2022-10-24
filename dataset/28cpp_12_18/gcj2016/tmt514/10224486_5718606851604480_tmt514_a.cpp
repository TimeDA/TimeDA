// by tmt514
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 int cs=0;
 string a[3][15];
 int counts[3][15][3];
 
 const int P = 0, R = 1, S = 2;
 
 bool correctcount(int i, int n, int r, int p, int s) {
    
   return counts[i][n][P] == p && counts[i][n][R] == r && counts[i][n][S] == s;
 }
 void solve() {
   ++cs;
   fprintf(stderr, "Case #%d: ", cs);
   printf("Case #%d: ", cs);
 
   int n, r, p, s;
   scanf("%d%d%d%d", &n, &r, &p, &s);
   string sol = "z";
   for(int i=0;i<3;i++) {
     if(correctcount(i, n, r, p, s)) {
       if (sol > a[i][n])
         sol = a[i][n];
     }
   }
   if(sol == "z") {
     printf("IMPOSSIBLE\n");
     fprintf(stderr, "IMPOSSIBLE\n");
   }
   else {
     printf("%s\n", sol.c_str());
     fprintf(stderr, "%s\n", sol.c_str());
   }
 
 
 }
 
 string concat(string x, string y) {
   if (x < y) return x+y;
   return y+x;
 }
 void pre() {
   a[P][0] = "P";
   a[R][0] = "R";
   a[S][0] = "S";
   for(int n=1;n<=12;n++) {
     a[P][n] = concat(a[P][n-1], a[R][n-1]);
     a[R][n] = concat(a[R][n-1], a[S][n-1]);
     a[S][n] = concat(a[S][n-1], a[P][n-1]);
   }
   for(int i=0;i<3;i++)
     for(int j=0;j<=12;j++)
       for(int k=0;k<(int)a[i][j].size();k++)
     {
       if(a[i][j][k] == 'P') counts[i][j][P]++;
       if(a[i][j][k] == 'R') counts[i][j][R]++;
       if(a[i][j][k] == 'S') counts[i][j][S]++;
     }
 }
 
 
 int main(void) {
   int T;
   scanf("%d", &T);
   pre();
   while(T--) solve();  
   return 0;
 }
