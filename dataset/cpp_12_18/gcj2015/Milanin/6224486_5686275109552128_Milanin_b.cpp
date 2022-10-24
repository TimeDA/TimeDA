#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 using namespace std;
 #define N 1010
 int m[N];
 int main()
 {
     int ts, tst;
     scanf("%d", &tst);
     for (ts = 1; ts <= tst; ts++)
     {
         int i, j, r, k, n;
         scanf("%d", &n);
         for (i = 0; i < n; scanf("%d", &m[i]), i++);
         r = N;
         for (j = 1; j <= N; j++)
         {
             k = j;
             for (i = 0; i < n; k+=(m[i]-1)/j, i++);
             r = min(r, k);
         }
         printf("Case #%d: %d\n", ts, r);
     }
     return 0;
 }