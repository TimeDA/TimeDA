#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <unordered_map>
 #include <unordered_set>
 #include <sstream>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define sqr(x) (x) * (x)
 template <class T> ostream& operator<<(ostream& out, const vector<T>& v) { forn(i, v.size()) { if (i) out << " "; out << v[i]; } return out; }
 template <class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) { out << "{" << p.first << ", " << p.second << "}"; return out; }
 
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 unordered_set<string> was;
 int fact[15];
 
 int get(const string& s) {
     if (was.find(s) != was.end()) return 0;
     was.insert(s);
     int res = 1;
 
     size_t cd = 0;
     for (size_t i = 1; i <= s.size(); i++)
         cd += (s[i - 1] - '0') * i;
 
     size_t nd = 0;
     for (size_t i = 1; i <= s.size(); i++)
         nd += (s[i - 1] - '0');
 
     if (nd > s.size()) return 1;
 
     if (cd <= s.size()) {
         string ns = "";
         forn(q, s.size() - nd) ns += '0';
         for (size_t i = 1; i <= s.size(); i++)
             forn(q, s[i - 1] - '0') ns += ('0' + i);
 
         if (ns.size() != s.size()) {
             cerr << "> " << s << " .. " << ns << endl;
             assert(false);
         }
         do {
             res += get(ns);
         } while (next_permutation(ns.begin(), ns.end()));
     } else {
         int f = fact[s.size()];
         int qs = 0;
         for (size_t i = 1; i <= s.size(); i++) {
             f /= fact[s[i - 1] - '0'];
             qs += s[i - 1] - '0';
         }
         f /= fact[s.size() - qs];
         res += f;
     }
 
     return res;
 }
 
 void solve() {
     char s[100];
     scanf("%s", s);
     was.clear();
     printf("%d\n", get(string(s)));
 }
 
 int main() {
     fact[0] = 1;
     for (int i = 1; i <= 12; i++) fact[i] = fact[i-1] * i;
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
     return 0;
 }
