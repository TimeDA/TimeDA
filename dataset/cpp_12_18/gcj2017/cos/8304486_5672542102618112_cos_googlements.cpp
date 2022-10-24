#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <set>
 #include <iostream>
 
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
     // puts("");
     solve();
   }
 }
 
 int n;
 set<int> open;
 void calc(const int &str);
 void dfs(int &nstr, vector<int> &values, int depth) {
   if (depth == n) {
     calc(nstr);
     return;
   }
   REP(i, n + 1) {
     if (values[i] == 0) { continue; }
     nstr = nstr * 10 + i;
     values[i]--;
     dfs(nstr, values, depth + 1);
     values[i]++;
     nstr /= 10;
   }
 }
 
 void calc(const int &str) {
   if (open.count(str)) { return; }
   open.insert(str);
   // cout << str << endl;
   vector<int> values(n + 1, 0);
   int total = 0;
   int temp = str;
   REP(i, n) {
     values[n - i] = temp % 10;
     temp /= 10;
     total += values[n - i];
     assert(values[n - i] <= n);
   }
   if (total > n) { return; }
   values[0] = n - total;
   assert(total != 0);
   int nstr = 0;
   dfs(nstr, values, 0);
 }
 
 void solve() {
   open.clear();
   string str;
   cin >> str;
   n = str.size();
   int v = atoi(str.c_str());;
   calc(v);
   printf("%d\n", (int)open.size());
 }
