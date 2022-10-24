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
 typedef pair<double, double> pdd;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	int N; double V, X;
     	cin>>N>>V>>X;
     	vector<pdd> W;
     	int x1 = 0, x2 = 0;
     	REP(i, N) {
     		double R, D; cin>>R>>D;
     		W.pb({D, R});
     		if (D >= X) x1 = 1;
     		if (D <= X) x2 = 1;
     	}
     	sort(W.begin(), W.end());
         if (x1 & x2) {
             double R0 = W[0].second, R1 = W[1].second;
             double D0 = W[0].first, D1 = W[1].first;
             if (N == 1) 
         	    printf("Case #%d: %.15lf\n", caseN + 1, V / R0);
             else {
                 double t = X * V - D1 * V;
                 double t2 = (R0 * D0 - R0 * D1);
                 if (t2 == 0)
                     printf("Case #%d: %.15lf\n", caseN + 1, V / (R0 + R1));
                 else {
                     t /= t2;
                     printf("Case #%d: %.15lf\n", caseN + 1, max(t, V / R1 - t * R0 / R1));
                 }
 
             }
         }
         else
             printf("Case #%d: IMPOSSIBLE\n", caseN + 1);
     }
     return 0;
 }