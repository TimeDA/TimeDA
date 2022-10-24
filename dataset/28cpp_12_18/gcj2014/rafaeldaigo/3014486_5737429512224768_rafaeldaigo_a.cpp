#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 int main()
 {
     int t, teste;
     int n, x;
     int i, j;
     int sizes[1100];
     bool stored[1100];
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d %d\n", &n, &x);
         for (i = 0; i < n; i++)
         {
             scanf("%d", &sizes[i]);
             stored[i] = false;
         }
         sort(&sizes[0], &sizes[n]);
 
         int ans = 0;
         j = n - 1;
         for (i = 0; i < n; i++)
         {
             if (stored[i]) continue;
             ans++;
             for (;j >= 0; j--)
             {
                 if (stored[j]) continue;
                 if (sizes[j] + sizes[i] <= x)
                 {
                     stored[j] = true;
                     break;
                 }
             }
         }
 
         printf("Case #%d: %d\n", t + 1, ans);
     }
     return 0;
 }
