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

int need;
bool have[3][3];
int nq;

pair<int,int> query(int x,int y) {
	++nq; printf("%d %d\n",x,y); fflush(stdout);
	pair<int,int> ret; scanf("%d%d",&ret.first,&ret.second); return ret;
}

void run(int casenr) {
	scanf("%d",&need);
	int cnt=(need+8)/9;
	nq=0;
	REP(i,cnt) {
		REP(x,3) REP(y,3) have[x][y]=false;
		int ox=1,oy=1+3*i;
		int rem=9;
		while(rem>0) {
			pair<int,int> cur=query(ox+1,oy+1);
			if(cur.first==-1&&cur.second==-1) exit(0);
			if(cur.first==0&&cur.second==0) {
				//fprintf(stderr,"nq=%d\n",nq);
				return;
			}
			int x=cur.first-ox,y=cur.second-oy;
			if(!have[x][y]) have[x][y]=true,--rem;
		}
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
