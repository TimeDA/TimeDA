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
 
 bool check(int cnt, const string& s) {
   int curhave = cnt;
   for (int i = 0; i < s.length(); ++i) {
     int x = s[i] - '0';
     if (curhave >= i) {
       curhave += x;
     } else {
       return false;
     }
   }
   return true;
 }
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   int len;
   scanf("%d", &len);
   string s;
   cin >> s;
 
   for (int i = 0; ; ++i) {
     if (check(i, s)) {
       printf("%d\n", i);
       break;
     }
   }
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve(i + 1);
   }
 
   return 0;
 }
