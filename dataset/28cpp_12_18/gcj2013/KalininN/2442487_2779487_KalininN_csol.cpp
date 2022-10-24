#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int maxn = 2006;
 
 bool was[maxn], used[maxn];
 int A[maxn], B[maxn];
 int ans[maxn], last[maxn];
 vector<int> gr[maxn];
 int n;
 
 void go(int cur)
 {
     if (was[cur]) return;
     was[cur] = true;
     for (int i = 0; i < (int)gr[cur].size(); i++) go(gr[cur][i]);
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         scanf("%d", &n);
         for (int i = 0; i < n; i++) scanf("%d", &A[i]);
         for (int i = 0; i < n; i++) scanf("%d", &B[i]);
         for (int i = 0; i < n; i++) gr[i].resize(0);
         for (int i = 0; i <= n; i++) last[i] = -1;
         for (int i = 0; i < n; i++)
         {
 //             cout << i << ' ' << A[i] << endl;
             if (last[A[i]] != -1)
             {
                 gr[last[A[i]]].push_back(i);
 //                 cout << last[A[i]] << "->" << i << endl;
             }
             if (last[A[i] - 1] != -1) gr[i].push_back(last[A[i] - 1]);
             if (last[A[i] + 1] != -1) gr[last[A[i] + 1]].push_back(i);
             last[A[i]] = i;
 //             cout << i << " greater than";
 //             for (int j = 0; j < (int)gr[i].size(); j++) cout << ' ' << j;
 //             cout << endl;
         }
 //         for (int i = 0; i < n; i++)
 //         {
 //             cout << i << " greater than";
 //             for (int j = 0; j < (int)gr[i].size(); j++) cout << ' ' << gr[i][j];
 //             cout << endl;
 //         }
         for (int i = 0; i <= n; i++) last[i] = -1;
         for (int i = n - 1; i >= 0; i--)
         {
             if (last[B[i]] != -1) gr[last[B[i]]].push_back(i);
             if (last[B[i] - 1] != -1) gr[i].push_back(last[B[i] - 1]);
             if (last[B[i] + 1] != -1) gr[last[B[i] + 1]].push_back(i);
             last[B[i]] = i;
         }
 //         for (int i = 0; i < n; i++)
 //         {
 //             cout << i << " greater than";
 //             for (int j = 0; j < (int)gr[i].size(); j++) cout << ' ' << gr[i][j];
 //             cout << endl;
 //         }
         for (int i = 0; i < n; i++) used[i] = false;
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < n; j++) was[j] = false;
             go(i);
             int cnt = 0;
             for (int j = i; j < n; j++) cnt += was[j];
             int cur = 0;
             for (int j = 0; j < n; j++)
             {
                 if (!used[j]) cur++;
                 if (cur == cnt)
                 {
                     ans[i] = j;
                     used[j] = true;
                     break;
                 }
             }
         }
         
         for (int i = 0; i < n; i++) printf(" %d", ans[i] + 1);
         printf("\n");
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
