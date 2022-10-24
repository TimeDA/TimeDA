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

int freq[30];

int query(int N){
	int i;
	int x = 0;
	REP(i,N) if(freq[i] > freq[x]) x = i;
	freq[x]--;
	return x;
}

void main2(void){
	int N,i;
	
	cin >> N;
	REP(i,N) cin >> freq[i];
	
	int S = 0;
	REP(i,N) S += freq[i];
	
	while(S > 0){
		cout << ' ';
		int p = query(N);
		S--;
		cout << (char)('A' + p);
		if(S % 2 == 1){
			int q = query(N);
			S--;
			cout << (char)('A' + q);
		}
	}
	
	cout << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d:", tc + 1);
		main2();
	}
	return 0;
}
