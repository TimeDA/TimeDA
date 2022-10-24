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
 void precalc();
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
 	cout.sync_with_stdio(0);
 	int t = 1;
 	//precalc();
 	//cout << "done!\n";
 	//freopen("in.txt", "r", stdin);
 	cin >> t;
 	//gen();
 	while (t--)
 		solve();
 	/*
 #ifdef room210
 	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
 #endif*/
 	return 0;
 }
 
 #define int li
 
 int n;
 int m;
 int start[100500], finish[100500], num[100500], num1[100500];
 int sum (int l) {
 	//cout << endl << n << ' ' << l << ' ' << n * (n + 1) / 2 - (n - l + 1) * (n - l + 2) / 2 << endl;
 	return l * (l - 1) / 2;
 }
 
 bool cmp1 (int q, int w) {
 	return finish[q] < finish[w] || finish[q] == finish[w] && start[q] < start[w];
 }
 
 bool cmp2 (int q, int w) {
 	return start[q] < start[w] || start[q] == start[w] && finish[q] < finish[w];
 }
 
 void solve() {
 	++timer;
 	cout << "Case #" << timer << ": ";
 	map <int, int> mapa;
 	mapa.clear();
 	vector <pair<int, pair<int, int> > > vec;
 	cin >> n >> m;
 	int loss = 0;
 	for (int i = 0; i < m; ++i) {
 		cin >> start[i] >> finish[i] >> num[i];
 		num1[i] = num[i];
 		int len = finish[i] - start[i];
 		loss += num[i] * sum(len);
 		vec.push_back(mp(start[i], mp(0, num[i])));
 		vec.push_back(mp(finish[i], mp(1, num[i])));
 	}
 	sort(all(vec));
 	vector <pair<int, int> > have;
 	for (int i = 0; i < vec.size(); ++i) {
 		if (vec[i].second.first == 0) {
 			have.push_back(mp(vec[i].first, vec[i].second.second));
 		}
 		else {
 			while (vec[i].second.second > 0) {
 				int got = min(have.back().second, vec[i].second.second);
 				//cout << vec[i].first << ' ' << have.back().first << ' ' << vec[i].second.second << ' ' << got << endl;
 				loss -= got * sum(vec[i].first - have.back().first);
 				vec[i].second.second -= got;
 				have.back().second -= got;
 				if (have.back().second == 0)
 					have.pop_back();
 			}
 		}
 	}
 	cout << -loss << "\n";
 }