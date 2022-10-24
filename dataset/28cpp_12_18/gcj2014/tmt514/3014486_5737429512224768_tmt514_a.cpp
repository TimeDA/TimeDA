#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 int a[100005];
 void solve() {
   int n, S;
   scanf("%d%d", &n, &S);
   for(int i=0;i<n;i++) scanf("%d", &a[i]);
   sort(a, a+n);
   int ans = n;
   for(int i=0,j=n-1;i<=j;i++) {
     while(i<j && a[i]+a[j]>S) --j;
     if(i<j) { --ans; --j; }
   }
   printf("Case #%d: %d\n", cs, ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
