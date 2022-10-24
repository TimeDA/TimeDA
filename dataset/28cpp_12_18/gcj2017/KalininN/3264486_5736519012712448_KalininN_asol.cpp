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
 
 const int maxn = 1005;
 
 char s[maxn];
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         int k;
         scanf("%s%d", s, &k);
         int n = strlen(s);
         int answer = 0;
         for (int i = 0; i < n - k + 1; i++)
         {
             if (s[i] == '-')
             {
                 for (int j = 0; j < k; j++) s[i + j] = '-' + '+' - s[i + j];
                 answer++;
             }
         }
         for (int i = n - k + 1; i < n; i++) if (s[i] != '+') answer = -1;
         if (answer == -1) printf(" IMPOSSIBLE\n");
         else printf(" %d\n", answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
