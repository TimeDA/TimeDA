#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 int H[2014], D[2014], F[2014];
 vector<int> R[2014];
 
 int main(){
     int caseNumber;
     scanf("%d", &caseNumber);
     //cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N;
         scanf("%d", &N);
         memset(H, 0, sizeof H);
         memset(D, 0, sizeof D);
         REP(i, N) {
             R[i].clear();
         }
         int ft = 1024101;
         int bad = 0;
         REP(i, N - 1) {
             scanf("%d", F + i);
             F[i]--;
             R[F[i]].pb(i);
             if (i) {
                 //~ printf("%d %d %d\n", i, ft, F[i]);
                 REP(j, i) {
                     if (F[j] < F[i] && F[j] > i) {
                         bad = 1;
                         //~ goto bb;
                     }
                 }
             }
             ft = min(ft, F[i]);
         }
         bb:;
         if (!bad) {
             for (int i = N - 1; i >= 0; i--) {
                  {
                     if (D[i] == 0) {
                         H[i] = 1000000000;
                         if (R[i].size() == 0) H[i]  =0;
                         D[i] = 1;
                     }
                     REP(k, R[i].size()) {
                         int& p = R[i][k];
                         D[p] = D[i] + k;
                         H[p] = H[i] - D[p] * (i - p);
                     }
                 }
             }
         }
         if (0) {
             
             if (bad) {
                 puts("-1");
             } else {
                 printf("%d\n", N);
                 REP(i, N) {
                     printf("%d ", H[i]);
                 }
                 puts("");
             }
             
         } else {
             printf("Case #%d: ", caseN + 1);
             if (bad) {
                 puts("Impossible");
             } else {
                 REP(i, N) {
                     printf("%d ", H[i]);
                 }
                 puts("");
             }
         }
     }
     return 0;
 }
