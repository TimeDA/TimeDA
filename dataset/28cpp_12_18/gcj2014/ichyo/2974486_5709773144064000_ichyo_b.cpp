#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 int main(){
     int TESTCASE;
     cin >> TESTCASE;
     for(int casenumber = 0; casenumber < TESTCASE; casenumber++){
         printf("Case #%d: ", casenumber + 1);
         double C, F, X;
         cin >> C >> F >> X;
         double ans = X / 2.0;
         double sum = C / 2.0;
         const int MAX_K = 1000000;
         for(int k = 1; k <= MAX_K; k++){
             ans = min(ans, sum + X / (2.0 + F * k));
             sum += C / (2.0 + F * k);
         }
         printf("%.7f\n", ans);
     }
     return 0;
 }
 
