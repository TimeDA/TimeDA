
 
 
 /*
     Prob:   Google Code Jam 2012 Qualification_Round A
     Author: peanutyk
     Time:   14/04/12 23:32
     Description: Unknown
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 300;
 int n;
 char ptr[MaxN], tmp[MaxN];
 
 int main() {
     ptr['a'] = 'y'; ptr['b'] = 'h';
     ptr['c'] = 'e'; ptr['d'] = 's';
     ptr['e'] = 'o'; ptr['f'] = 'c';
     ptr['g'] = 'v'; ptr['h'] = 'x';
     ptr['i'] = 'd'; ptr['j'] = 'u';
     ptr['k'] = 'i'; ptr['l'] = 'g';
     ptr['m'] = 'l'; ptr['n'] = 'b';
     ptr['o'] = 'k'; ptr['p'] = 'r';
     ptr['q'] = 'z'; ptr['r'] = 't';
     ptr['s'] = 'n'; ptr['t'] = 'w';
     ptr['u'] = 'j'; ptr['v'] = 'p';
     ptr['w'] = 'f'; ptr['x'] = 'm';
     ptr['y'] = 'a'; ptr['z'] = 'q';
     
     scanf("%d", &n);
     gets(tmp);
     for (int k = 1; k <= n; ++ k) {
         printf("Case #%d: ", k);
         gets(tmp);
         for (int r = 0; r < strlen(tmp); ++ r) {
             if (islower(tmp[r]))
                 printf("%c", ptr[tmp[r]]);
             else
                 printf("%c", tmp[r]);
         }
         puts("");
     }
     
     return 0;
 }
