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
 
 const string G = "GABRIEL";
 const string R = "RICHARD";
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   int x, r, c;
   cin >> x >> r >> c;
   if (x == 1) {
     cout << G << endl;
   } else if (x == 2) {
     if ((r * c) % 2 == 0) {
       cout << G << endl;
     } else {
       cout << R << endl;
     }
   } else if (x == 3) {
     if ((r * c) % 3 != 0) {
       cout << R << endl;
       return;
     }
     if (r * c == 3) {
       cout << R << endl;
     } else {
       cout << G << endl;
     }
   } else if (x == 4) {
     if (r * c == 12 || r * c == 16) {
       cout << G << endl;
     } else {
       cout << R << endl;
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
     cerr << i << endl;
   }
 
   return 0;
 }
