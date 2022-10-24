
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <iostream>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 int len;
 
 set<int> visited;
 int go(char *sv) {
   int v = atoi(sv);
   if(visited.count(v)) {
     return 0;
   }
   visited.insert(v);
   int res = 1;
   // cerr << ">> " << sv << endl;
 
   int sum = 0;
   REP(i, len) {
     sum += sv[i] - '0';
   }
   if(sum > len) {
     return res;
   }
   
   char buf[10] = "000000000";
   int ii = len-sum;
   REP(i, len) {
     for(int j = 0; j < sv[i] - '0'; ++j) {
       buf[ii++] = '1' + i;
     }
   }
   buf[len] = 0;
   do {
     res += go(buf);
   } while(next_permutation(buf, buf + len));
   return res;
 }
 
 
 int main(void) {
   int nCase;
   char buf[20];
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     scanf("%s", buf);
     len = strlen(buf);
     // int n = atoi(buf);
     // cerr << "n = " << n << " len = "  << len << endl;
     int res = 0;
     visited.clear();
     res = go(buf);
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
 
