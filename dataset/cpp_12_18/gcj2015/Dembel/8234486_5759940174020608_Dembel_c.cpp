#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 char s[10000];
 vector < vector <int> > cnt;
 map <string, int> dict;
 
 int getWordInt(char * s) {
   string word(s);
   dbg("%s\n", word.c_str());
   if (dict.count(word)) {
     return dict[word];
   }
   dict[word] = cnt.size();
   cnt.push_back(vector <int>(2, 0));
   return int(cnt.size()) - 1;
 }
 
 vector <int> parseLine() {
   vector <int> v;
   gets(s);
   for (int i = 0; ;) {
     int j = i;
     while (s[j] && s[j] != ' ') {
       ++j;
     }
     bool isEnd = (s[j] == 0);
     s[j] = 0;
     v.push_back(getWordInt(s + i));
     if (isEnd) {
       break;
     }
     i = j + 1;
   }
   for (int i = 0; i < int(v.size()); ++i) {
     dbg("%d ", v[i]);
   }
   dbg("\n");
   return v;
 }
 
 int brute (int k, const vector < vector <int> > & v) {
   if (k == int(v.size())) {
     int ans = 0;
     for (int i = 0; i < int(cnt.size()); ++i) {
       if (cnt[i][0] && cnt[i][1]) {
         ans += 1;
       }
     }
     return ans;
   }
   int ans = 1 << 28;
   for (int i = 0; i < 2; ++i) {
     for (int j = 0; j < int(v[k].size()); ++j) {
       cnt[v[k][j]][i] += 1;
     }
     ans = min(ans, brute(k + 1, v));
     for (int j = 0; j < int(v[k].size()); ++j) {
       cnt[v[k][j]][i] -= 1;
     }
   }
   return ans;
 }
 
 void solve() {
   cnt.clear();
   dict.clear();
 
   int n;
   scanf("%d\n", &n);
   for (int i = 0; i < 2; ++i) {
     vector <int> v = parseLine();
     for (int j = 0; j < (int)v.size(); ++j) {
       cnt[v[j]][i] += 1;
     }
   }
   vector < vector <int> > v(n - 2);
   for (int i = 2; i < n; ++i) {
     v[i - 2] = parseLine();
   }
 
   printf("%d\n", brute(0, v));
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     solve();
   }
 
   return 0;
 }
 
