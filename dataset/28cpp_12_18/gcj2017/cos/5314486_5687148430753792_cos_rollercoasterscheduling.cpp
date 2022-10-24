#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 
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
 
 int n, c, m;
 pair<int, int> tickets[1010];
 int cnts[1010];
 
 void solve() {
   MEMSET(cnts, 0);
   scanf("%d %d %d", &n, &c, &m);
   REP(i, m) {
     scanf("%d %d", &tickets[i].first, &tickets[i].second);
     // tickets[i].first--;
     tickets[i].second--;
   }
   sort(tickets, tickets + m);
   int coaster = 0;
   REP(i, m) {
     int pos = tickets[i].first;
     int custmer = tickets[i].second;
     // cout << custmer << " " << cnts[custmer] << " " << coaster << endl;
     if (coaster <= cnts[custmer]) { coaster++; }
     // cout << pos * coaster << " " << i + 1<< endl;
     if (pos * coaster < i + 1) { coaster++; }
     cnts[custmer]++;
   }
   int promotion = 0;
   int prev = -1;
   int use = 0;
   REP(i, m) {
     int pos = tickets[i].first;
     if (prev != pos) { use = 0; }
     if (use >= coaster) { promotion++; }
     prev = pos;
     use++;
   }
   printf("%d %d\n", coaster, promotion);
 }
