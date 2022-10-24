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
 #define N 10010
 char s[N], p[N];
 char mul(char x, char y)
 {
     int z, r;
     r = '1';
     z = 1;
     if (x == '1' + 3 || x == 'i' + 3 || x == 'j' + 3 || x == 'k' + 3)
     {
         x -= 3;
         z = -z;
     }
     if (y == '1' + 3 || y == 'i' + 3 || y == 'j' + 3 || y == 'k' + 3)
     {
         y -= 3;
         z = -z;
     }
     if (x == '1') r = y;
     else if (y == '1') r = x;
     else if (x == y) { r = '1'; z = -z; }
     else if (x == 'i' && y == 'j') r = 'k';
     else if (x == 'i' && y == 'k') { r = 'j'; z = -z; }
     else if (x == 'j' && y == 'k') r = 'i';
     else if (x == 'j' && y == 'i') { r = 'k'; z = -z; }
     else if (x == 'k' && y == 'i') r = 'j';
     else if (x == 'k' && y == 'j') { r = 'i'; z = -z; }
     if (z == -1) r += 3;
     return r;
 }
 int main()
 {
     int tst, ts;
     scanf("%d", &tst);
     for (ts = 1; ts <= tst; ts++)
     {
         int i, j, l, k, f;
         char a, b;
         scanf("%d%d%s", &l, &k, s);
         for (i = 1; i < k; i++)
             for (j = 0; j < l; s[i*l + j] = s[j], j++);
         l *= k;
         p[l] = '1';
         for (i = l - 1; i >= 0; p[i]=mul(s[i], p[i+1]), i--);
         f = 0;
         a = '1';
         for (i = 0; i < l; i++)
         {
             b = '1';
             for (j = 0; i + j < l; j++)
             {
                 if (i>0 && j > 0 && a == 'i' && b == 'j' && p[i + j] == 'k') f = 1;
                 b = mul(b, s[i + j]);
             }
             a = mul(a, s[i]);
         }
         if (f) printf("Case #%d: YES\n", ts);
         else printf("Case #%d: NO\n", ts);
     }
     return 0;
 }