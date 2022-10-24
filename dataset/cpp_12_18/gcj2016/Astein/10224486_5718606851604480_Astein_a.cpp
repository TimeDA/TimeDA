#include <cstdio>
 #include <string>
 
 using namespace std;
 
 string str[13][3]; // 'P' 'R' 'S'
 
 string precalc(int depth, int winner)
 {
   if (depth == 0)
   {
     if (winner == 0) return "P";
     if (winner == 1) return "R";
     if (winner == 2) return "S";
   }
 
   if (str[depth][winner].size() > 0)
     return str[depth][winner];
 
   string left, right;
   if (winner == 0) // P
   {
     left = precalc(depth - 1, 0); // P
     right = precalc(depth - 1, 1); // R
   }
   if (winner == 1) // R
   {
     left = precalc(depth - 1, 1); // R
     right = precalc(depth - 1, 2); // S
   }
   if (winner == 2) // S
   {
     left = precalc(depth - 1, 2); // S
     right = precalc(depth - 1, 0); // P
   }
   if (left > right) swap(left, right);
   str[depth][winner] = left + right;
   return str[depth][winner];
 }
 
 int main()
 {
   for (int i = 0; i < 3; ++i)
 		str[12][i] = precalc(12, i);
 
   int T;
   scanf("%d", &T);
   
   for (int cn = 1; cn <= T; ++cn)
   {
     int N, P, R, S;
     scanf("%d%d%d%d", &N, &R, &P, &S);
     
     string ret = "IMPOSSIBLE";
     for (int i = 0; i < 3; ++i)
     {
       int np = 0, nr = 0, ns = 0;
       for (int j = 0; j < str[N][i].size(); ++j)
       {
         if (str[N][i][j] == 'P') np++;
         if (str[N][i][j] == 'R') nr++;
         if (str[N][i][j] == 'S') ns++;
       }
       if (np == P && ns == S && nr == R)
         ret = str[N][i];
     }
     printf("Case #%d: %s\n", cn, ret.c_str());
   }
 }
 
