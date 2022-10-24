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
 
 set<pair<int, char>> s1;
 set<pair<int, int>> s;
 int n, r, o, y, g, b, v;
 map<char, int> cnt;
 map<int, char> mapping;
 string solve() {
 	if (r > y + b) {
 		return "IMPOSSIBLE";
 	}
 	if (y > r + b) {
 		return "IMPOSSIBLE";
 	}
 	if (b > y + r) {
 		return "IMPOSSIBLE";
 	}
 	s.clear();
 	cnt.clear();
 	s1.clear();
 	mapping.clear();
 	s1.insert(mp(-r, 'R'));
 	s1.insert(mp(-y, 'Y'));
 	s1.insert(mp(-b, 'B'));
 	int idx = 0;
 	for (auto it : s1) {
 		mapping[idx] = it.second;
 		s.insert(mp(it.first, idx));
 		cnt[idx] = -it.first;
 		idx++;
 	}
 	int last = 4;
 	string res;
 	FOR(i, 0, n) {
 		for (auto it : s)
 		{
 			if (it.second != last) {
 				res += mapping[it.second];
 				last = it.second;
 				break;
 			}
 		}
 		s.erase(mp(-cnt[last], last));
 		cnt[last]--;
 		s.insert(mp(-cnt[last], last));
 	}
 	return res;
 }
 
 string res;
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	double beg = clock();
 	freopen("out.txt", "w", stdout);
 #endif
 	
 	int tests;
 	scanf("%d", &tests);
 	FOR(testNumber, 1, tests + 1) {
 		cin >> n >> r >> o >> y >> g >> b >> v;
 		res = solve();
 		printf("Case #%d: %s\n", testNumber, res.c_str());
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }