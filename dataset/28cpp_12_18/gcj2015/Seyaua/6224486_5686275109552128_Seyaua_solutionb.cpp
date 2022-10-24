#include <iostream>
 #include <string>
 #include <cstring>
 #include <cstdio>
 #include <set>
 #include <map>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <bitset>
 #include <cmath>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 map<int, int> mvs;
 
 int get_mvs(int x) {
   if (x <= 0) {
     return 0;
   }
   if (mvs.count(x)) {
     return mvs[x];
   }
   if (x == 1) {
     return 1;
   }
   if (x == 0) {
     return 0;
   }
   int val = get_mvs((x + 1) / 2);
   int rem = x - ((x + 1) / 2);
   rem -= val;
   return mvs[x] = min(x, val + get_mvs(rem) + 1);
 }
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   int d;
   scanf("%d", &d);
   vector <int> vals;
   for (int i = 0; i < d; ++i) {
     int x;
     scanf("%d", &x);
     vals.push_back(x);
   }
   sort(vals.begin(), vals.end());
   reverse(vals.begin(), vals.end());
 
   int res = 0;
   for (int i = 0; i < vals.size(); ++i) {
     int cur = get_mvs(vals[i]);
     res += cur;
     for (int j = i + 1; j < vals.size(); ++j) {
       vals[j] -= cur;
     }
     while (vals.size() > 0 && vals.back() <= 0) {
       vals.pop_back();
     }
   }
   cout << res << endl;
 }
 
 map<vector<int>, int> rs;
 
 int solve_map(vector <int> val) {
   sort(val.begin(), val.end());
   reverse(val.begin(), val.end());
   while (val.size() > 0 && val.back() == 0) {
     val.pop_back();
   }
   if (val.size() == 0) {
     return 0;
   }
   reverse(val.begin(), val.end());
   if (rs.count(val)) {
     return rs[val];
   }
 
   int cres = val.back();
   int mx = val.back();
   if (mx == 1) {
     return 1;
   }
   vector <int> nval = val;
   nval.pop_back();
   nval.push_back(mx / 2);
   nval.push_back((mx + 1) / 2);
   vector <int> nval2 = val;
   for (int i = 0; i < nval2.size(); ++i) {
     --nval2[i];
   }
 
   int nvmx = 1000000;
   for (int i = 1; i < mx; ++i) {
     vector <int> curval = val;
     curval.pop_back();
     curval.push_back(i);
     curval.push_back(mx - i);
     nvmx = min(nvmx, solve_map(curval) + 1);
   }
   return rs[val] = min(min(mx, solve_map(nval2) + 1), nvmx);
 }
 
 void solve2(int tcase) {
   printf("Case #%d: ", tcase);
   int d;
   scanf("%d", &d);
   vector <int> vals;
   for (int i = 0; i < d; ++i) {
     int x;
     scanf("%d", &x);
     vals.push_back(x);
   }
   sort(vals.begin(), vals.end());
   printf("%d\n", solve_map(vals));
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve2(i + 1);
     cerr << i << endl;
   }
 
   return 0;
 }
