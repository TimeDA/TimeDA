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

int main()
{
	int tests;
	cin >> tests;
	FOR(testNumber, 1, tests + 1) {
		vector<int> a, b;
		int n;
		scanf("%d", &n);
		FOR(i,0,n) {
			int v;
			scanf("%d", &v);
			if (i&1) {
				b.push_back(v);
			} else {
				a.push_back(v);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> c;
		FOR(i,0,a.size()) {
			c.push_back(a[i]);
			if (i < b.size()) {
				c.push_back(b[i]);
			}
		}
		int res = -1;
		FOR(i,0,c.size() - 1) {
			if (c[i] > c[i + 1]) {
				res = i;
				break;
			}
		}
		printf("Case #%d: ", testNumber);
		if (res == -1) {
			cout<<"OK"<<endl;
		} else {
			cout<<res<<endl;
		}
	}
	return 0;
}