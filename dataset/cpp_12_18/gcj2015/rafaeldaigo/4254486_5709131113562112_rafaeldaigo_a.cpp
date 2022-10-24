#include<cstdio>
 #include<cstdlib>
 #include<vector>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 int s[1100000];
 int m[1100000];
 int n;
 int d;
 int safemin[1100000];
 int safemax[1100000];
 
 int main()
 {
     int t, test;
     scanf("%d", &test);
     for (t = 0; t < test; t++)
     {
         scanf("%d %d", &n, &d);
         long long ini, mul, add, modu;
         scanf("%lld %lld %lld %lld", &ini, &mul, &add, &modu);
         long long temp = ini;
         s[0] = ini;
         for (int i = 1; i < n; i++)
         {
             temp = (temp * mul + add) % modu;
             s[i] = temp;
         }
         scanf("%lld %lld %lld %lld", &ini, &mul, &add, &modu);
         temp = ini;
         m[0] = 0;
         for (int i = 1; i < n; i++)
         {
             temp = ((temp * mul) + add) % modu;
             m[i] = temp % i;
         }
 
         safemin[0] = s[0] - d;
         safemax[0] = s[0];
         for (int i = 1; i < n; i++)
         {
             safemin[i] = max(safemin[m[i]], s[i] - d);
             safemax[i] = min(safemax[m[i]], s[i]);
         }
 
         vector<pair<int, int> > events;
         for (int i = 1; i < n; i++)
         {
             if (safemax[i] >= safemin[i])
             {
                 events.push_back(make_pair(safemin[i], i));
                 events.push_back(make_pair(safemax[i] + 1, -i));
             }
         }
         sort(events.begin(), events.end());
 
         int current = 1;
         int resp = 1;
         bool impossible = false;
         for (int i = 0; i < events.size(); i++)
         {
             if (events[i].second > 0)
                 current++;
             else
                 current--;
             resp = max(resp, current);
         }
 
         printf("Case #%d: %d\n", t+1, resp);
     }
     return 0;
 }
