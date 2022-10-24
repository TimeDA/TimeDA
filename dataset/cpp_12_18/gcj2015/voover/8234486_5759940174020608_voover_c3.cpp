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
 
 char line[1000000];
 vector<int> words[25];
 
 int definitely_english[1000000], definitely_french[1000000], english[1000000], french[1000000];
 int counted[1000000];
 
 void scase() {
   REP(i,1000000) {definitely_english[i] = definitely_french[i] = english[i] = french[i] = counted[i] = 0;}
 
   int N;
   scanf("%d\n", &N);
   map<string, int> M;
   REP(i,N) {
     words[i].clear();
     gets(line);
     int last = 0;
     for (int j = 0;; ++j) {
       if (line[j] == ' ' || line[j] == 0) {
         string word(line, last, j - last);
         if (M.find(word) == M.end()) M[word] = M.size();
         words[i].push_back(M[word]);
         //printf("!!!%d\n", M[word]);
         if (line[j] == ' ') last = j + 1;
         else break;
       }
     }
   }
  
   FOREACH(it, words[0]) {
     definitely_english[*it] = 1;
   }
   int result_a = 0;
   FOREACH(it, words[1]) {
     if (definitely_french[*it]) continue;
     definitely_french[*it] = 1;
     if (definitely_english[*it]) {
       ++result_a;
       counted[*it] = -1;
     }
   }
   
   int result_b = 9999999;
   REP(mask, 1<<(N - 2)) {
     int mask2 = mask;
     int tmp = 0;
     FOR(i,2,N) {
       bool is_english = mask2&1;
       mask2 >>= 1;
       
       FOREACH(it, words[i]) {
         if (is_english) {
           english[*it] = mask + 1;
         } else french[*it] = mask + 1;
         
         if (counted[*it] == -1 || counted[*it] == mask + 1) continue;
         if ((english[*it] == mask + 1 || definitely_english[*it])
             && (french[*it] == mask + 1 || definitely_french[*it])) {
               counted[*it] = mask + 1;
               ++tmp;
             } 
       }
     }
     result_b = min(result_b, tmp);
   }
   
   printf("%d\n", result_a + result_b);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
