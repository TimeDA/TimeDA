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
     	double C, F, X;
         cin>>C>>F>>X;
         double r = 1e10;
         double P = 2;
         double passed = 0;
         //double producted = 0;
         while (1) {
             double tr = X / P;
             r = min(r, tr + passed);
             if (passed > r) {
                 break;
             }
             passed += C / P;
             P += F;
         }
         
     	printf("Case #%d: %.10lf\n", caseN + 1, r);
     }
     return 0;
 }