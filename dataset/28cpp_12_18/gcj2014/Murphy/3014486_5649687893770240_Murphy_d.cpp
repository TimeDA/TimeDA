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
 
 int N, M;
 string s[10];
 int c[1024];
 
 int worst, counts;
 
 void gao(int cur, int mask, int sum) {
 	if (cur == M && mask == ((1 << N) - 1) ) {
 		if (sum > worst) {
 			worst = sum; counts =0;
 		}
 		if (sum == worst) counts++;
 		return;
 	}
 	REP(i, 1 << N)
 		if (i)
 			if (!(mask & i)) {
 				gao(cur + 1, mask | i, sum + c[i]);
 			}
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>N>>M;
     	REP(i, N) {
     		cin>>s[i];
     	}
     	sort(s, s + N);
     	REP(i, 1<<N) {
     		if (!i) continue;
     		string pre = "";
     		int r = 0;
     		REP(j, N) {
     			if ((1<<j) & i) {
     				string k = s[j]; r += k.size();
     				REP(p, k.size()) {
     					if (pre.size() > p && k[p] == pre[p]) {
     						r--;
     					} else break;
     				}
     				pre = k;
     			}
     		}
     		r++;
     		// cout<<i<<' '<<r<<endl;
     		c[i] = r;
     	}
     	worst = counts = 0;
     	gao(0, 0, 0);
     	printf("Case #%d: %d %d\n", caseN + 1, worst, counts);
     	// cerr<<"case"<<caseN + 1<<endl;
     }
     return 0;
 }