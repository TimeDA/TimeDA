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
 
 int r[1024][1024]; 
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	int N, C, M;
     	cin>>N>>C>>M;
     	memset(r, 0, sizeof(r));
     	REP(i, M) {
     		int B, P; cin>>P>>B;
     		r[B][P]++;
     	}
     	for (int ccc = r[1][1] + r[2][1]; ccc <= 1024; ccc++) {
 	    	int pro = 0, o1 = 0, o2 = 0, o3 = ccc;
 	    	o1 = r[1][1]; o2 = r[2][1];
 	    	o3 -= o1 + o2;
 	    	int succ = 1;
 	    	for (int i = 2; i < 10; i++) {
 	    		int l1 = r[1][i], l2 = r[2][i];
 	    		int oo1 = o1, oo2 = o2;
 	    		int b1 = min(o3, l1); o3 -= b1; l1 -= b1; o1 += b1;
 	    		int b2 = min(o3, l2); o3 -= b2; l2 -= b2; o2 += b2;
 	    		// cerr<<ccc<<' '<<l1<<' '<<l2<<' '<<o1<<' '<<o2<<' '<<o3<<' '<<pro<<endl;
 	    		if (l1) {
 	    			if (o2 >= l1) {o2 -= l1; pro += max(l1 - oo2, 0);} else succ = 0;
 	    		}
 	    		if (l2) {
 	    			if (o1 >= l2) {o1 -= l2; pro += max(l2 - oo1, 0);} else succ = 0;
 	    		}
 	    	}
 	    	if (succ) {
 				printf("Case #%d: %d %d\n", caseN + 1, ccc, pro);
 				break;
 	    	}
     	}
 
     }
     return 0;
 }