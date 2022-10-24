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
 
 char buf[6][500];
 
 char code[256];
 char decode[256];
 
 string X = "yhesocvxduiglbkrztnwjpfmaq";
 
 char S[1000];
 int main() {
 /*    REP(i,6)gets(buf[i]);
     REP(i,3) {
         for(int j = 0; buf[i][j]; ++j)
             decode[buf[i][j]] = buf[i+3][j];
         for(int j = 0; buf[i][j]; ++j)
             code[buf[i+3][j]] = buf[i][j];            
     }
     code['q'] = 'z';
     code['z'] = 'q';
     decode['q'] = 'z';
     decode['z'] = 'q';
     printf("%s\n",decode + 'a');*/
     int N;
     scanf("%d\n",&N);
     FOR(i,1,N+1) {
         gets(S);
         printf("Case #%d: ",i);
         for(int j = 0; S[j]; ++j)    
             if (S[j] >= 'a' && S[j] <= 'z')
                 S[j] = X[S[j]-'a'];
         printf("%s\n",S);
     }
 }    
