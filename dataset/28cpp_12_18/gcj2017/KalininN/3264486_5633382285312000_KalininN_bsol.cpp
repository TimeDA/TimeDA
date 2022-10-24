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
 
 ll n, answer;
 
 void go(int cur, int mind, ll curans)
 {
 //     cout << "go " << cur << ' ' << mind << ' ' << curans << endl;
     if (cur < 0)
     {
         answer = curans;
         return;
     }
     ll st = 1;
     for (int i = 0; i < cur; i++) st *= 10;
     for (int d = 9; d >= mind && answer == -1; d--)
     {
         ll nextans = st * d + curans;
         if (nextans > n) continue;
         go(cur - 1, d, nextans);
     }
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
         scanf("%lld", &n);
         answer = -1;
         go(17, 0, 0);
         printf("%lld\n", answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
