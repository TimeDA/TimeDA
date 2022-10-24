#pragma comment(linker, "/STACK:100000000")
 #include <cmath>
 #include <cstdio>
 #include <vector>
 #include <iostream>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <ctime>
 using namespace std;
 const int N=1100;
 char s[N], f[N];
 int main()
 {
     int ts;
     scanf("%d", &ts);
     for(int t=1; t<=ts; t++)
     {
         printf("Case #%d: ", t);
         int n, k, i;
         scanf("%s%d", s, &k);
         n=strlen(s);
         for(i=0; i<=n; f[i]=0, i++);
         int r, x;
         x=0;
         r=0;
         for(i=0; i+k<=n; i++)
         {
             x^=f[i];
             int y=s[i]=='-';
             if(y^x)
             {
                 r++;
                 x^=1;
                 f[i+k]^=1;
             }
         }
         for(; i<n; i++)
         {
             x^=f[i];
             int y=s[i]=='-';
             if(y^x) r=-1;
         }
         if(r==-1) printf("IMPOSSIBLE\n");
         else printf("%d\n", r);
     }
 	return 0;
 }