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
#include <cstring>
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

char buff[100];

int query(int x) {
	printf("%d\n",x); fflush(stdout);
	scanf("%s",buff); if(strcmp(buff,"TOO_SMALL")==0) return -1; if(strcmp(buff,"TOO_BIG")==0) return +1; if(strcmp(buff,"WRONG_ANSWER")==0) exit(0); if(strcmp(buff,"CORRECT")==0) return 0; assert(false); return -1;
}

void run(int casenr) {
	int a,b,n; scanf("%d%d%d",&a,&b,&n);
	int l=a+1,r=b; // [l,r]
	while(true) {
		int m=l+(r-l)/2;
		int cur=query(m);
		if(cur<0) l=m+1; else if(cur>0) r=m-1; else return;
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
