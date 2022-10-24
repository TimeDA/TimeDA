#include <cstdio>
 #include <string>
 
 using namespace std;
 
 int ret;
 int N;
 string a[30];
 char s[30];
 
 void backtr(int x, int y, int ch)
 {
   if (x == N)
   {
     for (int i = 0; i < N; ++i)
     {
       int cnt1 = 0, cnt2 = 0;
       for (int j = 0; j < N; ++j)
       {
         if (a[i][j] == '1') cnt1++;
         if (a[j][i] == '1') cnt2++;
       }
       if (cnt1 == 0 || cnt2 == 0) return;
     }
   
     for (int i = 0; i < N; ++i)
     {
       int mine = 0;
       for (int j = 0; j < N; ++j)
       {
         if (a[i][j] == '1')
         {
           mine++;
         }
       }
       int same = 0;
       for (int j = 0; j < N; ++j)
       {
         if (a[i] == a[j]) same++;
       }
       if (mine != same) return;
     }
     if (ret > ch)
       ret = ch;
     return;
   }
   if (a[x][y] == '1')
   {
     if (y != N - 1) backtr(x, y + 1, ch); else backtr(x + 1, 0, ch);
   }
   else
   {
     a[x][y] = '0';
     if (y != N - 1) backtr(x, y + 1, ch); else backtr(x + 1, 0, ch);
     a[x][y] = '1';
     if (y != N - 1) backtr(x, y + 1, ch + 1); else backtr(x + 1, 0, ch + 1);
     a[x][y] = '0';
   }
 }
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     scanf("%d", &N);
     for (int i = 0; i < N; ++i)
     {
       scanf("%s", s);
       a[i] = s;
     }
     ret = N * N + 1;
     backtr(0, 0, 0);
     printf("Case #%d: %d\n", cn, ret);
   }
 }
