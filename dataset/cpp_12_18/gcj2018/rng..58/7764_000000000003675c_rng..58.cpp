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

typedef long long ll;
#define INF (1ll<<40)

int N;
int g[110][2];
ll input[110];

ll want[110];
ll have[110];

bool used[110];
vector <int> topo;

bool check(ll X){
	int i,j;
	
	REP(i,N) have[i] = input[i];
	REP(i,N) want[i] = 0;
	want[0] = X;
	
	while(1){
		REP(i,N) if(want[i] > 0 && have[i] > 0){
			ll d = min(want[i], have[i]);
			want[i] -= d;
			have[i] -= d;
		}
		
		REP(i,N) used[i] = false;
		topo.clear();
		
		while(1){
			REP(i,N) if(!used[i]) if(have[i] > 0 || (used[g[i][0]] && used[g[i][1]])) break;
			if(i == N) break;
			used[i] = true;
			topo.push_back(i);
		}
		
		REP(i,N) if(want[i] > 0 && !used[i]) return false;
		
		int sz = topo.size();
		reverse(topo.begin(),topo.end());
		
		REP(i,sz){
			int x = topo[i];
			ll d = min(want[x], have[x]);
			want[x] -= d;
			have[x] -= d;
			
			d = want[x];
			want[x] = 0;
			
			want[g[x][0]] = min(want[g[x][0]] + d, INF);
			want[g[x][1]] = min(want[g[x][1]] + d, INF);
		}
		
		bool finished = true;
		REP(i,N) if(want[i] > 0) finished = false;
		if(finished) return true;
	}
	
	return true;
}
	
void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) REP(j,2){
		cin >> g[i][j];
		g[i][j]--;
	}
	REP(i,N) cin >> input[i];
	
	ll low = 0, high = INF;
	while(high - low > 1){
		ll mid = (low + high) / 2;
		if(check(mid)) low = mid; else high = mid;
	}
	
	cout << low << endl;
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
