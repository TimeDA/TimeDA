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

struct point {double x,y;};
	
int N,K;
point P[310],Q[310];
int f[310];

point rotate(point R){
	point ans = {R.x * cos(1.0) - R.y * sin(1.0), R.x * sin(1.0) + R.y * cos(1.0)};
	return ans;
}
	
void main2(void){
	int i;
	
	cin >> N >> K;
	
	REP(i,N) cin >> P[i].x >> P[i].y >> Q[i].x >> Q[i].y;
	
	while(1){
		REP(i,N){
			P[i] = rotate(P[i]);
			Q[i] = rotate(Q[i]);
		}
		
		int sgn = rand() % 2;
		
		vector <pair <pair <int, double>, int> > v;
	
		REP(i,N){
			if(P[i].x > Q[i].x) swap(P[i], Q[i]);
			
			double minx = P[i].x;
			double angle = atan2(Q[i].y - P[i].y, Q[i].x - P[i].x);
			if(sgn) angle = -angle;
			
			v.push_back(make_pair(make_pair(minx, angle), i));
			
		//	cout << i << ' ' << minx << ' ' << angle << endl;
		}
	
		sort(v.begin(),v.end());
		REP(i,N) f[i] = v[i].second;
		
		bool failed = false;
	
		if(K == 2){
			REP(i,N) if(f[i] < 2) break;
			if(f[i] == 1) failed = true;
		}
		
		if(!failed) break;
	}
	
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
