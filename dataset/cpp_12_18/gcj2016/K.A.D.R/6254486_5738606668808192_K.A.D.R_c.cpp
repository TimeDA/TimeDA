#ifdef _MSC_VER
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:66777216")
 #else
 #pragma GCC optimize("O3")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
 #include <fstream>
 #include <ctime>
 #include <cstring>
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
 
 inline ll conv(const string& s, int base) {
 	ll ans = 0;
 	rept(i, L(s)) {
 		ans = ans * base + s[i] - '0';
 	}
 	return ans;
 }
 inline ll fnd(ll t) {
 	for (int i = 2; (ll)i * i <= t; ++i) {
 		if (t % i == 0) return i;
 	}
 	return 1;
 }
 ll cand[12];
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	const int n = 16;
 	const int mx = 50;
 	
 	int found = 0;
 	printf("Case #1:\n");
 	set<string> was;
 	while (found < mx) {
 		string s = "";
 		rept(i, n) {
 			if (i == 0 || i == n - 1) {
 				s += '1';
 			}
 			else {
 				s += (char)(rand() % 2 + '0');
 			}
 		}
 		if (was.count(s)) continue;
 		bool ok = 1;
 		FOR(base, 2, 10) {
 			ll t = conv(s, base);
 			ll p = fnd(t);
 			if (p == 1) {
 				ok = 0;
 				break;
 			}
 			cand[base] = p;
 		}
 		if (!ok) continue;
 		printf("%s", s.c_str());
 		FOR(i, 2, 10) {
 			printf(" %I64d", cand[i]);
 		}
 		printf("\n");
 		fflush(stdout);
 		++found;
 		cerr << "FOUND " << found << endl;
 		was.insert(s);
 	}
 }
