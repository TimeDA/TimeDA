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

const int MAXR=500;
const int MAXB=500;

vector<int> dp[MAXR+1][MAXR+1];

void run(int casenr) {
	int r,b; scanf("%d%d",&r,&b);
	int idx=min(b,SZ(dp[r][0])-1);
	printf("Case #%d: %d\n",casenr,dp[r][0][idx]);
}

void precalc() {
	REPE(nred,MAXR) for(int mnred=nred;mnred>=0;--mnred) {
		int blim;
		if(mnred==0) {
			blim=MAXB;
		} else {
			int mxans=nred/mnred;
			int bneed=(1+mxans)*mxans/2;
			blim=min(MAXB,bneed);
		}
		dp[nred][mnred]=vector<int>(blim+1,0);
		REPE(nblue,blim) {
			for(int i=0;;++i) {
				int needblue=mnred==0?i*(i+1)/2:i*(i-1)/2,needred=i*mnred;
				if(needblue>nblue||needred>nred) break;
				int cur=i;
				if(mnred+1<=nred-needred) {
					vector<int> &ndp=dp[nred-needred][mnred+1];
					int idx=min(SZ(ndp)-1,nblue-needblue);
					cur+=ndp[idx];
				}
				dp[nred][mnred][nblue]=max(dp[nred][mnred][nblue],cur);
			}
		}
		//printf("nred=%d mnred=%d:",nred,mnred); REPSZ(nblue,dp[nred][mnred]) printf(" %d",dp[nred][mnred][nblue]); puts("");
	}
}


int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
