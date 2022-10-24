#include<bits/stdc++.h>

using namespace std;

int R, B, C;
struct Cashier {
	int m, s, p;
};

vector<Cashier> v;
vector<int> G, I;
long long res;

void rec(int u, int b, vector<Cashier> &cc) {
	if (b < 0) return;

	long long int rem = 0;
	for (int i = u; i < cc.size(); i++)
		rem += cc[i].m;
	if (rem < b) return;

	if (u == cc.size()) {
		if (b != 0) return;
		long long sum = -1;
		for (int i = 0; i < cc.size(); i++) {
			long long v = I[i];
			v *= cc[i].s;
			v += cc[i].p;
			if (v > sum) sum = v;
		}
		if (sum < res) {
			res = sum;
		}
		return;
	}
	for (int i = 1; i <= cc[u].m && i <= b; i++) {
		I.push_back(i);
		rec(u + 1, b - i, cc);
		I.pop_back();
	}
}

void process(vector<Cashier> &cc) {
	long long sum = 0;
	for (int i = 0; i < cc.size(); i++) {
		sum += cc[i].m;
	}
	if (sum < B) return;
	I.clear();
	rec(0, B, cc);
}

void dfs(int u, int d) {
	if (u == C) {
		vector<Cashier> cc;
		for (int i = 0; i < G.size(); i++) {
			if (G[i] == 1) {
				cc.push_back(v[i]);
			}
		}
		process(cc);
	} else {
		if ( (d + 1) <= R ) {
			G.push_back(1);
			dfs(u + 1, d + 1);
			G.pop_back();
		}
		G.push_back(0);
		dfs(u + 1, d);
		G.pop_back();
	}
}

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		cin >> R >> B >> C;

		v.clear();

		for (int i = 0; i < C; i++) {
			Cashier cashier;
			cin >> cashier.m >> cashier.s >> cashier.p;
			v.push_back(cashier);
		}
		res = 100000000; res *= res;
		G.clear();
		dfs(0, 0);
		cout << "Case #" << cases << ": " << res << endl;
	}
	return 0;
}
