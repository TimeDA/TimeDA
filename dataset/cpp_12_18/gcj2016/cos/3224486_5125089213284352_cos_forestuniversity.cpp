// g++ -Wall hoge.cpp -lgmpxx -lgmp
 #include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 
 #include <gmpxx.h>
 
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
 
 struct Random {
   unsigned int x;
   unsigned int y;
   unsigned int z;
   unsigned int w; 
   Random() : x(0x34fb2383), y(0x327328fa), z(0xabd4b54a), w(0xa9dba8d1) {;}
   Random(int s) : x(0x34fb2383), y(0x327328fa), z(0xabd4b54a), w(s) {
     for (int i = 0; i < 100; i++) { Xor128(); }
   }
   void Seed(int s) {
     *this = Random(s);
   }
   unsigned int Xor128() {
     unsigned int t;
     t = x ^ (x << 11);
     x = y; y = z; z = w;
     return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
   }
   int next(int r) { return Xor128() % r; }
   int next(int l, int r) { return next(r - l + 1) + l; }
   ll next(ll r) { return (ll)((((unsigned long long)Xor128() << 32) + (unsigned long long)Xor128()) % r); }
   ll next(ll l, ll r) { return next(r - l + 1) + l; }
   double next(double r) { return (double)Xor128() / 0xffffffff * r; }
   double next(double l, double r) { return next(r - l) + l; }
   mpz_class next(mpz_class r) {
     mpz_class ret = Xor128();
     while (ret < r * 1000000000) {
       ret = (ret << 32) + Xor128();
     }
     return ret % r;
   }
   mpz_class next(mpz_class l, mpz_class r) { return next(r - l + 1) + l; }
 };
 Random rnd;
 
 // #define mpz_class int
 void solve();
 mpz_class combi[110][110];
 int main() {
   REP(i, 110) REP(j, 110) { combi[i][j] = 0; }
   combi[0][0] = 1;
   REP(i, 105) {
     REP(j, 105) {
       combi[i + 1][j] += combi[i][j];
       combi[i + 1][j + 1] += combi[i][j];
     }
   }
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d:", test_case);
     // puts("");
     solve();
   }
 }
 
 int n, m;
 int parent[110];
 char courses[110];
 char words[10][110];
 vector<int> childs[110];
 int hits[10];
 
 string random_merge(const string &lhs, const string &rhs) {
   int len = lhs.size() + rhs.size();
   string ret(len, '-');
   int pos = -1;
   REP(i, lhs.size()) {
     int space = len - (pos + 1);
     int rest = lhs.size() - 1 - i;
     mpz_class sum = 0;
     FOREQ(j, rest, space - 1) {
       sum += combi[j][rest];
       // cout << sum << " " << combi[j][rest] << " " << j << " " << rest << endl;
     }
     mpz_class r = rnd.next(sum);
     mpz_class sum2 = 0;
     FOREQ(j, rest, space - 1) {
       sum2 += combi[j][rest];
       if (sum2 > r) {
         pos = len - 1 - j;
         break;
       }
     }
     ret[pos] = lhs[i];
   }
   int index = 0;
   REP(i, len) {
     if (ret[i] == '-') { ret[i] = rhs[index++]; }
   }
   assert(index == (int)rhs.size());
   return ret;
 }
 
 string random_dfs(int from) {
   string ret;
   FORIT(it, childs[from]) {
     string nret = random_dfs(*it);
     ret = random_merge(ret, nret);
   }
   ret = string(1, courses[from]) + ret;
   return ret;
 }
 
 void solve() {
   // random_merge("AB", "C");
   // exit(0);
   REP(i, 110) { childs[i].clear(); }
   MEMSET(hits, 0);
   scanf("%d", &n);
   REP(i, n) {
     scanf("%d", &parent[i]);
     parent[i]--;
     if (parent[i] == -1) { parent[i] = n; }
     childs[parent[i]].push_back(i);
   }
   scanf("%s", courses);
   courses[n] = '-';
   courses[n + 1] = 0;
   scanf("%d", &m);
   REP(i, m) {
     scanf("%s", words[i]);
   }
 
   int cnt = 3000;
   REP(i, cnt) {
     string ans = random_dfs(n);
     // cout << ans << endl;
     REP(i, m) {
       if (strstr(ans.c_str(), words[i]) != NULL) { hits[i]++; }
     }
   }
   REP(i, m) {
     printf(" %.5f", (double)hits[i] / cnt);
   }
   puts("");
 }
