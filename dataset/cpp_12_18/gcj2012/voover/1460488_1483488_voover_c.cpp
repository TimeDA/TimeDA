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
 int p10s[10];
 
 int L = 0;
 bool check(int x, int y) {
     REP(l,L) {
         if (x == y / p10s[l] + y % p10s[l] * p10s[L-l]) return true;
     }
     return false;
 }
 
 int main() {
     p10s[0] = 1;
     for (int i = 1; i < 10; ++i) p10s[i] = p10s[i-1] * 10;
 
     int T;
     scanf("%d",&T);
     FOR(i,1,T+1) {
         printf("Case #%d: ",i);
         int A,B;
         scanf("%d%d",&A,&B);
         for(L = 1; A >= p10s[L]; ++L);
         
         int result = 0;
         for (int x = A; x <= B; ++x)
             for (int y = x + 1; y <= B; ++y)
                 result += check(x,y);
         printf("%d\n",result);
     }
 }    
