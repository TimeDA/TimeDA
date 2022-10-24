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

void main2(void){
	int A,i;
	
	cin >> A;
	
	int x = 10;
	int y = 10;
	
	while(1){
		set <pair <int, int> > s;
		
		while(s.size() < 9){
			printf("%d %d\n", x, y);
			fflush(stdout);
			int p,q;
			scanf("%d%d", &p, &q);
			if(p == 0 && q == 0) return;
			s.insert(make_pair(p, q));
		}
		
		x += 3;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC) main2();
	return 0;
}
