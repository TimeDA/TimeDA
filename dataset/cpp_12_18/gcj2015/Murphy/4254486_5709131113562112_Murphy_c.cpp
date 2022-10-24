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
 
 
 vector<int> e[1024000];
 vector<int> s, st, par;
 int D;
 
 int dfs(int x, int bd) {
     if (s[x] < bd || s[x] > bd + D) return 0;
     int res = 1; //st[x] = 1;
     // par[x] = max(par[x], s[x]);
     REP(i, e[x].size()) {
         // par[e[x][i]] = par[x];
         res += dfs(e[x][i], bd);
     }
     // cout<<"dfs"<<x<<' '<<res<<endl;
     return res;
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N; cin>>N>>D;
         REP(i, N) e[i].clear();
         int S0, As, Cs, Rs, M0, Am, Cm, Rm;
         cin>>S0>>As>>Cs>>Rs>>M0>>Am>>Cm>>Rm;
         // cout<<'s'<<N<<D<<endl;
         s.resize(N, 0);
         st.resize(N, 0); par.resize(N, 0);s[0] = S0;
         vector<pii> V; V.pb(make_pair(s[0], 0));
         REP(i, N) {
             if (!i) continue;
             S0 = (S0 * (LL)As + Cs) % Rs;
             M0 = (M0 * (LL)Am + Cm) % Rm;
             // cout<<i<<'k'<<S0<<' '<<M0<<endl;
             e[M0 % i].pb(i);
             s[i] = S0;
             V.pb(make_pair(S0, i));
         }
         sort(V.begin(), V.end());
         int best = 0;
         REP(i, N) {
         	// cout<<i<<' '<<best<<endl;
         	best = max(best, dfs(0,V[i].first));
         }
     	printf("Case #%d: %d\n", caseN + 1,  best);
     }
 }