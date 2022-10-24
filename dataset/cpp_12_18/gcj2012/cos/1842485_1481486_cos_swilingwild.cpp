#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <queue>
 
 using namespace std;
 typedef long long ll;
 typedef unsigned int uint;
 typedef unsigned long long ull;
 static const double EPS = 1e-9;
 static const double PI = acos(-1.0);
 
 #define REP(i, n) for (int i = 0; i < (int)(n); i++)
 #define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
 #define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
 #define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
 #define MEMSET(v, h) memset((v), h, sizeof(v))
 
 void solve();
 int main() {
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d: ", test_case);
     //puts("");
     solve();
   }
 }
 
 int n;
 ll d[10010];
 ll l[10010];
 ll D;
 ll length[10010];
 
 void solve() {
   MEMSET(length, 0);
   scanf("%d", &n);
   REP(i, n) {
     scanf("%lld %lld", &d[i], &l[i]);
   }
   scanf("%lld", &D);
   d[n] = D;
   l[n] = 0;
   priority_queue<pair<ll, int> > que;
   que.push(make_pair(d[0], 0));
   length[0] = d[0];
   while (!que.empty()) {
     ll len = que.top().first;
     int index = que.top().second;
     que.pop();
     if (length[index] != len) { continue; }
     //cout << len << " " << index << endl;
     REP(i, n + 1) {
       ll dist = abs(d[i] - d[index]);
       if (dist > len) { continue; }
       dist = min(dist, l[i]);
       if (i == n) {
         puts("YES");
         return;
       }
       if (length[i] >= dist) { continue; }
       length[i] = dist;
       que.push(make_pair(dist, i));
     }
   }
   puts("NO");
 }
