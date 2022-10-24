#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<double>
#define vvd vector<vd>
#define vp vector<pii>
#define vvp vector<vp>
#define msi map<string, int>
#define mii map<int, int>

#define sqr(a) ((a) * (a))
#define two(n) (1 << (n))
#define twoLL(n) (1LL << (n))
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }
template<typename TContainer> inline TContainer rev(TContainer const & c) { TContainer cont = c; reverse(all(cont)); return cont; }

#define inf 2100000000
#define eps 1e-9

int const MAX_ITER = 1000000;

int main()
{
	string ts;
	getline(cin, ts);
	int _T = atoi(ts.c_str());

	for (int _t = 0; _t < _T; ++_t)
	{
		getline(cin, ts);
		vi t = split<int>(ts);
		int n = t[0], L = t[1];

		unordered_set<string> dict;
		vector<vector<char>> opt(L);
		for (int i = 0; i < n; ++i)
		{
			getline(cin, ts);
			dict.insert(ts);
			for (int j = 0; j < L; ++j)
				opt[j].push_back(ts[j]);
		}

		for (int i = 0; i < L; ++i)
		{
			sort(all(opt[i]));
			opt[i].erase(unique(all(opt[i])), opt[i].end());
		}

		bool ok = false;
		string res = *dict.begin();
		for (int i = 0; i < MAX_ITER; ++i)
		{
			int ind = rand() % L;
			int chInd = rand() % sz(opt[ind]);
			res[ind] = opt[ind][chInd];
			if (dict.count(res) == 0)
			{
				ok = true;
				break;
			}
		}

		

		cout << "Case #" << _t + 1 << ": ";
		cout << (ok ? res : string(1, '-'));
		cout << endl;
	}
	return 0;
}
