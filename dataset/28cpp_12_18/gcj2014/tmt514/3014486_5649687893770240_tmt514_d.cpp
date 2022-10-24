#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <iostream>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 int M, N;
 string s[1005];
 int best = 0, cnt = 0;
 
 int get(int f) {
   set<string> r;
   for(int i=0;i<M;i++) if(f&(1<<i)) {
     for(int j=0;j<SZ(s[i]);j++) r.insert(s[i].substr(0, j+1));
   }
   return SZ(r) + 1;
 }
 
 void go(int x, int mask, int now) {
   if(x==1) {
     if(mask == (1<<M)-1) return;
     now += get((1<<M)-1-mask);
     if(now > best) { best = now; cnt = 0; }
     if(best == now) ++cnt;
     return;
   }
   int cmask = (1<<M)-1-mask;
   for(int i=cmask;i>0;i=((i-1)&cmask)) {
     go(x-1, mask+i, now+get(i));
   }
 }
 
 void solve() {
   scanf("%d%d", &M, &N);
   for(int i=0;i<M;i++) cin >> s[i];
   sort(s, s+M);
   cnt = 0; best = 0;
   go(N, 0, 0);
   printf("Case #%d: %d %d\n", cs, best, cnt);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
