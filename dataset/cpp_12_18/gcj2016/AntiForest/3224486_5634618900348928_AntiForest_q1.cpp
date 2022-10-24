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
 
 int T;
 
 char allTypes[20005];
 
 int main() {
     scanf ("%d", &T);
     FO (_z,0,T) {
         int ans = 0;
         vector<int> cStack;
         printf ("Case #%d: ", _z+1);
         scanf (" %s", allTypes);
         int N = strlen(allTypes);
         FO (i,0,N) {
             cStack.push_back (allTypes[i]);
             while (cStack.size() >= 2) {
                 if (cStack[cStack.size()-1] == cStack[cStack.size()-2]) {
                     ans += 10;
                     cStack.pop_back();
                     cStack.pop_back();
                 } else {
                     break;
                 }
             }
         }
         ans += 5 * cStack.size()/2;
         printf ("%d\n", ans);
     }
     return 0;
 }
