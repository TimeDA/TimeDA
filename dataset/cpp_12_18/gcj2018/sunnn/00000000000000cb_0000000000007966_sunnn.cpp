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

bool checkDamage(string const & a, ll d)
{
	ll p = 1;
	ll r = 0;
	for (int i = 0; i < sz(a); ++i)
	{
		if (a[i] == 'C')
			p *= 2;
		else
			r += p;
	}

	return r <= d;
}

bool getNext(string & a)
{
	int n = sz(a);
	int ok = false;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] == 'C' && ok)
		{
			swap(a[i], a[i + 1]);
			return true;
		}
		else
			ok = true;
	}
	return false;
}

int main()
{
	string ts;
	getline(cin, ts);
	int _T = atoi(ts.c_str());

	for (int _t = 0; _t < _T; ++_t)
	{
		getline(cin, ts);
		vs t = split<string>(ts);
		int d = cast<int>(t[0]);
		string a = t[1];

		int res = 0;
		bool ok = false;
		do
		{
			if (checkDamage(a, d))
			{
				ok = true;
				break;
			}
			++res;
		}
		while (getNext(a));

		cout << "Case #" << _t + 1 << ": ";
		if (ok)
			cout << res;
		else
			cout << "IMPOSSIBLE";
		cout << endl;
	}
	return 0;
}
