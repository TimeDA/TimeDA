#include <stdio.h>
 #include <iostream>
 #include <string>
 #include <sstream>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <deque>
 #include <cmath>
 #include <ctime>
 #include <stack>
 #include <set>
 #include <map>
 #include <cassert>
 #include <memory.h>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 #define all(a) a.begin(), a.end()
 
 typedef long long li;
 typedef long double ld;
 typedef vector<int> vi;
 typedef pair <int, int> pi;
 
 void solve();
 //void precalc();
 int timer = 0;
 #define FILENAME "change me please"
 int main(){
 	string s = FILENAME;
 #ifdef room210
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	//cout<<FILENAME<<endl;
 	//assert (s != "change me please");
 	clock_t start = clock();
 #else
 	//freopen(FILENAME ".in", "r", stdin);
 	//freopen(FILENAME".out", "w", stdout);
 #endif
 	//cout.sync_with_stdio(0);
 	int t = 1;
 	//precalc();
 	//cout << "done!\n";
 	cin >> t;
 	//gen();
 	while (t--)
 		++timer, solve();
 	/*
 #ifdef room210
 	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
 #endif*/
 	return 0;
 }
 
 //#define int li
 
 int n;
 int type[1000];
 vector<int> keys[1000];
 
 int can[1 << 20];
 
 int nums[1000];
 
 int done;
 
 vector<int> ans;
 
 bool doing () {
 	if (can[done] != 0) {
 		if (can[done] == 1)
 			return false;
 		if (can[done] == 2)
 			return true;
 	}
 	if (done + 1 == (1 << n)) {
 		can[done] = 2;
 		return true;
 	}
 	bool found = false;
 	for (int i = 0; i < n; ++i)
 		if (!(done & (1 << i))) {
 			int now = type[i];
 			if (nums[now] == 0)
 				continue;
 			--nums[now];
 			for (int j = 0; j < keys[i].size(); ++j)
 				nums[keys[i][j]]++;
 			done |= (1 << i);
 			if (doing()) {
 				ans.push_back(i + 1);
 				found = true;
 			}
 			++nums[now];
 			for (int j = 0; j < keys[i].size(); ++j)
 				nums[keys[i][j]]--;
 			done ^= (1 << i);
 			if (found) {
 				can[done] = 2;
 				return true;
 			}
 		}
 		can[done] = 1;
 		return false;
 }
 
 void solve () {
 	int k;
 	cin >> k >> n;
 
 	ans.clear();
 	for (int i = 0; i < 1000; ++i)
 		keys[i].clear();
 	memset(nums, 0, sizeof nums);
 	memset(can, 0, sizeof can);
 
 	vector<int> have(k);
 	for (int i = 0; i < k; ++i)
 		cin >> have[i], nums[have[i]]++;
 	for (int i = 0; i < n; ++i) {
 		cin >> type[i];
 		int cur; cin >> cur;
 		for (int j = 0; j < cur; ++j) {
 			int now; cin >> now;
 			keys[i].push_back(now);
 		}
 	}
 
 	done = 0;
 
 	cout << "Case #" << timer << ": ";
 
 	if (!doing()) {
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 
 	for (int i = ans.size() - 1; i >= 0; --i)
 		cout << ans[i] << ' ';
 
 	printf("\n");
 
 }
