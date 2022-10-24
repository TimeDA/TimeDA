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
 
 int N, X;
 vector<int> R;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         cin>>N>>X;
         R.clear();
         REP(i, N) {
             int x; cin>>x;
             R.pb(x);
         }
         sort(R.begin(), R.end(), greater<int>());
         int res = 0;
         REP(i, N) {
             if (R[i] == -1) continue;
             for (int j = i + 1; j < N; j++) {
                 if (R[j] != -1 && R[i] + R[j] <= X) {
                     R[j] = -1;
                     break;
                 }
             }
             R[i] = -1;
             res++;
         }
     	printf("Case #%d: %d\n", caseN + 1, res);
     }
     return 0;
 }