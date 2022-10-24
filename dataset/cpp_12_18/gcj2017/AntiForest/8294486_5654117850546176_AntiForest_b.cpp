#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<62)-5)
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
 #define SZ(v) int(v.size())
 #define pb push_back
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 #define N_TYPS 6
 const char *IMP = "IMPOSSIBLE";
 int _T;
 
 int N, R, O, Y, G, B, V;
 char chrs[N_TYPS] = {'R', 'O', 'Y', 'G', 'B', 'V'};
 int vals[7];
 int nTyps;
 
 vector <string> compStrs[N_TYPS];
 vector <string> endStrs[3];
 
 void reset() {
     FO (i,0,7) vals[i] = 0;
     nTyps = 0;
     FO (i,0,N_TYPS) compStrs[i].clear();
     FO (i,0,3) endStrs[i].clear();
 }
 // returns if done.
 bool proc (int basicInd, int combInd) {
     int bVal = vals[basicInd];
     int cVal = vals[combInd];
     if (bVal < cVal) {
         puts(IMP);
         return true;
     }
     if (bVal == cVal && bVal != 0) {
         if (nTyps > 2) {
             puts(IMP);
             return true;
         }
         FO (i,0,bVal) {
             printf ("%c%c", chrs[basicInd], chrs[combInd]);
         }
         printf ("\n");
         return true;
     }
     if (cVal > 0) {
         string cStr = "";
         cStr += chrs[basicInd];
         vals[basicInd]--;
         while (vals[combInd] > 0) {
             vals[basicInd]--;
             vals[combInd]--;
             cStr += chrs[combInd];
             cStr += chrs[basicInd];
         }
         compStrs[basicInd].pb(cStr);
     }
     while (vals[basicInd] > 0) {
         compStrs[basicInd].pb(string(1,chrs[basicInd]));
         vals[basicInd]--;
     }
     return false;
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         reset();
         scanf ("%d %d %d %d %d %d %d", &N, &R, &O, &Y, &G, &B, &V);
         vals[0] = R;
         vals[1] = O;
         vals[2] = Y;
         vals[3] = G;
         vals[4] = B;
         vals[5] = V;
         nTyps = 0;
         FO (i,0,N_TYPS) {
             nTyps += vals[i] > 0;
         }
         // orange and blue:
         if (proc(4, 1)) {
             continue;
         }
         // green and red:
         if (proc(0, 3)) {
             continue;
         }
         // violet and yellow:
         if (proc(2, 5)) {
             continue;
         }
         endStrs[0] = compStrs[4];
         endStrs[1] = compStrs[0];
         endStrs[2] = compStrs[2];
         FO (i,0,3) {
             FO (j,0,3) {
                 if (endStrs[j+1].size() > endStrs[j].size()) {
                     swap (endStrs[j+1], endStrs[j]);
                 }
             }
         }
         if (endStrs[0].size() > endStrs[1].size() + endStrs[2].size()) {
             puts (IMP);
             continue;
         }
         string ans;
         FO (i,0,SZ(endStrs[0])) {
             ans += endStrs[0][i];
             if (i < SZ(endStrs[1])) {
                 ans += endStrs[1][i];
             }
             int revI = SZ(endStrs[0])-i-1;
             if (revI < SZ(endStrs[2])) {
                 ans += endStrs[2][revI];
             }
         }
         puts(ans.c_str());
     }
     return 0;
 }
