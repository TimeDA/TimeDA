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
 #include <sstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	map<string, int> m;
     	int N; string s;
     	cin>>N; getline(cin, s);
     	vector<int> sen[32];
     	REP(i, N) {
     		getline(cin, s);
     		istringstream sin(s);
     		string w;
     		while (sin>>w) {
     			if (m.find(w) == m.end()) {
     				int sz = m.size();
     				m[w] = sz;
     			}
     			// cout<<w<<' '<<m[w]<<endl;
     			sen[i].pb(m[w]);
     		}
     	}
     	int best = 50000;
     	REP(i, 1<<(N - 2)) {
     		bool S[2048], S2[2048];
     		memset(S, 0, sizeof S);
     		memset(S2, 0, sizeof S2);
     		REP(j, N) {
     			if (j == 0 || (j >= 2 && ((i & (1<<(j - 2))) != 0))) {
     				REP (k, sen[j].size()) {
     					S[sen[j][k]] = 1;
     				}
     			}
     		}
     		int cnt = 0;
     		REP(j, N) {
     			if (j == 1 || (j >= 2 && ((i & (1<<(j - 2))) == 0))) {
     				REP (k, sen[j].size()) {
     					if (S[sen[j][k]]) {
     						if (S2[sen[j][k]] == 0) {
     							S2[sen[j][k]] = 1;
     							cnt++;
     						}
     					}
     				}
     			}
     		}
     		// cout<<i<<' '<<cnt<<' '<<S.size()<<endl;
     		best = min(best, cnt);
     	}
     	printf("Case #%d: %d\n", caseN + 1, best);
     }
     return 0;
 }