#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 using namespace std;
 typedef long long ll;
 
 char buf[110][110];
 
 const int DI[4] = {-1, 0, 1, 0};
 const int DJ[4] = {0, -1, 0, 1};
 const char* DIR = "^<v>";
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase){
     int nRow, nCol;
     scanf("%d%d", &nRow, &nCol);
     REP(i, nRow){
       scanf("%s", buf[i]);
     }
     
     printf("Case #%d: ", iCase+1);
     int res = 0;
     REP(i, nRow){
       REP(j, nCol){
 	REP(d, 4){
 	  if(buf[i][j] == DIR[d]){
 	    bool target = true;
 	    for(int ii = i + DI[d], jj = j + DJ[d];
 		ii >= 0 && jj >= 0 && ii < nRow && jj < nCol;
 		ii += DI[d], jj += DJ[d]){
 	      if(buf[ii][jj] != '.'){
 		target = false;
 		break;
 	      }
 	    }
 	    if(target){
 	      ++res;
 	      bool possible = false;
 	      REP(d2, 4){
 		for(int ii = i + DI[d2], jj = j + DJ[d2];
 		    ii >= 0 && jj >= 0 && ii < nRow && jj < nCol;
 		    ii += DI[d2], jj += DJ[d2]){
 		  if(buf[ii][jj] != '.'){
 		    possible = true;
 		    break;
 		  }
 		}
 	      }
 	      if(!possible){
 		res = -1;
 		goto OUT;
 	      }
 	    }
 	  }
 	}
       }
     }
     
   OUT:
     if(res < 0){
       puts("IMPOSSIBLE");
     }else{
       printf("%d\n", res);
     }
   }
   return 0;
 }
