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
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     int r;
     vector<pii> V;
     REP(caseN, caseNumber) {
     	int N;
     	cin>>N;V.clear();
     	REP(i, N) cin>>r;
     	REP(i, N) {
     		cin>>r;
     		V.pb(make_pair(-r, i));
     	}
     	sort(V.begin(), V.end());
     	printf("Case #%d:", caseN + 1);
     	REP(i, N)
     		printf(" %d", V[i].second);
     	puts("");
     }
     return 0;
 }