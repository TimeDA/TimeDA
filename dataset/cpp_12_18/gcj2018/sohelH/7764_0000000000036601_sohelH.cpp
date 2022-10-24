#include<bits/stdc++.h>

using namespace std;

struct Node {
	int x;

};

int N, L;

bool cmp(const Node &a, const Node &b) {
	int aa = (100 * a.x) % N;
	int bb = (100 * b.x) % N;

	return aa > bb;
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> N >> L;
		vector<int> v;
		int rem = N;
		for (int i = 0; i < L; i++) {
			int a; cin >> a; v.push_back(a);
			rem -= a;
		}

		vector<int> done, todo;
		for (int i = 0; i < v.size(); i++) {
			int num = v[i] * 100;
			if (num % N == 0) {
				done.push_back(v[i]);
			} else {
				int m = (v[i] * 100) % N;
				if ( (m*2) >= N ) {
					done.push_back(v[i]);
				} else {
					todo.push_back(v[i]);
				}
			}
		}

		int m = 100 % N;
		if ( (m*2) >= N) {
			for (int i = 0; i < todo.size(); i++)
				done.push_back(todo[i]);
			int res = 0;
			for (int i = 0; i < done.size(); i++) {
				res += (done[i] * 100) / N;
				int m = (done[i] * 100) % N;
				if ( (m*2) >= N) res++;
			}
			while (rem) {
				bool ok = false;
				for (int i = 1; i <= rem; i++) {
					int m = (i * 100) % N;
					if ( (m*2) >= N) {
						res += (i * 100) / N;
						res++;
						rem -= i;
						ok = true;
						break;
					}
				}
				if (!ok) {
						res += (rem * 100) / N;
						rem = 0;
				}
			}
			printf("Case #%d: %d\n", cases, res);
		} else {
			vector<Node> nodes;
			for (int i = 0; i < todo.size(); i++) {
				Node node;
				node.x = todo[i];
				nodes.push_back(node);
			}
			sort(nodes.begin(), nodes.end(), cmp);

			for (int i = 0; i < nodes.size(); i++) {
				while (rem) {
					nodes[i].x++;
					rem--;
					int m = (nodes[i].x * 100) % N;
					if ( (m*2) >= N ) break;
				}
			}

			int res = 0;
			for (int i = 0; i < done.size(); i++) {
				res += (done[i] * 100) / N;
				int m = (done[i] * 100) % N;
				if ( (m*2) >= N) res++;
			}

			for (int i = 0; i < nodes.size(); i++) {
				res += (nodes[i].x * 100) / N;
				int m = (nodes[i].x * 100) % N;
				if ( (m*2) >= N) res++;
			}

			while (rem) {
				bool ok = false;
				for (int i = 1; i <= rem; i++) {
					int m = (i * 100) % N;
					if ( (m*2) >= N) {
						res += (i * 100) / N;
						res++;
						rem -= i;
						ok = true;
						break;
					}
				}
				if (!ok) {
						res += (rem * 100) / N;
						rem = 0;
				}
			}

			printf("Case #%d: %d\n", cases, res);
		}

	}
	return 0;
}
