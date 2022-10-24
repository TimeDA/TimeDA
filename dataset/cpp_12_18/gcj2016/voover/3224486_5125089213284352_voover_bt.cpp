#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <complex>
 #include <sstream>
 using namespace std;
  
 typedef long long LL;
 typedef unsigned long long ULL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
 #define ALL(v) (v).begin(), (v).end()
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 bool before[200][200];
 
 int base_order[100];
 const int SAMPLES = 2000;
 const int MUTATIONS = 35000;
 
 char letters[200];
 
 char buf[200];
 int M;
 string cool[100];
 
 int order[100];
 
 int found[200];
 
 void scase() {
   int N;
   scanf("%d", &N);
   REP(i,N)REP(j,N) before[i][j] = false;
   REP(i,200) found[i] = 0;
 
   queue<int> Q;
   REP(i,N) {
     int a;
     scanf("%d", &a);
     if (a > 0) {
       --a;
       before[a][i] = true;
     } else Q.push(i);
   }
   
   scanf("%s%d", letters, &M);
   REP(i,M) {
     scanf("%s", buf);
     cool[i] = string(buf);
   }
   
   int ii = 0;
   while (!Q.empty()) {
     int k = Q.front();
     Q.pop();
     base_order[ii++] = k;
     REP(i,N) if (before[k][i]) Q.push(i);
   }
   
   REP(k,N)REP(i,N)REP(j,N) if (before[i][k] && before[k][j]) before[i][j] = true;
   
   REP(ss, SAMPLES) {
     REP(i,N) order[i] = base_order[i];
     if (N > 1) {
       REP(mm, MUTATIONS) {
         int rd = rand() % (2 * (N - 1));
         if (rd & 1) continue;
         int k = rd >> 1; 
         if (!before[order[k]][order[k+1]]) swap(order[k], order[k+1]);
       }
     }
     
     string word;
     REP(i,N) word += letters[order[i]];
     REP(i,M) if (word.find(cool[i]) != string::npos) found[i]++;
   }
   
   REP(i,M) printf("%0.2lf ", (double)found[i] / SAMPLES);
   printf("\n");
   fflush(stdout);
 }
 
 int main() {
 //  REP(i, R) randomized[i] = rand();
 
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
 
