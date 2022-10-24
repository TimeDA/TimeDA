#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <map>
 
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
     solve();
   }
 }
 
 struct Event {
   ll end;
   ll pos;
   ll cnt;
   Event() {;}
   Event(ll end, ll pos, ll cnt) : end(end), pos(pos), cnt(cnt) {;}
   bool operator<(const Event &rhs) const {
     if (pos != rhs.pos) { return pos < rhs.pos; }
     return end < rhs.end;
   }
 };
 
 const ll MOD = 1000002013;
 ll n, m;
 
 ll CalcCost(ll s, ll e, ll c) {
   if (s == e) { return 0; }
   c %= MOD;
   ll dist = e - s;
   return (dist * (n + 1) - dist * (dist + 1) / 2) % MOD * c % MOD;
 }
 
 void solve() {
   vector<Event> events;
   scanf("%lld %lld", &n, &m);
   ll total = 0;
   REP(i, m) {
     ll s, e, c;
     scanf("%lld %lld %lld", &s, &e, &c);
     events.push_back(Event(0, s, c));
     events.push_back(Event(1, e, c));
     total = (total + CalcCost(s, e, c)) % MOD;
   }
   map<ll, ll> tickets;
   sort(events.begin(), events.end());
   ll ans = 0;
   FORIT(it, events) {
     Event e = *it;
     if (e.end) {
       while (e.cnt != 0) {
         ll start = tickets.rbegin()->first;
         ll use = min(e.cnt, tickets[start]);
         e.cnt -= use;
         tickets[start] -= use;
         if (tickets[start] == 0) { tickets.erase(start); }
         ans = (ans + CalcCost(start, e.pos, use)) % MOD;
       }
     } else {
       tickets[e.pos] += e.cnt;
     }
   }
   ans = (total - ans + MOD) % MOD;
   printf("%lld\n", ans);
 }
