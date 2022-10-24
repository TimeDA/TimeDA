#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

LL recalc(const string &s) {
	LL res = 0;
	LL d = 1;
	FOR(i,0,s.size()) {
		if (s[i] == 'C') {
			d *= 2;
		} else {
			res += d;
		}
	}
	return res;
}

int main()
{
	int tests;
	cin >> tests;
	FOR(testNumber, 1, tests + 1) {
		LL d;
		string s;
		cin >> d >> s;
		bool ok = false;
		int res = 0;
		while (1) {
			LL val = recalc(s);
			if (val <= d) {
				ok = true;
				break;
			}
			res++;
			bool changed = false;
			for (int i = (int)s.size() - 1; i > 0; --i) {
				if ((s[i] == 'S') && (s[i - 1] == 'C')) {
					swap(s[i-1],s[i]);
					changed = true;
					break;
				}
			}
			if (!changed) {
				break;
			}
		}
		printf("Case #%d: ", testNumber);
		if (ok) {
			cout<<res<<endl;
		} else {
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}