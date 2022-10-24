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
     REP(caseN, caseNumber) {
 		string s[4];
 		REP(i, 4) cin>>s[i];
 		bool empty = false;
 		REP(i, 4)
 			REP(j, 4)
 				empty |= s[i][j] == '.';
 		bool win[2] = {false, false};
 		REP(r, 2) {
 			char c = r ? 'O' : 'X';
 			REP(i, 4) {
 				bool y = true;
 				REP(j, 4) {
 					y &= s[i][j] == c || s[i][j] == 'T';
 				}
 				win[r] |= y;
 			}
 			REP(i, 4) {
 				bool y = true;
 				REP(j, 4) {
 					y &= s[j][i] == c || s[j][i] == 'T';
 				}
 				win[r] |= y;
 			}			
 			{
 				bool y = true;
 				REP(j, 4) {
 					y &= s[j][j] == c || s[j][j] == 'T';
 				}
 				win[r] |= y;
 			}
 			{
 				bool y = true;
 				REP(j, 4) {
 					y &= s[j][3 - j] == c || s[j][3 - j] == 'T';
 				}
 				win[r] |= y;
 			}
 		}
         printf("Case #%d: ", caseN + 1);
 		if (win[0]) {
 			puts("X won");
 			continue;
 		} 
 		if (win[1]) {
 			puts("O won");
 			continue;
 		}
 		if (empty) {
 			puts("Game has not completed");
 			continue;
 		} else {
 			puts("Draw");
 			continue;
 		}
     }
     return 0;
 }
