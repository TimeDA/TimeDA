#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 int main()
 {
 	freopen("A-small-attempt2.in" , "r" , stdin);
 	freopen("A-small-attempt2.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         int n , x , k;
         int a[701] = {0};
         scanf("%d %d" , &n , &x);
         for (int i = 0; i < n; i ++)
         {
             scanf("%d" , &k);
             a[k] ++;
         }
         int res = 0;
         for (int i = 0; i <= x/2; i ++)
         {
             if (a[i] > 0)
             {
                 int b = x-i;
                 int num = a[i];
                 for (int j = b; j > i; j --)
                     if (a[j] > 0)
                     {
                         if (a[j] >= num)
                         {
                             res += num;
                             a[j] -= num;
                             num = 0;
                             break;
                         }
                         else
                         {
                             res += a[j];
                             num -= a[j];
                             a[j] = 0;
                         }
                     }
                 if (num > 0)
                 {
                     res += num / 2 + (num & 1);
                     num = 0;
                 }
                 a[i] = 0;
             }
         }
         for (int i = 0; i <= x; i ++) res += a[i];
         printf("%d\n" , res);
     }
     return 0;
 }