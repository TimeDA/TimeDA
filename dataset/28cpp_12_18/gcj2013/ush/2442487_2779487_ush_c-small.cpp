
 #include <cstdio>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <cmath>
 #include <complex>
 #include <numeric>
 #include <cassert>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 typedef long long ll;
 const int INF = 0x77777777;
 int n;
 int ans[3000];
 int as[3000];
 int bs[3000];
 
 inline int getA(int idx) {
   vector<int> st;
   for(int i = 0; i < idx; ++i){
     if(ans[i] != INF){
       vector<int>::iterator it = lower_bound(st.begin(), st.end(), ans[i]);
       if(it == st.end()){
 	st.push_back(ans[i]);
       }else{
 	*it = ans[i];
       }
     }
   }
   return st.size() + 1;
 }
 
 inline int getB(int idx) {
   vector<int> st;
   for(int i = n-1; i > idx; --i){
     if(ans[i] != INF){
       vector<int>::iterator it = lower_bound(st.begin(), st.end(), ans[i]);
       if(it == st.end()){
 	st.push_back(ans[i]);
       }else{
 	*it = ans[i];
       }
     }
   }
   return st.size() + 1;
 }
 
 inline bool solve(int num) {
   if(num > n)
     return true;
   REP(i, n){
     if(ans[i] == INF){
       int a = getA(i);
       int b = getB(i);
       if(as[i] == a && bs[i] == b){
 	ans[i] = num;
 	if(solve(num+1))
 	  return true;
 	ans[i] = INF;
       }	    
     }
   }
   return false;
 }
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     cin >> n;
     REP(i, n)
       cin >> as[i];
     REP(i, n)
       cin >> bs[i];
     
     fill(ans, ans + n, INF);
     solve(1);
     
     cout << "Case #" << (iCase+1) << ":";
     REP(i, n)
       cout << " " << ans[i];
     cout << endl;
   }
   
   return 0;
 }
