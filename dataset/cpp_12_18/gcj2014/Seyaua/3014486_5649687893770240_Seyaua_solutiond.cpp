#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 50;
 
 struct node {
   node* a[26];
   node() {
     for (int i = 0; i < 26; ++i) {
       a[i] = NULL;
     }
   }
 };
 
 int res;
 node* cur;
 
 void add(node* cur, const string& s) {
   for (int i = 0; i < s.length(); ++i) {
     if (cur->a[s[i] - 'A'] != NULL) {
       cur = cur->a[s[i] - 'A'];
     } else {
       node* buf = new node();
       ++res;
       cur->a[s[i] - 'A'] = buf;
       cur = buf;
     }
   }
 }
 
 void mclear(node* cur) {
   for (int i = 0; i < 26; ++i) {
     if (cur->a[i] != NULL) {
       mclear(cur->a[i]);
     }
   }
   delete cur;
 }
 
 int get_cnt(const vector <string>& vals) {
   res = 1;
   cur = new node();
   for (int i = 0; i < vals.size(); ++i) {
     add(cur, vals[i]);
   }
 
   mclear(cur);
   return res;
 }
 
 int m, n;
 string s[maxN];
 int a[maxN];
 int mx;
 int cntmx;
 
 vector <string> curs[maxN];
 
 void rec(int x) {
   if (x == m) {
     for (int i = 0; i < n; ++i) curs[i].clear();
     for (int i = 0; i < m; ++i) curs[a[i]].push_back(s[i]);
 
     int tres = 0;
     for (int i = 0; i < n; ++i) {
       if (curs[i].size() == 0) {
         tres = -1;
         break;
       }
       tres += get_cnt(curs[i]);
     }
 
     if (tres > mx) {
       mx = tres;
       cntmx = 1;
     } else if (tres == mx) {
       ++cntmx;
     }
     return;
   }
   for (int i = 0; i < n; ++i) {
     a[x] = i;
     rec(x + 1);
   }
 }
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
 
   scanf("%d%d", &m, &n);
 
   for (int i = 0; i < m; ++i) {
     cin >> s[i];
   }
 
   mx = -1;
   cntmx = 0;
   rec(0);
   cout << mx << " " << cntmx << endl;
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve(i + 1);
     cerr << i << endl;
   }
 
   return 0;
 }
