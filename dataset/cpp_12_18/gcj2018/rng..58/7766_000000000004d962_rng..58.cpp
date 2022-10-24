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

#define _abs(x) ((x)>0?(x):-(x))

typedef long long ll;
#define eps 1.0E-50

vector <int> v[20010];
double dp[2][20010];

double essential(int C, vector <pair <int, int> > intervals){
	int x,big=0,i,j;
	
	REP(i,C+1) v[i].clear();
	REP(i,intervals.size()){
		int p = intervals[i].first;
		int q = intervals[i].second;
		if(p < q) v[p].push_back(q);
	}
	
	REP(i,C+1) dp[0][i] = 0.0;
	dp[0][0] = 1.0;
	
	REP(x,C){
		REP(i,v[x].size()){
			int y = v[x][i];
			REP(j,C+1) dp[1][j] = 0.0;
			REP(j,C+1) if(dp[0][j] > eps){
				dp[1][min(big,max(j,y))] += dp[0][j] / 2.0;
				dp[1][j] += dp[0][j] / 2.0;
			}
			swap(dp[0], dp[1]);
			big = max(big, y);
		}
		dp[0][x] = 0.0;
	}
	
	double ans = 0.0;
	REP(i,C+1) ans += dp[0][i];
	return ans;
}

ll gcd(ll x, ll y){
	return x ? gcd(y%x, x) : y;
}

struct angle{
	ll x,y;
};

bool operator<(const angle &A, const angle &B){
	// return (atan2(A.y, A.x) < atan2(B.y, B.x));
	if(A.y == 0 && B.y == 0 && A.x > B.x) return true;
	if((__int128)A.y * B.x < (__int128)A.x * B.y) return true;
	return false;
}

angle divide(ll x1, ll y1, ll x2, ll y2){
	y2 = -y2;
	angle A;
	A.x = x1 * x2 - y1 * y2;
	A.y = x1 * y2 + x2 * y1;
	ll g = gcd(_abs(A.x), _abs(A.y));
	A.x /= g;
	A.y /= g;
	return A;
}

vector <angle> froms,tos;

void pre(ll x, ll y, ll dx, ll dy){
	angle from = divide(0 - x, 1000 - y, dx, dy);
	angle to = divide(0 - x, 0 - y, dx, dy);
	froms.push_back(from);
	tos.push_back(to);
}

map <angle, int> mp;

void add_angle(angle A){
	if(A.y < 0) A.y = -A.y;
	mp[A] = 0;
}

int get_angle(int C, angle A){
	if(A.y < 0){
		A.y = -A.y;
		return 2 * C - mp[A];
	} else {
		return mp[A];
	}
}

double main3(void){
	int N = froms.size();
	int i;
	
	mp.clear();
	angle P = {1, 0};
	add_angle(P);
	angle Q = {-1, 0};
	add_angle(Q);
	
	REP(i,N){
		add_angle(froms[i]);
		add_angle(tos[i]);
	}
	
	int C = 0;
	snuke(mp,itr){
		(itr->second) = C;
		C++;
	}
	C--;
	
	int up_filled = 0;
	int down_filled = 0;
	vector <pair <int, int> > intervals;
	
	REP(i,N){
		int from = get_angle(C, froms[i]);
		int to = get_angle(C, tos[i]);
		
		if(from > to){
			int a = 2 * C - from;
			int b = to;
			if(a > b) swap(a, b);
			up_filled = max(up_filled, a);
			intervals.push_back(make_pair(a, b));
		} else if(to <= C){
			intervals.push_back(make_pair(from, to));
		} else if(from >= C){
			intervals.push_back(make_pair(2 * C - to, 2 * C - from));
		} else {
			int a = C - from;
			int b = to - C;
			if(a > b) swap(a, b);
			down_filled = max(down_filled, a);
			intervals.push_back(make_pair(C - b, C - a));
		}
	}
	
	if(up_filled + down_filled >= C) return 1.0;
	
	vector <pair <int, int> > intervals2;
	
	REP(i,intervals.size()){
		int p = intervals[i].first;
		int q = intervals[i].second;
		p = max(p - up_filled, 0);
		q = min(q - up_filled, C - up_filled - down_filled);
		intervals2.push_back(make_pair(p, q));
	}
	
	return essential(C - up_filled - down_filled, intervals2);
}

void main2(void){
	int n,i;
	
	cin >> n;
	
	froms.clear();
	tos.clear();
	
	REP(i,n){
		int xa,ya,xb,yb;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		if(xa < 0){
			xa = -xa;
			xb = -xb;
		}
		if(xa > 0) pre(xa, ya, xb - xa, yb - ya);
	}
	
	double ans = main3();
	printf("%.9f\n", 1.0 - ans);
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
