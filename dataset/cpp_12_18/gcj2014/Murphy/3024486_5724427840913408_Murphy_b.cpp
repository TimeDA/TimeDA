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
 
 int H[128], G[128];
 int P, Q, N;
 int E[255];
 int hit[128][1280], nhit[128][1280];
 
 void update(int ht, int n, int times) {
 	if (ht == 1 ){
 		int pre = n == -1 ? 0: hit[n][times];
 		{
 			//cout<<ht<<' '<<n<<' '<<times<<' '<<pre<<endl;
 				if (H[n + 1] <= Q) {
 					//kit to death
 					nhit[n + 1][times] = max(nhit[n + 1][times], pre);
 				} else {
 					int blood = H[n + 1] - Q;
 					int cost = E[blood];
 					int saving = blood % Q == 0 ? blood / Q : blood / Q + 1;
 					//not hit
 					nhit[n + 1][times + saving] = max(nhit[n + 1][times + saving], pre);
 					if (cost != -100 && times + cost >= 0)
 					hit[n + 1][times + cost] = max(hit[n + 1][times + cost], pre + G[n + 1]);
 		
 				}
 				int blood = H[n + 1];
 				int s2 = blood % P == 0 ? blood / P : blood / P + 1;
 				int cost = -s2;
 				if (cost != -100 && times + cost >= 0)
 				hit[n + 1][times + cost] = max(hit[n + 1][times + cost], pre + G[n + 1]);
 		
 		}
 	} else {
 		int pre = n == -1 ? 0: nhit[n][times];
 	//cout<<ht<<' '<<n<<' '<<times<<' '<<pre<<endl;
 		int blood = H[n + 1];
 		int cost = E[blood];
 		int saving = blood % Q == 0 ? blood / Q : blood / Q + 1;
 		//not hit
 		nhit[n + 1][times + saving] = max(nhit[n + 1][times + saving], pre);
 		if (cost != -100 && times + cost >= 0)
 		hit[n + 1][times + cost] = max(hit[n + 1][times + cost], pre + G[n + 1]);
 	}
 }
 
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>P>>Q>>N;
     	for (int i = 1; i <= 200; i++) {
     		E[i] = -100;
     		REP(a, 11) REP (b, 11) {
     			if (a * P + b * Q >= i) continue;
     			if (a * P + b * Q + P >= i) {
     				E[i] = max(E[i], b - a);
     			}
     		}
     	}
     	REP(i, N) { cin>>H[i]>>G[i];//cout<<"E"<<E[H[i]]<<endl;
     }
     	memset(hit, -1, sizeof hit);
     	memset(nhit, -1, sizeof nhit);
     	update(0, -1, 0);
     	REP(i, N - 1) {
 			REP(j, N * 10 + 20) {
 				if (hit[i][j] != -1)
     				update(1, i, j);
 				if (nhit[i][j] != -1)
     				update(0, i, j);
 			}
     	}
 
     	int best = 0;
 		REP(j, N * 10 + 20) {
 			// if (hit[N - 1][j] != -1)
 			// cout<<"ht"<<j<<' '<<hit[N - 1][j]<<endl;
 			// if (nhit[N - 1][j] != -1)
 			// cout<<"nht"<<j<<' '<<nhit[N - 1][j]<<endl;
 			best = max(best, hit[N - 1][j]);
 			best = max(best, nhit[N - 1][j]);
 		}
 
     	printf("Case #%d: %d\n", caseN + 1, best);
     }
     return 0;
 }