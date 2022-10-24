#include <iostream>
 #include <cstdio>
 #include <vector>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <queue>
 #include <set>
 #include <map>
 #include <bitset>
 #include <cmath>
 #include <ctime>
 #pragma comment (linker, "/STACK:256000000")
 
 using namespace std;
 
 void readData() {
 }
 
 // 0 - Paper
 // 1 - Rock
 // 2 - Scissors
 
 int winner(int x, int y) {
 	if (x == y) {
 		return -1;
 	}
 	if (x > y) {
 		swap(x, y);
 	}
 	if (x == 0 && y == 1) {
 		return 0;
 	}
 	if (x == 0 && y == 2) {
 		return 2;
 	}
 	if (x == 1 && y == 2) {
 		return 1;
 	}
 	return -1;
 }
 
 void solve(int test) {
 	int n, r, p, s;
 	cin >> n >> r >> p >> s;
 	vector < int > order(1 << n);
 	for (int i = 0; i < p; ++i) {
 		order[i] = 0;
 	}
 	for (int i = p; i < p + r; ++i) {
 		order[i] = 1;
 	}
 	for (int i = p + r; i < (1 << n); ++i) {
 		order[i] = 2;
 	}
 
 	do {
 		vector < int > res = order;
 		bool bad = false;
 		while (res.size() > 1 && !bad) {
 			vector < int > cur;
 			for (int i = 0; i < res.size(); i += 2) {
 				cur.push_back(winner(res[i], res[i + 1]));
 				if (cur.back() == -1) {
 					bad = true;
 					break;
 				}
 			}
 			res = cur;
 		}
 		if (bad) {
 			continue;
 		}
 		printf("Case #%d: ", test);
 		for (int i = 0; i < order.size(); ++i) {
 			printf("%c", (order[i] == 0 ? 'P' : (order[i] == 1 ? 'R' : 'S')));
 		}
 		printf("\n");
 		return;
 	} while (next_permutation(order.begin(), order.end()));
 	printf("Case #%d: IMPOSSIBLE\n", test);
 }
 
 int main(int argc, char* argv[]) {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int left_bound, right_bound;
 
 	/*freopen(argv[3], "w", stdout);	
 	sscanf(argv[1], "%d", &left_bound);
 	sscanf(argv[2], "%d", &right_bound);*/
 
 	int t;
 	cin >> t;
 	left_bound = 1, right_bound = t;
 	for (int i = 1; i <= t; ++i) {
 		if (i >= left_bound && i <= right_bound) {
 			solve(i);
 		}
 		cerr << i << ": " << clock() << endl;
 	}
 
 	return 0;
 }
