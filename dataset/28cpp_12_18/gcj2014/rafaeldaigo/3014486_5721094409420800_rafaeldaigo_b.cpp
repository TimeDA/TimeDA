#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 int main()
 {
     int t, teste;
     int n;
     int i;
     int j;
     int count;
     int values[1100];
     int sorted[1100];
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d\n", &n);
         for (i = 0; i < n; i++)
         {
             scanf("%d", &values[i]);
             sorted[i] = values[i];
         }
         sort(&sorted[0], &sorted[n]);
 
         int ans = 0;
         for (i = 0; i < n; i++)
         {
             int a = sorted[i];
             count = 0;
             for (j = 0 ;j < n; j++)
             {
                 if (values[j] > a)
                 {
                     count++;
                 }
                 else if (values[j] == a)
                 {
                     int best = count;
                     if (best > n - i - 1 - count)
                         best = n - i - 1 - count;
                     ans += best;
                     break;
                 }
             }
         }
 
         printf("Case #%d: %d\n", t + 1, ans);
     }
     return 0;
 }
