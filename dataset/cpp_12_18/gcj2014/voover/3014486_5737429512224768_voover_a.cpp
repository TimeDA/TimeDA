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
 
 
 bool taken[100000];
 int S[100000];
 void scase() {
   int N,X;
   scanf("%d%d",&N,&X);
   REP(i,N) {
     scanf("%d",&S[i]);
   }
   sort(S, S+N);
   REP(i,N) taken[i] = false;
   int n = 0;
   int result = 0;
   FORD(i,N,0) {
     if (taken[i]) break;
     if (S[i] + S[n] <= X) taken[n++] = true;
     taken[i] = true;
     ++result;
   }
   printf("%d\n", result);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
