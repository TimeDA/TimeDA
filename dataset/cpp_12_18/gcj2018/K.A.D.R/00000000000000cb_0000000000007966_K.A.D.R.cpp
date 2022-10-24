#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#define GETS gets_s
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <stdio.h>
#define GETS gets
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k, kolt;
char str[102];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d%s", &d, str);
		m = (int)strlen(str);
		
		priority_queue<pii, vector<pii> > q;
		c = 0;
		ll cur = 0;
		rept(i, m) {
			if (str[i] == 'C') ++c;
			if (i && str[i] != str[i - 1] && str[i] == 'S') {
				q.push(mp(1LL << c, i));
			}
			if (str[i] == 'S') cur += 1LL << c;
		}

		int cnt = 0;
		while (!q.empty() && cur > d) {
			auto t = q.top();
			q.pop();
			++cnt;
			
			cur -= t.x / 2;
			swap(str[t.y], str[t.y - 1]);
			if (t.y - 1 > 0 && str[t.y - 2] == 'C') {
				t.x /= 2;
				--t.y;
				q.push(t);
				t.x *= 2;
				++t.y;
			}
			if (t.y + 1 < m && str[t.y + 1] == 'S') {
				++t.y;
				q.push(t);
				--t.y;
			}
		}

		printf("Case #%d: ", hod);
		if (cur > d) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", cnt);
		}
	}
}
