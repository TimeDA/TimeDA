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

#define X 2000

int func(int x){ // the ratio of monsters who eat x
	int cnt = 0;
	int i;
	
	REP(i,X) printf("%d\n", x);
	fflush(stdout);
	
	REP(i,X){
		int c;
		scanf("%d", &c);
		cnt += c;
	}

	return cnt;
}

void main2(void){
	int i;
	
	int low = 0;
	int high = 1000000;
	
	while(high - low > 1){
		int mid = (low + high) / 2;
		if(func(mid) > 0){
			high = mid;
		} else {
			low = mid;
		}
	}
	
	int x = func(high);
	
	int ans = -1;
	for(int p=2;p<=25;p++){
		int L = X / p;
		int R = L + min(X % p, 2);
	//	cerr << p << ' ' << L << ' ' << R << endl;
		if(x >= L && x <= R) ans = p;
	}
	
	printf("%d\n", -ans);
	fflush(stdout);
}

int main(void){
	int T,S;
	cin >> T;
	int t;
	REP(t,T){
		cin >> S;
		main2();
	}
	return 0;
}
