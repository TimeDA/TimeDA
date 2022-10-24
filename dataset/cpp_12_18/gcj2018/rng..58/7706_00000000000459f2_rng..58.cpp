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

int N;
int s[110],t[110];
	
void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) s[i] = i;
	
	int pos = 0;
	REP(i,N){
		int x;
		scanf("%d", &x);
		REP(j,x){
			t[pos] = i;
			pos++;
		}
	}
	
	if(t[0] != 0 || t[N-1] != N-1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	int d = 0;
	REP(i,N) d = max(d, abs(s[i] - t[i]));
	cout << d + 1 << endl;
	
	while(1){
		string ans;
		bool finished = true;
		REP(i,N) if(s[i] != t[i]) finished = false;
		
		if(finished){
			REP(i,N) ans += '.';
			printf("%s\n", ans.c_str());
			return;
		}
		
		REP(i,N) ans += '.';
		
		REP(i,N) if(s[i] < t[i]){
			ans[s[i]] = '\\';
			s[i]++;
		} else if(s[i] > t[i]){
			ans[s[i]] = '/';
			s[i]--;
		}
		
		printf("%s\n", ans.c_str());
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
