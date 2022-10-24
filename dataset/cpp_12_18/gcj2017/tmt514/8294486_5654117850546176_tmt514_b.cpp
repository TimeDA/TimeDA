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
 
 enum { red = 0, orange, yellow, green, blue, violet };
 int start = 0;
 char t[8] = "ROYGBV";
 
 int tooclose(int x, int y) {
   return abs(x-y)<=1 || abs(x-y)>=5;
 }
 
 #include <map>
 #include <cassert>
 map<vector<int>, int> dp;
 bool go(vector<int> s) {
   if(dp.find(s) != dp.end()) return dp[s];
   int &ret = dp[s];
 
   int head = s[6];
   int tail = s[7];
   if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]==1) {
     // check and return
     for(int i=0;i<6;i++) if(s[i]) {
       if(tooclose(i, head) || tooclose(i, tail))
         return (ret=false);
     }
     return (ret=true);
   }
   for(int i=0;i<6;i++) {
     if(s[i] && !tooclose(i, tail)) {
       s[i]--;
       s[7] = i;
       if(go(s))
         return (ret=true);
       s[7] = tail;
       s[i]++;
     }
   }
   return (ret=false);
 }
 void output(vector<int> s) {
   int tail = s[7];
   if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]==1) {
     // check and return
     for(int i=0;i<6;i++) if(s[i]) {
       putchar(t[i]);
       fprintf(stderr, "%c", t[i]);
       return;
     }
     assert("Warning!!!! output empty!!!" && false);
     return;
   }
   
   for(int i=0;i<6;i++) {
     if(s[i] && !tooclose(i, tail)) {
       s[i]--;
       s[7] = i;
       if(go(s)) { // shouldn't recursive
         putchar(t[i]);
         fprintf(stderr, "%c", t[i]);
         output(s);
         return;
       }
       s[7] = tail;
       s[i]++;
     }
   }
     assert("Warning!!!! output empty!!! 2222" && false);
     return;
   
 }
 
 void solve() {
   int N, R, O, Y, G, B, V;
   cin >> N >> R >> O >> Y >> G >> B >> V;
   if(R) start = red, R--;
   else if(O) start = orange, O--;
   else if(Y) start = yellow, Y--;
   else if(G) start = green, G--;
   else if(B) start = blue, B--;
   else if(V) start = violet, V--;
   
   static int cs = 0;
   printf("Case #%d: ", ++cs);
   fprintf(stderr, "Case #%d: ", cs);
   if(go({R, O, Y, G, B, V, start, start})) {
     putchar(t[start]);
     fprintf(stderr, "%c", t[start]);
     output({R, O, Y, G, B, V, start, start});
     printf("\n");
     fprintf(stderr, "\n");
   } else {
     printf("IMPOSSIBLE\n");
     fprintf(stderr, "IMPOSSIBLE\n");
   }
 }
 
 int main(void) {
   int T;
   cin >> T;
   while(T--) solve();
   return 0;
 }
