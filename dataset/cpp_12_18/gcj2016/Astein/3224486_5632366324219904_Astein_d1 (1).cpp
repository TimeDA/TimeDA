#include <string>
 #include <cstdio>
 
 using namespace std;
 
 char s[55];
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     int N, L;
     scanf("%d%d", &N, &L);
     bool ispos = true;
     for (int i = 0; i < N; ++i)
     {
       scanf("%s", s);
       string S = s;
       if (S == string(L, '1'))
         ispos = false;
     }
     scanf("%s", s);
     
     string s1, s2;
 
 		if (!ispos)
 		{
 		  printf("Case #%d: IMPOSSIBLE\n", cn);
 		  continue;
 		}
     if (L == 1)
     {
       printf("Case #%d: 0 0?\n", cn);
     }
     else
     {
       for (int i = 0; i < L - 1; ++i)
         s1 += "?";
 
       s2 = "10?1";
       for (int i = 2; i < L; ++i)
       {
         if (s2[0] == '1')
         {
           s2 = "0" + s2;
         }
         else
         {
           s2 = "1" + s2;
         }
       }
       printf("Case #%d: %s %s\n", cn, s1.c_str(), s2.c_str());
     }
   }
 }
