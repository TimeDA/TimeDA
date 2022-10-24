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

priority_queue <ll> q;

void main2(void){
	int i;
	ll D;
	string s;
	
	cin >> D >> s;
	
	while(!q.empty()) q.pop();
	
	ll two = 1;
	ll sum = 0;
	
	REP(i,s.length()){
		if(s[i] == 'S'){
			q.push(two);
			sum += two;
		} else {
			two *= 2;
		}
	}
	
	int ans = 0;
	
	while(1){
		if(sum <= D){
			cout << ans << endl;
			return;
		} else {
			ans++;
			ll x = q.top();
			q.pop();
			if(x == 1){
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			q.push(x/2);
			sum -= x/2;
		}
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
