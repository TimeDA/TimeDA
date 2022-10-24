#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 #define N_SAMPLES 30000
 
 int T;
 int N, M;
 int p[105];
 char l[105];
 char str[6][22];
 int strL[6];
 
 vector <int> allC[105];
 int sz[105];
 long double nWays[105];
 
 long double chs[105][105];
 
 int ans[6];
 
 void resetAll() {
     FO (i,0,N+1) {
         allC[i].clear();
         sz[i] = 0;
         nWays[i] = 0;
         ans[i] = 0;
     }
 }
 
 void fInfo (int c) {
     //fprintf (stderr, "FINFO: %d\n", c);
     nWays[c] = 1;
     FO (i,0,allC[c].size()) {
         fInfo(allC[c][i]);
         int temSz = sz[c] + sz[allC[c][i]];
         nWays[c] = nWays[c]*chs[temSz][sz[c]]*nWays[allC[c][i]];
         sz[c] = temSz;
     }
     sz[c]++;
     //printf ("nWays: %d %Lf\n", c, nWays[c]);
 }
 
 vector <char> myStr;
 vector <int> cQueue;
 
 
 void tryWay() {
     cQueue.clear();
     myStr.clear();
     FO (i,0,allC[0].size()) cQueue.push_back(allC[0][i]);
     while (!cQueue.empty()) {
         //fprintf (stderr, "SIZE: %d\n", cQueue.size());
         vector <int> nQueue;
         vector <long double> allProbs;
         vector <int> allN;
         long double totProb = 0;
         long double knownProb = 1;
         int _tN = 0;
         FO (p,0,cQueue.size()) {
             int temTN = _tN;
             knownProb *= nWays[cQueue[p]];
             temTN += sz[cQueue[p]];
             if (p == cQueue.size()-1) temTN--;
             knownProb *= chs[temTN][_tN];
             _tN = temTN;
             allN.push_back (_tN);
         }
         allProbs.push_back (knownProb);
         for (int i = cQueue.size()-2; i >= 0; i--) {
             int cAftN = allN[i+1];
             int ccN = allN[i];
             int prevN = 0;
             if (i != 0) prevN = allN[i-1];
             knownProb /= chs[cAftN][ccN];
             knownProb /= chs[ccN][prevN];
             allN[i]--;
             ccN = allN[i];
             knownProb *= chs[cAftN][ccN];
             knownProb *= chs[ccN][prevN];
             allProbs.push_back(knownProb);
         }
         // Pick one of the nodes randomly:
         reverse(allProbs.begin(),allProbs.end());
         FO (i,1,allProbs.size()) {
             allProbs[i] += allProbs[i-1];
         }
         totProb = allProbs[allProbs.size()-1];
         int cRand = rand() % RAND_MAX;
         long double myRand = cRand*totProb/RAND_MAX;
         int myNode = 0;
         FO (i,0,allProbs.size()) {
             if (myRand < allProbs[i] || i == allProbs.size()-1) {
                 myNode = i;
                 break;
             }
         }
         FO (i,0,cQueue.size()) {
             if (i != myNode) nQueue.push_back (cQueue[i]);
             else {
                 FO (p,0,allC[cQueue[i]].size()) {
                     nQueue.push_back(allC[cQueue[i]][p]);
                 }
                 myStr.push_back (l[cQueue[i]]);
             }
         }
         cQueue = nQueue;
     }
     //FO (i,0,myStr.size()) printf ("%c", myStr[i]);
     //printf ("\n");
     // Count string occurrences:
     FO (i,0,M) {
         FO (p,0,N-strL[i]+1) {
             bool found = false;
             FO (t,0,strL[i]) {
                 if (myStr[p+t] != str[i][t]) break;
                 if (t == strL[i]-1) found = true;
             }
             if (found) {
                 ans[i]++;
                 break;
             }
         }
     }
 }
 
 
 int main() {
     srand(time(NULL));
     scanf ("%d", &T);
     FO (i,0,105) chs[i][0] = 1;
     FO (i,1,105) {
         FO (p,1,i+1) {
             chs[i][p] = chs[i-1][p-1]+chs[i-1][p];
         }
     }
     FO (_z,0,T) {
         printf ("Case #%d: ", _z+1);
         resetAll();
         scanf ("%d", &N);
         FO (i,1,N+1) {
             scanf ("%d ", &p[i]);
             allC[p[i]].push_back(i);
         }
         FO (i,1,N+1) {
             scanf ("%c", &l[i]);
         }
         scanf ("%d", &M);
         FO (i,0,M) {
             scanf (" %s", str[i]);
             strL[i] = strlen(str[i]);
         }
         fInfo(0);
         int actSamples = 0;
         clock_t startT = clock();
         FO (i,0,N_SAMPLES) {
             tryWay();
             actSamples++;
             clock_t cT = clock();
             if ((1.0*(cT-startT)) > (3*CLOCKS_PER_SEC) || actSamples >= 30000) break;
         }
         FO (i,0,M) printf ("%.4lf ", (1.0*ans[i])/actSamples);
         printf ("\n");
         fprintf (stderr, "actSamples: %d\n", actSamples);
         fprintf (stderr, "DONE %d: %d\n", _z, N);
     }
     return 0;
 }
