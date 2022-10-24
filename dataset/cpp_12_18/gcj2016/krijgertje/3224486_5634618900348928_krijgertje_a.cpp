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
 
 const int MAXLEN=20000;
 
 char s[MAXLEN+1]; int n;
 
 void run(int casenr) {
 	scanf("%s",s); n=strlen(s);
 	int ret=0,cnt=0; char lst='?';
 	REP(i,n) {
 		if(s[i]==lst) { ret+=10; --cnt; lst=cnt==0?'?':lst=='C'?'J':'C'; continue; }
 		++cnt; lst=s[i];
 	}
 	printf("Case #%d: %d\n",casenr,ret+5*(cnt/2));
 }
 
 int main() {
 
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
