#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 //#include "testlib.h"
 #include <bits/stdc++.h>
 using namespace std;
 
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve(bool);
 void precalc();
 clock_t start;
 int main() {
 #ifdef AIM
   freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
   freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
   //freopen("out.txt", "w", stdout);
 #else
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
 #endif
   start = clock();
   int t = 1;
   cout.sync_with_stdio(0);
   cin.tie(0);
   precalc();
   cout.precision(10);
   cout << fixed;
   cin >> t;
   int testNum = 1;
   while (t--) {
     cout << "Case #" << testNum++ << ": ";
     solve(true);
     //cerr << testNum - 1 << endl;
   }
   cout.flush();
 #ifdef AIM1
   while (true) {
       solve(false);
   }
 #endif
 
 #ifdef AIM
   cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
   return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 template<typename T>
 T binpow(T q, T w, T mod) {
   if (!w)
     return 1 % mod;
   if (w & 1)
     return q * 1LL * binpow(q, w - 1, mod) % mod;
   return binpow(q * 1LL * q % mod, w / 2, mod);
 }
 
 template<typename T>
 T gcd(T q, T w) {
   while (w) {
     q %= w;
     swap(q, w);
   }
   return q;
 }
 template<typename T>
 T lcm(T q, T w) {
   return q / gcd(q, w) * w;
 }
 
 void precalc() {
 
 }
 
 template<typename T>
 void relax_min(T& cur, T val) {
   cur = min(cur, val);
 }
 
 template<typename T>
 void relax_max(T& cur, T val) {
   cur = max(cur, val);
 }
 
 //const int mod = 1000000007;
 //#define int li
 
 int L;
 set<vector<int>> pure;
 
 void rec(vector<int> nums) {
   if (pure.count(nums)) {
     return;
   }
   pure.insert(nums);
   vector<int> now;
   for (int i = 0; i < L; ++i) {
     for (int j = 0; j < nums[i]; ++j) {
       now.push_back(i + 1);
     }
   }
   if (now.size() > L) {
     return;
   }
   while (now.size() < L) {
     now.push_back(0);
   }
   sort(all(now));
   do {
     rec(now);
   }
   while (next_permutation(all(now)));
 }
 
 vector<int> get_repr(vector<int> vec) {
   vector<int> res(L);
   for (int x : vec) {
     if (x) {
       ++res[x - 1];
     }
   }
   return res;
 }
 
 void solve(bool read) {
   string s;
   cin >> s;
   L = (int)s.length();
   vector<int> nums(L);
   for (int i = 0; i < L; ++i) {
     nums[i] = s[i] - '0';
   }
   pure.clear();
   rec(nums);
   cout << pure.size() << endl;
 
 }
