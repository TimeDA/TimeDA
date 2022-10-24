#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)
	
int N;
int d[100010],a[100010],b[100010];
int x[100010][2];
int maxlen[100010];

void dfs(int L, int R){
	if(R - L <= 1){
		maxlen[L] = max(maxlen[L], R - L + 1);
		return;
	}
	
	int M = (L + R) / 2;
	dfs(L, M-1);
	dfs(M+1, R);
	
	int p,dir;
	
	REP(p,2) REP(dir,2){
		int l = M;
		int r = M;
		
		int zero = INF;
		int one = INF;
		
		if(p == 0) zero = x[M][0]; else one = x[M][1];
		
		while(l > L && (x[l-1][0] == zero || x[l-1][1] == one)) l--;
		while(r < R && (x[r+1][0] == zero || x[r+1][1] == one)) r++;
		
		if(dir == 0){
			if(l > L){
				if(p == 0) one = x[l-1][1]; else zero = x[l-1][0];
			}
		} else {
			if(r < R){
				if(p == 0) one = x[r+1][1]; else zero = x[r+1][0];
			}
		}
		
		while(l > L && (x[l-1][0] == zero || x[l-1][1] == one)) l--;
		while(r < R && (x[r+1][0] == zero || x[r+1][1] == one)) r++;
		
		maxlen[l] = max(maxlen[l], r - l + 1);
	}
}
	
void main2(void){
	int i;
	
	cin >> N;
	REP(i,N) scanf("%d%d%d", &d[i], &a[i], &b[i]);
	
	REP(i,N){
		x[i][0] = d[i] + a[i];
		x[i][1] = d[i] - b[i];
	}
	
	REP(i,N) maxlen[i] = 0;
	
	dfs(0, N-1);
	
	int best = 0, cnt = 0;
	REP(i,N) best = max(best, maxlen[i]);
	REP(i,N) if(maxlen[i] == best) cnt++;
	
	cout << best << ' ' << cnt << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
