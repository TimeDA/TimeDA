#include<cstdio>
 #include<cstdlib>
 #include<vector>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 int n;
 int k;
 int sums[1100];
 int diff[1100];
 int gmax[1100];
 int gmin[1100];
 
 int main()
 {
     int t, test;
     scanf("%d", &test);
     for (t = 0; t < test; t++)
     {
         scanf("%d %d", &n, &k);
         for (int i = 0; i < n - k + 1; i++)
         {
             scanf("%d", &sums[i]);
         }
         for (int i = 0; i < n - k; i++)
         {
             diff[i] = sums[i + 1] - sums[i];
         }
         for (int i = 0; i < k; i++)
         {
             gmax[i] = 0;
             gmin[i] = 0;
             int temp = 0;
             for (int j = i; j < n - k; j += k)
             {
                 temp += diff[j];
                 gmax[i] = max(gmax[i], temp);
                 gmin[i] = min(gmin[i], temp);
             }
         }
 
         int fsum = sums[0];
         for (int i = 0; i < k; i++)
         {
             fsum += gmin[i];
             gmax[i] -= gmin[i];
             gmin[i] = 0;
         }
         fsum = ((fsum % k) + k) % k;
         int mingmax = -1;
         for (int i = 0; i < k; i++)
         {
             mingmax = max(mingmax, gmax[i]);
         }
         int extra = 0;
         for (int i = 0; i < k; i++)
         {
             extra += mingmax - gmax[i];
         }
         if (fsum > extra)
         {
             mingmax++;
         }
 
         printf("Case #%d: %d\n", t+1, mingmax);
     }
     return 0;
 }
