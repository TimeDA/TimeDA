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
 
 bool v[1024][1024];
 int h[1024][1024];
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
 		bool answer = true;
 		int x, y;
 		cin>>x>>y;
 		REP(i, x) {
 			REP(j, y) {
 				cin>>h[i][j];
 				v[i][j] = 0;
 			}
 		}
 		//cout<<x<<' '<<y<<endl;
 		while (1) {
 			int fx = -1, fy = -1;
 			REP(i, x) {
 				REP(j, y) {
 					if (v[i][j] == 0) {
 						if (fx == -1 || h[i][j] < h[fx][fy]) {
 							fx = i;
 							fy = j;
 						}
 					}
 				}
 			}
 			//cout<<fx<<' '<<fy<<' '<<h[fx][fy]<<endl;
 			if (fx == -1) {
 				break;
 			}
 			int succ;
 			succ = 1;
 			REP(i, x) {
 				if (v[i][fy] == 0) {
 					succ &= h[i][fy] == h[fx][fy];
 				}
 			}
 			if (succ) {
 				REP(i, x) {
 					v[i][fy] = 1;
 				}
 				continue;
 			}
 			succ = 1;
 			REP(i, y) {
 				if (v[fx][i] == 0) {
 					succ &= h[fx][i] == h[fx][fy];
 				}
 			}
 			if (succ) {
 				REP(i, y) {
 					v[fx][i] = 1;
 				}
 				continue;
 			}
 			answer = false;
 			break;
 		}
         printf("Case #%d: ", caseN + 1);
 		if (answer) {
 			puts("YES");
 		} else {
 			puts("NO");
 		}
     }
     return 0;
 }
