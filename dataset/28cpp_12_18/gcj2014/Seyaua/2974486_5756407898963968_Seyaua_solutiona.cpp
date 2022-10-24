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
 
 int a[5][5], b[5][5];
 int used[20];
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   int x, y;
   scanf("%d", &x);
   --x;
   for (int i = 0; i < 4; ++i) {
     for (int j = 0; j < 4; ++j) {
       scanf("%d", &a[i][j]);
     }
   }
 
   scanf("%d", &y);
   --y;
   for (int i = 0; i < 4; ++i) {
     for (int j = 0; j < 4; ++j) {
       scanf("%d", &b[i][j]);
     }
   }
 
   memset(used, 0, sizeof(used));
   for (int i = 0; i < 4; ++i) {
     ++used[a[x][i]];
     ++used[b[y][i]];
   }
 
   int cnt = 0;
   int num = -1;
   for (int i = 0; i < 20; ++i) {
     if (used[i] > 1) {
       ++cnt;
       num = i;
     }
   }
   if (cnt == 1) {
     printf("%d\n", num);
   } else if (cnt > 1) {
     printf("Bad magician!\n");
   } else {
     printf("Volunteer cheated!\n");
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
