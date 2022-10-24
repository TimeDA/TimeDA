#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 map<int, int> compress(vector<int> v){
     map<int, int> m;
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()), v.end());
     REP(i, v.size()){
         m[v[i]] = i;
     }
     return m;
 }
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++){
         printf("Case #%d: ", casenum);
         int N;
         cin >> N;
         vector<string> type(N);
         vector<int> id(N);
         vector<int> all;
         for(int i = 0; i < N; i++){
             cin >> type[i] >> id[i];
             if(id[i] != 0) {
                 all.push_back(id[i]);
             }
         }
         map<int, int> index = compress(all);
         REP(i, N) if(id[i] != 0) id[i] = index[ id[i] ] + 1;
         bool ok[16][1 << 16] = {};
         REP(i, N + 1) REP(s, 1 << N) ok[i][s] = (i == 0 ? true : false);
         REP(i, N) REP(s, 1 << N) if(ok[i][s]) {
             REP(x, N) if(id[i] == 0 || id[i] == x + 1) {
                 if(((s >> x & 1) && type[i] == "L") || (!(s >> x & 1) && type[i] == "E")) {
                     int ns = s ^ (1 << x);
                     ok[i + 1][ns] = true;
                 }
             }
         }
         int ans = INT_MAX;
         REP(s, 1 << N) {
             if(ok[N][s]) {
                 ans = min(ans, __builtin_popcount(s));
             }
         }
         if(ans < INT_MAX) {
             cout << ans << endl;
         }else {
             cout << "CRIME TIME" << endl;
         }
     }
     return 0;
 }
 
