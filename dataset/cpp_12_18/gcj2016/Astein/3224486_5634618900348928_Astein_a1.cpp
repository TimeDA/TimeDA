#include <cstdio>
 #include <string>
 
 using namespace std;
 
 char s[20005];
 int a[55][55];
 
 int solve(string s)
 {
   int ret = 0;
   for (int i = 2; i <= s.size(); i += 2)
   {
     for (int j = 0; j <= s.size() - i; ++j)
     {
       int x = j, y = j + i - 1;
       int def = (s[x] == s[y]) ? 10 : 5;
       a[x][y] = def + a[x + 1][y - 1];
 
       for (int k = x + 1; k < y - 1; ++k)
       {
         if (a[x][y] < a[x][k] + a[k + 1][y])
         {
           a[x][y] = a[x][k] + a[k + 1][y];
         }
       }
     }
   }
   return a[0][s.size() - 1];
 }
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     scanf("%s", s);
     printf("Case #%d: %d\n", cn, solve(s));
   }
 }
