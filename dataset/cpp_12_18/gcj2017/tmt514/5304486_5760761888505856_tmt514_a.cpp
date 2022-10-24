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
 
 char a[105][105];
 int n, m;
 int cs;
 
 void solve() {
   scanf("%d%d", &n, &m);
   for(int i=0;i<n;i++) scanf("%s", a[i]);
   for(int i=0;i<n;i++) {
     for(int j=0;j<m;j++) {
       if(a[i][j]!='?') {
         for(int k=j-1;j>=0 && a[i][k]=='?';k--)
           a[i][k] = a[i][j];
       }
     }
     for(int j=0;j<m;j++) if(a[i][j]!='?')
       for(int k=j+1;j<m && a[i][k]=='?';k++)
         a[i][k] = a[i][j];
   }
   for(int i=0;i<n;i++) if(a[i][0]!='?') {
     for(int j=i+1;j<n && a[j][0]=='?';j++)
       for(int k=0;k<m;k++) a[j][k] = a[i][k];
   }
   for(int i=0;i<n;i++) if(a[i][0]!='?') {
     for(int j=i-1;j>=0 && a[j][0]=='?';j--)
       for(int k=0;k<m;k++) a[j][k] = a[i][k];
   }
   printf("Case #%d:\n", ++cs);
   fprintf(stderr, "Case #%d:\n", cs);
   for(int i=0;i<n;i++) {
     printf("%s\n", a[i]);
   }
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
