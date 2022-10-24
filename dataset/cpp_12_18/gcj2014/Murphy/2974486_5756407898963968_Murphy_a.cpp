#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     int r;
     REP(caseN, caseNumber) {
     	int N; r = 0;
         cin>>N;
         REP(i, 4) {
             REP(j, 4) {
                 int t;
                 cin>>t;
                 if (i == N - 1) {
                     r |= (1 << t);
                 }
             }
         }
         cin>>N;
         REP(i, 4) {
             REP(j, 4) {
                 int t;
                 cin>>t;
                 if (i != N - 1) {
                     r &= ~(1 << t);
                 }
             }
         }
     	printf("Case #%d: ", caseN + 1);
         if (r == 0) {
             puts("Volunteer cheated!");
         } else {
             if (__builtin_popcount(r) > 1) {
                 puts("Bad magician!");
             } else {
                 printf("%d\n", __builtin_ctz(r));
             }
         }
     }
     return 0;
 }