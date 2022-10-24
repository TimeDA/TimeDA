#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int T;
 
 int N;
 vector <int> sym[25];
 
 int nS;
 map <string, int> allS;
 
 bool hasC[20005][2];
 int ans (INF);
 
 int main() {
     freopen ("c.in", "r", stdin);
     freopen ("c.out", "w", stdout);
     scanf ("%d", &T);
     FO (_z,0,T) {
         ans = INF;
         nS = 0;
         allS.clear();
         printf ("Case #%d: ", _z+1);
         scanf ("%d ", &N);
         FO (i,0,N) {
             sym[i].clear();
             for (;;) {
                 string tem;
                 cin >> tem;
                 if (allS.find (tem) == allS.end()) {
                     sym[i].push_back (nS);
                     allS.insert (mp (tem, nS++));
                 } else {
                     map <string,int>::iterator myIt = allS.find (tem);
                     sym[i].push_back ((*myIt).second);
                 }
                 char temC;
                 scanf ("%c", &temC);
                 if (temC == '\n') break;
             }
         }/*
         FO (i,0,N) {
             FO (p,0,sym[i].size()) {
                 printf ("%d ", sym[i][p]);
             }
             printf ("\n");
         }*/
         FO (i,0,(1<<N)) {
             FO (p,0,nS) hasC[p][0] = hasC[p][1] = false;
             if (i&1 || !(i&2)) continue;
             FO (p,0,N) {
                 int wS = ( (i&(1<<p)) != 0);
                 FO (t,0,sym[p].size()) {
                     hasC[sym[p][t]][wS] = true;
                 }
             }
             int cAns = 0;
             FO (p,0,nS) {
                 if (hasC[p][0] && hasC[p][1]) {
                     cAns++;
                 }
             }
             ans = min (cAns, ans);
         }
         printf ("%d\n", ans);
     }
     return 0;
 }
         
         
         
         
         
         
         
         
