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

struct point {double x,y,z;};

point P[8];
point Q[8];

double get_area(void){
	double s = 0.0, t = 0.0;
	int i;
	REP(i,8){
		double x = Q[i].x;
		if(i&1) s = max(s, x); else t = max(t, x);
	}
	return (s + t) / 2.0 * sqrt(8.0);
}

point rotate(point P, double theta){
	point Q = P;
	Q.x = P.x * cos(theta) - P.y * sin(theta);
	Q.y = P.x * sin(theta) + P.y * cos(theta);
	return Q;
}

void print(int p, int q){
	printf("%.18f %.18f %.18f\n", (Q[p].x + Q[q].x) / 2.0, (Q[p].y + Q[q].y) / 2.0, (Q[p].z + Q[q].z) / 2.0);
}

void main2(void){
	int i,j;
	
	double target;
	cin >> target;
	
	REP(i,4) P[i].x = P[i].z = 0.0;
	REP(i,4) P[i].y = 0.5;
	
	double tmp = sqrt(2.0) / 2.0;
	P[0].x = tmp;
	P[1].z = tmp;
	P[2].x = -tmp;
	P[3].z = -tmp;
	
	REP(i,4){
		P[4+i] = P[i];
		P[4+i].y = -0.5;
	}
	
	double low = 0.0;
	double high = atan(sqrt(2.0));
	
	REP(i,100){
		double mid = (low + high) / 2.0;
		REP(j,8) Q[j] = rotate(P[j], mid);
		double S = get_area();
		
		if(S < target){
			low = mid;
		} else {
			high = mid;
		}
	}
	
	print(0, 2);
	print(0, 5);
	print(0, 7);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d:\n", tc + 1);
		main2();
	}
	return 0;
}
