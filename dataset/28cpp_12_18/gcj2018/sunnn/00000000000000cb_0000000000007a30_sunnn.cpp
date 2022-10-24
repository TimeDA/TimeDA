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

void pickPosition(vvi const & b, int a, int & r, int & c)
{
	int orX = 100, orY = 100;
	
	int n, m;
	if (a == 20)
	{
		n = 5, m = 4;
	}
	else if (a == 10)
	{
		n = 3, m = 4;
	}
	else if (a == 200)
	{
		n = 14, m = 15;
	}
	else 
	{
		assert(false);
	}

	int best = 0;
	for (int i = 1; i < n - 1; ++i)
		for (int j = 1; j < m - 1; ++j)
		{
			int res = 0;
			for (int ii = i - 1; ii <= i + 1; ++ii)
				for (int jj = j - 1; jj <= j + 1; ++jj)
					if (b[orX + ii][orY + jj] == 0)
						++res;

			if (res > best)
			{
				best = res;
				r = orX + i, c = orY + j;
			}
		}
}

int main()
{
	string ts;
	getline(cin, ts);
	int _T = atoi(ts.c_str());

	for (int _t = 0; _t < _T; ++_t)
	{
		getline(cin, ts);
		int a = cast<int>(ts);

		vvi b = vvi(1000, vi(1000, 0));

		int r, c;
		bool ok = false;
		while (true)
		{
			pickPosition(b, a, r, c);

			cout << r << ' ' << c << endl << flush;

			getline(cin, ts);
			if (ts == "-1 -1")
				break;
			else if (ts == "0 0")
			{
				ok = true;
				break;
			}

			vi ti = split<int>(ts);

			b[ti[0]][ti[1]] = 1;
		}
	}
	return 0;
}
