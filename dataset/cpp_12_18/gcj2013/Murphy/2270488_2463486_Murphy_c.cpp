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
 
 vector<LL> p;
 
 
 char c[100];
 bool P(LL x) {
 	int L = 0;
 	while (x) {
 		c[L++] = x % 10;
 		x /= 10;
 	}
 	for (int i = 0, j = L - 1; i < j; i++, j--) {
 		if (c[i] != c[j]) {
 			return false;
 		}
 	}
 	return true;
 }
 
 int main(){
 	for (int i = 1; i <= 10000000; i++) {
 		if (P(i)) {
 			LL x = 1LL * i * i;
 			if (P(x)) {
 				p.pb(x);
 				//cout<<i<<endl;
 			}
 		}
 	}
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
 		int A, B;
 		cin>>A>>B;
 		int r = 0;
 		REP(i, p.size()) {
 			if (p[i] > B) {
 				break;
 			}
 			if (p[i] >= A) {
 				r++;
 			}
 		}
         printf("Case #%d: %d\n", caseN + 1, r);
     }
     return 0;
 }
