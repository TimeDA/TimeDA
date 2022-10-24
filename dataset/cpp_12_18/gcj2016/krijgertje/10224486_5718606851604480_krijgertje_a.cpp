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
 
 const int MAXN=12;
 const int MAXX=1<<MAXN;
 
 int mem[MAXN][MAXX+1][MAXX+1];
 bool ok(int n,int r,int p,int s) {
 	if(n==0) return true;
 	int &ret=mem[n][r][p];
 	if(ret==-1) {
 		ret=0; int RW=-1,PW=-1,SW=-1;
 		REPE(rw,r) {
 			int pw=r-rw,sw=p-pw;
 			if(rw<0||pw<0||sw<0||rw+pw!=r||pw+sw!=p||sw+rw!=s) continue;
 			if(ok(n-1,rw,pw,sw)) { ret=1; RW=rw,PW=pw,SW=sw; break; }
 		}
 		//printf("%d %d %d %d = %d (%d,%d,%d)\n",n,r,p,s,ret,RW,PW,SW);
 	}
 	return ret==1;
 }
 bool can(int n,int RW,int PW,int SW,int r,int p,int s) {
 	REPE(rw,r) {
 		int pw=r-rw,sw=p-pw;
 		if(rw<0||pw<0||sw<0||rw+pw!=r||pw+sw!=p||sw+rw!=s) continue;
 		if(ok(n-1,RW+rw,PW+pw,SW+sw)) return true;
 	}
 	return false;
 }
 
 int n,r,p,s;
 char ret[MAXX+1];
 
 void run(int casenr) {
 	scanf("%d%d%d%d",&n,&r,&p,&s);
 	if(!ok(n,r,p,s)) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
 
 	int rw=0,pw=0,sw=0; ret[1<<n]='\0';
 	for(int i=0;i<(1<<n);i+=2) {
 		// PR,PS,RS
 		if(p>0&&r>0&&can(n,rw,pw+1,sw,r-1,p-1,s)) { ret[i]='P'; ret[i+1]='R'; --p,--r,++pw; continue; }
 		if(p>0&&s>0&&can(n,rw,pw,sw+1,r,p-1,s-1)) { ret[i]='P'; ret[i+1]='S'; --p,--s,++sw; continue; }
 		if(r>0&&s>0&&can(n,rw+1,pw,sw,r-1,p,s-1)) { ret[i]='R'; ret[i+1]='S'; --r,--s,++rw; continue; }
 		assert(false);
 	}
 	printf("Case #%d: %s\n",casenr,ret);
 }
 
 int main() {
 	memset(mem,-1,sizeof(mem));
 	int n; scanf("%d",&n); FORE(i,1,n) run(i);
 	return 0;
 }
