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
 
 vector<int> S;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N, p, q, r, s;
         cin>>N>>p>>q>>r>>s;
         S.resize(N, 0);
         LL sum = 0;
         REP(i, N) {
             S[i] = ((((LL)i * p + q) % r) + s);
             // if (N < 100)
             //     cout<<i<<' '<<S[i]<<endl;
             sum += S[i];
         }
         LL L = 0, R = sum;
         while (R != L + 1) {
             LL m = (L + R) / 2;
             LL tmp = 0, cnt = 0;
             REP(i, N) {
                 if (tmp + S[i] > m) {
                     tmp = 0;
                     cnt++;
                 }
                 tmp += S[i];
                 if (tmp > m) {
                     tmp = 0;
                     cnt += 100;
                 }
             }
             if (tmp) cnt++;
             if (cnt <= 3) {
                 R = m;
             } else {
                 L = m;
             }
             // cout<<L<<' '<<R<<' '<<cnt<<endl;
         }
         if (N == 1) R = sum;
         if (N == 2) R = max(S[0], S[1]);
     	printf("Case #%d: %.10lf\n", caseN + 1, 1 - R * 1.0 / sum);
     }
     return 0;
 }