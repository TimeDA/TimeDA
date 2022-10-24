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
 int n, m;
 int a[111][111];
 
 int getMinStolb(int j, int except) {
 	int res = 101;
 	for (int i = 0; i < n; ++i)
 		if (i != except)
 			res = min(res, a[i][j]);
 	return res;
 }
 
 int getMinStr(int j, int except) {
 	int res = 101;
 	for (int i = 0; i < m; ++i)
 		if (i != except)
 			res = min(res, a[j][i]);
 	return res;
 }
 
 
 void solve () {
 	cout << "Case #" << timer << ": ";
 	cin >> n >> m;
 	for (int i = 0; i < n; ++i)
 		for (int j = 0; j < m; ++j)
 			cin >> a[i][j];
 	
 	for (int i = 0; i < n; ++i)
 		for (int j = 0; j < m; ++j)
 			if (a[i][j] == 1) {
 				bool f = true;
 				for (int w = 0; w < m; ++w)
 					if (a[i][w] != 1) {
 						f = false;
 						break;
 					}
 				if (f)
 					continue;
 				f = true;
 				for (int w = 0; w < n; ++w)
 					if (a[w][j] != 1) {
 						f = false;
 						break;
 					}
 				if (f)
 					continue;
 				cout << "NO\n";
 				return;
 			}
 	cout << "YES\n";
 
 }
