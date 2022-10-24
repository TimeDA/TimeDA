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
     solve();
   }
 }
 
 ll calc(ll n, ll p) {
   if (p == -1) { return -1; }
   ll zero = 0;
   ll left = 0;
   REP(i, n) {
     if (p & 1LL) { left = i; }
     else { zero++; }
     p >>= 1LL;
   }
  ll cnt = 1LL << min(zero, n - left);
  return (1LL << n) - cnt;
 }
 ll n, p;
 void solve() {
   scanf("%lld %lld", &n, &p);
   p--;
   ll revP = (1LL << n) - p - 2;
   //cout << revP << " " << calc(n, revP) << endl;
   ll ans_independent = (1LL << n) - 2 - calc(n, revP);
   ll ans_dependent = calc(n, p);
   printf("%lld %lld\n", ans_independent, ans_dependent);
 }
