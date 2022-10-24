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
 
 int N;
 vector<int> R;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>N; 
     	// int l = -1, pos = -1;
     	R.clear();
     	// vector<pii> O;
     	REP(i, N) {
     		int x; cin>>x;R.pb(x);
     		// O.pb(make_pair(-x, i));
     		// if (x > l) {
     		// 	l = x;
     		// 	pos = i;
     		// }
     	}
     	// sort(O.begin(), O.end());
     	int small = 10000000;
     	REP(F, N) {
     		int res = 0;
     		vector<int> X = R;
     		vector<int> G(N, false);
     		REP(i, N) {
     			int big = -1, pos = -1;
     			REP(j, N) {
     				if (!G[j] && X[j] > big) {
     					big = X[j]; pos = j;
     				}
     			}
     			// cout<<"big"<<big<<' '<<pos<<' '<<F<<endl;
     			if (pos > F) {
     				while (pos != F) {
     					if (G[pos - 1]) {
     						break;
     					}
     					swap(X[pos], X[pos - 1]);
     					pos--;res++;
     				}
     			} else if (pos < F) {
     				while (pos != F) {
     					if (G[pos + 1]) {
     						break;
     					}
     					swap(X[pos], X[pos + 1]);
     					pos++;res++;
     				}
     			}
     			G[pos] = true;
     		}
     		small = min(small, res);
     		cout<<res<<' '<<F<<endl;
     	}
     	printf("Case #%d: %d\n", caseN + 1, small);
     }
     return 0;
 }