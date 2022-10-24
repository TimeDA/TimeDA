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
#define INF (1ll<<60)

ll pop[(1<<15)];

int K;
ll cnt[(1<<15)];

ll get_max(void){
	ll big = 0, small = INF;
	int mask;
	
	ll total = 0;
	REP(mask,(1<<K)) total += cnt[mask];
	
	REP(mask,(1<<K)){
		ll sum = 0;
		int mask2 = mask;
		while(mask2 > 0){
			sum += cnt[mask2];
			mask2 = ((mask2 - 1) & mask);
		}
		
		ll c = pop[mask];
		if(c > 0) big = max(big, (sum + c - 1) / c);
		
		if(c < K) small = min(small, (total - sum) / (K - c));
	}
	
	return big - small;
}

/*
ll pre[(1<<15)];

ll get_min(void){
	ll ans = INF;
	int mask;
	
	REP(mask,(1<<K)) pre[mask] = 0;
	
	REP(mask,(1<<K)) if(mask > 0){
		int mask2 = mask;
		while(mask2 > 0){
			pre[mask2] += cnt[mask];
			mask2 = ((mask2 - 1) & mask);
		}
	}
	
	REP(mask,(1<<K)) if(mask > 0) ans = min(ans, pre[mask] / pop[mask]);
	
	REP(mask,(1<<K)) cout << 'a' << ' ' << mask << ' ' << pre[mask] << endl;
	
	return ans;
}
*/

ll X,Y;
ll px[20],py[20],pd[20];

void main2(void){
	int i,j,k;
	
	cin >> X >> Y >> K;
	REP(i,K){
		cin >> px[i] >> py[i] >> pd[i];
		px[i]--;
		py[i]--;
	}
	
	vector <ll> vx,vy;
	
	vx.push_back(0);
	vx.push_back(X);
	vy.push_back(0);
	vy.push_back(Y);
	
	REP(i,K){
		vx.push_back(px[i]);
		vx.push_back(px[i] + 1);
		vx.push_back(px[i] - pd[i]);
		vx.push_back(px[i] + 1 + pd[i]);
		vy.push_back(py[i]);
		vy.push_back(py[i] + 1);
		vy.push_back(py[i] - pd[i]);
		vy.push_back(py[i] + 1 + pd[i]);
	}
	
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	
	REP(i,(1<<K)) cnt[i] = 0;
	
	REP(i,vx.size()-1){
		ll x = vx[i];
		ll dx = vx[i+1] - vx[i];
		REP(j,vy.size()-1){
			ll y = vy[j];
			ll dy = vy[j+1] - vy[j];
			if(dx * dy > 0 && x >= 0 && x < X && y >= 0 && y < Y){
				int mask = 0;
				REP(k,K){
					if(px[k] == x && py[k] == y) goto failed;
					if(x >= px[k] - pd[k] && x < px[k] + pd[k] + 1 && y >= py[k] - pd[k] && y < py[k] + pd[k] + 1){
						mask |= (1<<k);
					}
				}
				if(mask != 0) cnt[mask] += dx * dy;
				failed:;
			}
		}
	}
	
//	REP(i,(1<<K)) if(cnt[i] > 0) cout << i << ' ' << cnt[i] << endl;
//	cout << get_max() << ' ' << get_min() << endl;
	
//	ll ans = get_max() - get_min();
	ll ans = get_max();
	cout << ans << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int i;
	REP(i,(1<<15)) pop[i] = __builtin_popcount(i);
	
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
