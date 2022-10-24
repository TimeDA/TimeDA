#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cassert>
 #include <map>
 #include <iostream>
 using namespace std;
 
 const int N = 37;
 
 typedef long long llong;
 
 const int EPS = 100;
 
 void solve(int tc)
 {
     llong B;
     int n;
     scanf("%lld %d", &B, &n);
     vector<llong> H(37, 0);
     for (int i = 0; i < n; i++)
         scanf("%lld", &H[i]);
     sort(H.begin(), H.end());
     vector<llong> T;
     vector<llong> S;
 
     for (int i = 0; i < N; i++)
         T.push_back(H[i] - 1), T.push_back(H[i]), T.push_back(H[i] + 1);
     llong s = 0;
     for (int i = 0; i < N; i++)
     {
         s += H[i];
         T.push_back((B - s) / (i + 1));
     }
 
     for (int i = 0; i < T.size(); i++)
         for (int x = -100; x <= 100; x++)
             S.push_back(max(0LL, T[i] + x));
     sort(S.begin(), S.end());
     S.resize(unique(S.begin(), S.end()) - S.begin());
 
     double ans = 0;
 
     for (int i = 0; i < S.size(); i++)
     {
         llong h = S[i];
         for (int p = 1; p <= 37; p++)
         {
             llong bf = 0;
             llong pf = 0;
             if (H[p - 1] > h)
                 break;
             for (int j = 0; j < p; j++)
             {
                 assert(H[j] <= h);
                 bf += h - H[j];
                 pf += h - H[j];
             }
             for (int j = p; j < 37; j++)
             {
                 bf += h + 1 - min(h + 1, H[j]);
             }
             if (bf <= B)
                 ans = max(ans, -bf + pf * 36.0 / p);
         }
     }
     printf("Case #%d: %.12lf\n", tc, ans);
 }
 
 int main()
 {
     int t;
     scanf("%d", &t);
     for (int i = 0; i < t; i++)
     {
         solve(i + 1);
     }
 }
