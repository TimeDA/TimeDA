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
 
 int A[3000], B[3000];
 
 list<int> adj[3000];
 int indeg[3000];
 
 int out[3000];
 void scase() {
     REP(i,3000) adj[i].clear();
 
     int N;
     scanf("%d",&N);
     REP(i,N) scanf("%d",&A[i]);
     REP(i,N) scanf("%d",&B[i]);
     
     REP(i,N) {
         if (A[i] != 1) {
             FORD(j,i,0) if (A[j] == A[i] - 1) {
                 adj[j].push_back(i);
                 break;                
             }        
         }
         FOR(j,i+1,N) if (A[j] <= A[i]) adj[j].push_back(i);
         
         if (B[i] != -1) {
             FOR(j,i+1,N) if (B[j] == B[i] - 1) {
                 adj[j].push_back(i);
                 break;
             }
             FORD(j,i,0) if (B[j] <= B[i]) adj[j].push_back(i);
         }
     }
     REP(i,N) indeg[i] = 0;
     
     REP(i,N)FOREACH(it, adj[i]) {
         indeg[*it]++;
     }
     
     priority_queue<int, vector<int>, greater<int> > Q;
     REP(i,N) if (!indeg[i]) Q.push(i);
     
     int X = 0;
     while (!Q.empty()) {
         int k = Q.top();
         Q.pop();
         out[k] = ++X;
         FOREACH(it, adj[k]) {
             --indeg[*it];
             if (!indeg[*it]) Q.push(*it);
         }
     }
     
     REP(i,N)printf("%d ",out[i]);
     printf("\n");
 }
 
 int main() {
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 }  
