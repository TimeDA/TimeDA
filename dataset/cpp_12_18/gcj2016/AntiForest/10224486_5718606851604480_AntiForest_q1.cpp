#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int _T;
 int N, R, P, S;
 
 int fWinner (int N, int R, int P, int S) {
     if (N == 0) {
         if (R) return 0;
         if (P) return 1;
         if (S) return 2;
     }
     int a = (R+P-S)/2;
     int b = (P+S-R)/2;
     int c = (S+R-P)/2;
     return fWinner (N-1,a,b,c);
 }
 
 string bestStr (int nRem, int type) {
     if (nRem == 0) {
         if (type == 0) return "R";
         if (type == 1) return "P";
         return "S";
     }
     string myAns1;
     string myAns2;
     string ch1 = bestStr(nRem-1,type);
     string ch2 = bestStr(nRem-1,(type+1)%3);
     myAns1 = ch1+ch2;
     myAns2 = ch2+ch1;
     if (myAns1 < myAns2) return myAns1;
     return myAns2;
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d %d %d", &N, &R, &P, &S);
         int mxAll = max(R,max(P,S));
         int mnAll = min(R,min(P,S));
         if (mxAll-mnAll != 1) {
             printf ("IMPOSSIBLE\n");
             continue;
         }
         int winner = fWinner(N,R,P,S);
         cout << bestStr(N,winner) << '\n';
     }
     return 0;
 }
