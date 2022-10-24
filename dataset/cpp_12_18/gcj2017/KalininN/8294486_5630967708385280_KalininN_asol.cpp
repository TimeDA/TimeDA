#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 template<typename T>
 using pair2 = pair<T, T>;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
         int D, n;
         scanf("%d%d", &D, &n);
         ld answer = 0;
         for (int i = 0; i < n; i++)
         {
             int d, s;
             scanf("%d%d", &d, &s);
             answer = max(answer, (ld)(D - d) / s);
         }
         printf("%.20f\n", (double)(D / answer));
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
