
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <iostream>
 #include <cassert>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 int vs[10];
 
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     memset(vs, 0, sizeof vs);
     int n, p;
     scanf("%d%d", &n, &p);
     REP(i, n) {
       int v;
       scanf("%d", &v);
       v %= p;
       vs[v]++;
     }
     int res = 0;
     // REP(i, 4){
     //   cerr << vs[i] << " ";
     // }
     // cerr << endl;
     if(p == 2) {
       res += vs[0];
       res += (vs[1]+1) / 2;
     } else if(p == 3) {
       res += vs[0];
       while(vs[1] > 0 || vs[2] > 0) {
         if(vs[2] > 0) {
           vs[2]--;
           res++;
           if(vs[1] > 0) {
             vs[1]--;
           } else {
             vs[2]-= 2;
           }
         } else {
           vs[1] -= 3;
           ++res;
         }
       }
     } else if(p == 4) {
       res += vs[0];
       while(vs[1] > 0 || vs[2] > 0 || vs[3] > 0) {
         if(vs[3] > 0) {
           // XXX
         } else if(vs[2] > 0) {
           // XXX
         } else {
           vs[1] -= 4;
           ++res;
         }
       }
       
       
     } else {
       assert(false);
     }
     
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
