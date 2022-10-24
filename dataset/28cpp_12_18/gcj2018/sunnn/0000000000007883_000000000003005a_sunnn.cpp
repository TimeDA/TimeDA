#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
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

bool solve(vvi const & dp, int n, int m, int h, int v)
{
	int cnt = dp[n][m];
	int pieces = (h + 1) * (v + 1);
	int c = cnt / pieces;

	if (cnt % pieces != 0)
		return false;

	int inVer = cnt / (v + 1);
	vi ver(1, 0);

	while (ver.size() != v + 2)
	{
		int prev = ver.back();
		int j = prev + 1;
		for (; j <= m; ++j)
		{
			int inCurVer = dp[n][j] - dp[n][prev];
			if (inCurVer == inVer)
			{
				ver.push_back(j);
				break;
			}
			else if (inCurVer > inVer)
			{
				return false;
			}
		}
		if (j == m + 1)
		{
			return false;
		}
	}

	int inHor = cnt / (h + 1);
	vi hor(1, 0);

	while (hor.size() != h + 2)
	{
		int prev = hor.back();
		int i = prev + 1;
		for (; i <= n; ++i)
		{
			int inCurHor = dp[i][m] - dp[prev][m];
			if (inCurHor == inHor)
			{
				hor.push_back(i);
				break;
			}
			else if (inCurHor > inHor)
			{
				return false;
			}
		}
		if (i == n + 1)
		{
			return false;
		}
	}

	for (int i = 1; i < sz(hor); ++i)
		for (int j = 1; j < sz(ver); ++j)
			if (dp[hor[i]][ver[j]] - dp[hor[i - 1]][ver[j]] - dp[hor[i]][ver[j - 1]] + dp[hor[i - 1]][ver[j - 1]] != c)
			{
				return false;
			}

	return true;
}

int main()
{
	string ts;
	getline(cin, ts);
	int _T = atoi(ts.c_str());

	for (int _t = 0; _t < _T; ++_t)
	{
		getline(cin, ts);
		vi t = split<int>(ts);

		int n = t[0], m = t[1], h = t[2], v = t[3];

		vs b(n);
		for (int i = 0; i < n; ++i)
		{
			getline(cin, b[i]);
		}

		vvi dp(n + 1, vi(m + 1, 0));

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
				if (b[i - 1][j - 1] == '@')
					++dp[i][j];
			}									

		bool ok = solve(dp, n, m, h, v);
		cout << "Case #" << _t + 1 << ": ";
		if (!ok)
			cout << "IMPOSSIBLE";
		else
			cout << "POSSIBLE";
		cout << endl;
	}
	return 0;
}
