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
 	freopen("B-small-attempt0.in" , "r" , stdin);
 	freopen("B-small-attempt0.out" , "w" , stdout);
 	//freopen("B-large.in" , "r" , stdin);
 	//freopen("B-large.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         int n , k;
         scanf("%d %d" , &n , &k);
         double a[210];
         for (int i = 0; i < n; i ++)
         {
             scanf("%lf" , &a[i]);
             a[i] = a[i] - 0.5;
         }
         sort(a , a + n);
         int i = 0 , j = n-1;
         vector<double> res;
         for (int t = 0; t < k; t += 2)
         {
             if (a[i] <= 0 && a[j] >= 0)
             {
                 res.push_back(a[i]);
                 res.push_back(a[j]);
                 i ++; j --;
             }
             else if (a[i] < 0 && a[j] < 0)
             {
                 res.push_back(a[j]);
                 res.push_back(a[j-1]);
                 j -= 2;
             }
             else if (a[i] > 0 && a[j] > 0)
             {
                 res.push_back(a[i]);
                 res.push_back(a[i+1]);
                 i += 2;
             }
         }
         double p = 0;
         for (int i = 0; i < (1 << k); i ++)
         {
             int t = i;
             int num = 0;
             while (t) { t = t & (t-1); num ++;}
             if (num == k/2)
             {
                 double q = 1;
                 for (int j = 0; j < k; j ++)
                     if (i & (1 << j)) q *= (0.5 + res[j]);
                     else q *= (0.5 - res[j]);
                 p += q;
             }
         }
         printf("%lf\n" , p);
     }
     return 0;
 }