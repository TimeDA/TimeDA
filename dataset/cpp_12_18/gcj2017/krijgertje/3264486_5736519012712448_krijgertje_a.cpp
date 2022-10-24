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
 
 const int MAXLEN=1000;
 
 char s[MAXLEN+1]; int slen;
 int sz;
 int d[MAXLEN+1];
 
 void run(int casenr) {
 	scanf("%s%d",s,&sz); slen=strlen(s);
 	memset(d,0,sizeof(d));
 	int cur=0,ret=0;
 	REP(i,slen) {
 		cur+=d[i];
 		if(cur%2==1) s[i]=s[i]=='+'?'-':'+';
 		if(s[i]=='-'&&i+sz<=slen) ++cur,++ret,--d[i+sz],s[i]='+';
 	}
 	REP(i,slen) if(s[i]=='-') { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 	printf("Case #%d: %d\n",casenr,ret);
 }
 
 int main() {
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
