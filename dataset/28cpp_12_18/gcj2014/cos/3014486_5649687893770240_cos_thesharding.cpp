#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <set>
 
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
 
 int n, m;
 string strs[1000];
 int ans;
 int cnt;
 
 int makeTrie(const set<string> &t) {
   set<string> s;
   s.insert("");
   FORIT(it, t) {
     string str = "";
     REP(i, it->size()) {
       str += it->at(i);
       s.insert(str);
     }
   }
   return s.size();
 }
 
 void calc(vector<set<string> > &ts,  int index) {
   if (index == n) {
     int sum = 0;
     REP(i, m) {
       if (ts[i].empty()) { return; }
       sum += makeTrie(ts[i]);
     }
     if (sum > ans) { 
       ans = sum;
       cnt = 1;
     } else if (sum == ans) { cnt++; }
   } else {
     REP(i, m) {
       ts[i].insert(strs[index]);
       calc(ts, index + 1);
       ts[i].erase(strs[index]);
     }
   }
 }
 
 void solve() {
   ans = 0;
   cnt = -1;
   scanf("%d %d", &n, &m);
   REP(i, n) {
     cin >> strs[i];
   }
   vector<set<string> > ts(n);
   calc(ts, 0);
   cout << ans << " " << cnt << endl;
 }
