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
 
 int B[20000], D[20000], L[20000];
 
 int main(){
     int caseNumber;
     scanf("%d", &caseNumber);
     //cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N;
         scanf("%d", &N);
         REP(i, N) {
             scanf("%d%d", D + i, L + i);
         }
         int DD;
         scanf("%d", &DD);
         int yes = 0;
         memset(B, 0, sizeof B);
         B[0] = D[0];
         for (int i = 0; i < N; i++)  {
             for (int j = i + 1; j < N; j++) {
                 if (B[i] >= D[j] - D[i]) {
                     B[j] = min(L[j], max(B[j], D[j] - D[i]));
                 }
             }
             yes |= B[i] + D[i] >= DD;
         }
         printf("Case #%d: ", caseN + 1);
         if (yes) {
             puts("YES");
         } else puts("NO");
     }
     return 0;
 }
