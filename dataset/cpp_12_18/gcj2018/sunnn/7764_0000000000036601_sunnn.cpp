#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
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

int main()
{
	string ts;
	getline(cin, ts);
	int _T = atoi(ts.c_str());

	for (int _t = 0; _t < _T; ++_t)
	{
		getline(cin, ts);
		vi t = split<int>(ts);

		int n = t[0], m = t[1];

		getline(cin, ts);
		vi a = split<int>(ts);

		int left = n - accumulate(all(a), 0);

		int x = 1;
		for (; x <= left; ++x)
		{
			int p = ((x * 1000) / n + 5) / 10;
			int q = x * 100 / n;
			if (p > q)
				break;
		}

		unordered_map<int, int> b;
		for (int i = 0; i < m; ++i)
		{
			if (b.find(a[i]) != b.end())
				continue;

			int x = 0;
			for (; x <= left; ++x)
			{
				int y = a[i] + x;
				int p = ((y * 1000) / n + 5) / 10;
				int q = y * 100 / n;
				if (p > q)
					break;
			}
			if (x == left + 1)
				x = 0;
			b[a[i]] = x;
		}

		vp c;
		for (int i = 0; i < m; ++i)
			c.push_back(pii(b[a[i]], a[i]));

		sort(all(c));

		
		int res = 0;
		for (int i = 0; i < m; ++i)
		{
			if (x <= left && c[i].first > x)
			{
				int p = ((x * 1000) / n + 5) / 10;
				res += (left / x) * p;
				left = 0;
			}
			int y = c[i].second + min(c[i].first, left);
			int p = ((y * 1000) / n + 5) / 10;
			res += p;
			left = max(left - c[i].first, 0);
		}
		if (x <= left)
		{
			int p = ((x * 1000) / n + 5) / 10;
			res += (left / x) * p;
			left = 0;
		}
		else
		{
			res += ((left * 1000) / n + 5) / 10;
		}

		cout << "Case #" << _t + 1 << ": ";
		cout << res;
		cout << endl;
	}
	return 0;
}
