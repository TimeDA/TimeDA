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
 	freopen("B-small-attempt4.in" , "r" , stdin);
 	freopen("B-small-attempt4.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         int n , a[1005];
         scanf("%d" , &n);
         for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
         int res = 0;
         int minres = 1 << 30;
         for (int k = 0; k <= n; k ++)
         {
             res = 0;
             for (int i = 0; i < k; i ++)
             {
                 for (int j = i+1; j < k; j ++) if (a[i] > a[j]) res ++;
             }
             for (int i = k; i < n; i ++)
             {
                 for (int j = i+1; j < n; j ++) if (a[i] < a[j]) res ++;
             }
             if (res < minres) minres = res;
         }
         res = minres;
         printf("%d\n" , res);
 
     }
     return 0;
 }