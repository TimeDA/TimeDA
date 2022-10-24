#include <algorithm>  
 #include <iostream>  
 #include <sstream>  
 #include <string>  
 #include <vector>  
 #include <queue>  
 #include <set>  
 #include <map>  
 #include <cstdio>  
 #include <cstdlib>  
 #include <cctype>  
 #include <cmath>  
 #include <list>  
 #include <climits>
 #include <cassert>
 using namespace std;  
 
 #define PB push_back  
 #define MP make_pair  
 #define SZ(v) ((int)(v).size())  
 #define FOR(i,a,b) for(int i=(a);i<(b);++i)  
 #define REP(i,n) FOR(i,0,n)  
 #define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
 #define REPE(i,n) FORE(i,0,n)  
 #define FORSZ(i,a,v) FOR(i,a,SZ(v))  
 #define REPSZ(i,v) REP(i,SZ(v))  
 typedef long long ll;  
 
 const int MAXN=9;
 
 char s[MAXN+1]; int n;
 int C[MAXN+1][MAXN+1];
 
 set<string> seen;
 
 ll go(string at) {
 	int sum=0; REP(i,n) sum+=at[i]-'0'; if(sum>n) return 1;
 	int sum2=0; REP(i,n) sum2+=(i+1)*(at[i]-'0'); if(sum2>n) {
 		ll ret=1; 
 		int rem=n; REP(i,n) ret=ret*C[rem][at[i]-'0'],rem-=at[i]-'0';
 		return ret+1;
 	}
 
 	if(seen.count(at)) return 0; else seen.insert(at);
 	string to(n,'0'); int pos=0; REP(i,n) REP(j,at[i]-'0') to[pos++]='0'+i+1; sort(to.begin(),to.end());
 	ll ret=1;
 	do {
 		ret+=go(to);
 	} while(next_permutation(to.begin(),to.end()));
 	return ret;
 }
 
 void run(int casenr) {
 	REPE(i,MAXN) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j]; }
 	scanf("%s",s); n=strlen(s);
 	seen.clear();
 	ll ret=go(string(s));
 	printf("Case #%d: %lld\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
