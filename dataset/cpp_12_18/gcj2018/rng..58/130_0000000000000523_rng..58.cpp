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
	int A,B,N;
	
	cin >> A >> B >> N;
	A++;
	
	while(1){
		int x = (A + B) / 2;
		cout << x << endl;
		string s;
		cin >> s;
		if(s == "CORRECT") return;
		if(s == "TOO_BIG") B = x - 1; else A = x + 1;
	}
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC) main2();
	return 0;
}
