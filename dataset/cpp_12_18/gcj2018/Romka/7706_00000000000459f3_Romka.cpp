#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

const int P = 239017;

int ans;
unordered_set<long long> seen;
bool was[110][110];
vector<pair<int, int>> up, up2;

long long getKey(int R, int B) {
	up2 = up;
	sort(up2.begin(), up2.end());
	long long hash = (R + 1) * P + (B + 1);
	for (const auto& q : up2) {
		hash = hash * P + q.first + 1;
		hash = hash * P + q.second + 1;
	}
	return hash;
}

void go(int R, int B, int q) {
	// printf("go %d %d\n", R, B);
	// for (int x : used) printf("%d ", x); printf("\n");
	if (!seen.insert(getKey(R, B)).second)
		return;
	int lb = -1;
	if (q > ans) {
		ans = q;
	}
	for (int r = 0; r <= R; r++) {
		for (int b = 0; b <= B; b++) {
			if (r == 0 && b == 0) continue;
			
			if (was[r][b]) continue;
			if (b == lb) {
				if (b == 0) return;
				break;
			}
			lb = b;
			was[r][b] = true;
			up.emplace_back(r, b);
			go(R - r, B - b, q + 1);
			up.pop_back();
			was[r][b] = false;
			break;
		}
	}
}


void solve() {
	int R, B;
	scanf("%d %d", &R, &B);

	seen.clear();
	for (int i = 0; i <= R; i++) for (int j = 0; j <= B; j++) was[i][j] = false;
	ans = 0;
	go(R, B, 0);
	printf("%d\n", ans);
}


int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}