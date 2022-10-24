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

struct point {ll x,y,z;};

#define d_INF 1.0E+7

ll volume(point O, point P, point Q, point R){
	ll A = P.x - O.x, B = P.y - O.y, C = P.z - O.z;
	ll D = Q.x - O.x, E = Q.y - O.y, F = Q.z - O.z;
	ll G = R.x - O.x, H = R.y - O.y, I = R.z - O.z;
	
//	return A*E*I - A*F*H - B*D*I - C*E*G + B*F*G + C*D*H;
	
	double tmp = (double)A*E*I - (double)A*F*H - (double)B*D*I - (double)C*E*G + (double)B*F*G + (double)C*D*H;
	if(tmp > d_INF) return 1;
	if(tmp < -d_INF) return -1;
	
	ll MOD = (1ll<<40);
	ll ans = ((A*E*I)%MOD) - ((A*F*H)%MOD) - ((B*D*I)%MOD) - ((C*E*G)%MOD) + ((B*F*G)%MOD) + ((C*D*H)%MOD);
	ans = (ans % MOD + MOD) % MOD;
	
	if(ans < MOD / 2) return 1;
	return -1;
}

bool is_S_above(point P, point Q, point R, point S){
	point S0 = P;
	S0.z = 0;
	
	ll V1 = volume(P, Q, R, S0);
	ll V2 = volume(P, Q, R, S);
	
	return ((V1 > 0) != (V2 > 0));
}
	
int N;
point P[1010];
bool exist[1010];
int f[1010];
	
void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) scanf("%lld%lld%lld", &P[i].x, &P[i].y, &P[i].z);

/*	N = 1000;
	REP(i,N) P[i].x = rand() % 100000;
	REP(i,N) P[i].y = rand() % 100;
	REP(i,N) P[i].z = rand() % 100 + 1;
*/	
	
	int cnt = 0;
	REP(i,N) exist[i] = true;
	
	int s = 0;
	REP(i,N) if(P[i].z > P[s].z) s = i;
	
	int t;
	
	REP(t,N) if(t != s){
		int u = -1;
		REP(i,N) if(i != s && i != t) if(u == -1 || is_S_above(P[s], P[t], P[u], P[i])) u = i;
		
		bool good = true;
		REP(i,N) if(i != s && i != t && i != u && is_S_above(P[s], P[t], P[u], P[i])) good = false;
		
		if(good){
			f[0] = s;
			f[1] = t;
			cnt = 2;
			exist[s] = exist[t] = false;
			break;
		}
	}
	
	while(cnt < N){
		s = f[cnt-2];
		t = f[cnt-1];
		
		int u = -1;
		REP(i,N) if(exist[i] && (u == -1 || is_S_above(P[s], P[t], P[u], P[i]))) u = i;
		
		f[cnt] = u;
		cnt++;
		exist[u] = false;
	}
	
	reverse(f, f + N);
	
	REP(i,N){
		printf("%d", f[i] + 1);
		if(i == N-1) printf("\n"); else printf(" ");
	}
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
