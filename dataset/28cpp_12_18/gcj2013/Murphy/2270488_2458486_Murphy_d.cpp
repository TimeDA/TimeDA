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
 
 int fat[1<<20];
 
 vector<int> ks[32];
 int open[32];
 int keys[256];
 int N, K, tmp;
 
 void gao(int o) {
 //cout<<o<<' '<<N<<endl;
 	REP(i, N) {
 		if ((o & (1<<i)) == 0) {
 			if (keys[open[i]]) {
 				int nxt = o | (1<<i);
 				//cout<<o<<' '<<nxt<<endl;
 				if (fat[nxt] == -1) {
 					fat[nxt] = i;
 					keys[open[i]]--;
 					REP(j, ks[i].size()) {
 						keys[ks[i][j]]++;
 					}
 					gao(nxt);
 					keys[open[i]]++;
 					REP(j, ks[i].size()) {
 						keys[ks[i][j]]--;
 					}
 				}
 			}
 		}
 	}
 }
 
 void output(int k) {
 	if (k == 0) {
 		return;
 	}
 	int f = fat[k];
 	output(k - (1<<f));
 	printf(" %d", f + 1);
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
 		cin>>K>>N;
 		memset(keys, 0, sizeof keys);
 		REP(i, K) {
 			cin>>tmp;
 			keys[tmp]++;
 		}
 		REP(i, N) {
 			cin>>open[i]>>K;
 			ks[i].clear();
 			REP(j, K) {
 				cin>>tmp;
 				ks[i].pb(tmp);
 			}
 		}
 		memset(fat, -1, sizeof fat);
 		gao(0);
         printf("Case #%d:", caseN + 1);
 		if (fat[(1<<N) - 1] == -1) {
 			puts(" IMPOSSIBLE");
 		} else {
 			output((1<<N) - 1);
 			puts("");
 		}
     }
     return 0;
 }
