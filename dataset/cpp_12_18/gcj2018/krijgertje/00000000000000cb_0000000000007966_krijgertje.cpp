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

const int MAXN=30;
const int MAXSWAP=MAXN*(MAXN-1)/2;


int maxdamage;
char s[MAXN+1]; int n;

int dp[MAXN+1][MAXN+1][MAXSWAP+1]; // dp[i][j][k] is minimum amount of damage when first i+j commands are i charges and j shots using k swaps

int chargecost[MAXN+1][MAXN+1];
int shotcost[MAXN+1][MAXN+1];

int chargepos[MAXN+1]; int ncharges;
int shotpos[MAXN+1]; int nshots;



void run(int casenr) {
	scanf("%d%s",&maxdamage,s); n=strlen(s);

	int maxswap=n*(n-1)/2;
	ncharges=0,nshots=0; REP(i,n) if(s[i]=='C') chargepos[ncharges++]=i; else if(s[i]=='S') shotpos[nshots++]=i;
	REPE(i,ncharges) REPE(j,nshots) {
		chargecost[i][j]=shotcost[i][j]=INT_MAX;
		if(i<ncharges) chargecost[i][j]=max(0,chargepos[i]-(i+j));
		if(j<nshots) shotcost[i][j]=max(0,shotpos[j]-(i+j));
		//printf("%d %d: %d %d\n",i,j,chargecost[i][j],shotcost[i][j]);
	}

	REPE(i,n) REPE(j,n) REPE(k,maxswap) dp[i][j][k]=INT_MAX; dp[0][0][0]=0;
	REPE(i,ncharges) REPE(j,nshots) REPE(k,maxswap) if(dp[i][j][k]!=INT_MAX) {
		//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
		if(i<ncharges) { // charge
			int ni=i+1,nj=j,nk=k+chargecost[i][j];
			dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]);
		}
		if(j<nshots) {
			int ni=i,nj=j+1,nk=k+shotcost[i][j];
			dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]+(1<<i));
		}
	}
	
	REPE(k,maxswap) if(dp[ncharges][nshots][k]<=maxdamage) { printf("Case #%d: %d\n",casenr,k); return; }
	printf("Case #%d: IMPOSSIBLE\n",casenr);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
