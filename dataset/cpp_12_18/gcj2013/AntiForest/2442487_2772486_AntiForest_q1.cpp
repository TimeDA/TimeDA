#include <cstdio>
 #include <stack>
 #include <algorithm>
 
 #define MOD_N 1000002013
 using namespace std;
 
 struct aTask {
     long long plc, p;
     bool isEnd;
     aTask (long long _a=0, long long _b=0, bool _c=0) {
         plc = _a; p = _b; isEnd = _c;
     }
     bool operator < (const aTask &a) const {
         if (plc == a.plc) {
             return !isEnd;
         }
         return plc < a.plc;
     }
 };
 
 int T, N, M, s, e, p;
 int oldnT, nT;
 
 aTask allT[2005], cTask;
 stack <aTask> taskS;
 
 long long a, oA;
 
 long long nPop, temP;
 
 long long tri (int c) {
     long long rVal = c;
     rVal = (rVal * (rVal+1))/2;
     rVal %= MOD_N;
     return rVal;
 }
 
 void mySort() {
     for (int i = 0; i < nT; i++) {
         for (int j = 0; j < nT; j++) {
             if (allT[i] < allT[j]) swap (allT[i], allT[j]);
         }
     }
 }
 
 int main() {
     freopen ("q1.in", "r", stdin);
     freopen ("q1.out", "w", stdout);
     scanf ("%d", &T);
     for (int _z=1; _z<=T; _z++) {
         printf ("Case #%d: ", _z);
         scanf ("%d %d", &N, &M);
         nT = 0;
         oA = a = 0;
         s = e = p = 0;
         while (!taskS.empty()) taskS.pop();
         nPop = temP = 0;
         for (int i = 0; i < M; i++) {
             scanf ("%d %d %d", &s, &e, &p);
             allT[nT++] = aTask (s, p, false);
             allT[nT++] = aTask (e, p, true);
             oA += tri(e-s)*p;
             oA %= MOD_N;
         }
         oldnT = nT;
         mySort();
         for (int i = 0; i < nT; i++) {
             //printf ("%lld %lld %d\n", allT[i].plc, allT[i].p, allT[i].isEnd);
             if (allT[i].isEnd) {
                 nPop = allT[i].p;
                 while (nPop > 0) {
                     cTask = taskS.top();
                     temP = min (nPop, cTask.p);
                     if (temP == cTask.p) {
                         taskS.pop();
                     }
                     else {
                         taskS.top().p -= temP;
                     }
                     nPop -= temP;
                     a += tri (allT[i].plc-cTask.plc)*temP;
                     a %= MOD_N;
                 }
             } else {
                 taskS.push (allT[i]);
             }
         }
         //if (!taskS.empty()) printf ("FAIL\n");
         //printf ("%lld %lld\n", oA, a);
         printf ("%lld\n", (a-oA+MOD_N)%MOD_N);
     }
     return 0;
 }
