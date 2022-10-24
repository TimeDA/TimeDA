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
 
 #define inf 2100000000
 #define eps 1e-9
 
 int main()
 {
 	string _task = "B";
 	string _in = _task + "-small.in", _out = _task + "-small.out";
 	//string _in = _task + "-large.in", _out = _task + "-large.out";
 	ifstream fin(_in.c_str());
 	ofstream fout(_out.c_str());
 
 	string ts;
 	getline(fin, ts);
 	int _N = atoi(ts.c_str());
 
 	for (int _n = 1; _n <= _N; ++_n)
 	{
 		getline(fin, ts);
 		vi t = split<int>(ts);
 
 		int n = t[0];
 
 		getline(fin, ts);
 		vi a = split<int>(ts);
 		
 
 		int res = 0;
 
 		vi b = a;
 
 		sort(all(b));
 		//reverse(all(b));
 
 		//map<int, int> m;
 
 		//for (int i = 0; i < sz(a); ++i)
 		//{
 		//	m[a[i]] = i;
 		//}
 
 		//deque<int> c;
 		//c.push_back(b[0]);
 		//int ind = m[b[0]];
 		//for (int i = 1; i < sz(a); ++i)
 		//{
 		//	if (m[b[i]] < ind)
 		//		c.push_front(b[i]);
 		//	else
 		//		c.push_back(b[i]);
 		//}
 
 		//vi d(all(c));
 
 		//for (int i = 0; i < ind; ++i)
 		//{
 		//	int x = d[i];
 		//	int indA = -1;
 		//	for (int j = 0; j < ind; ++j)
 		//	{
 		//		if (a[j] == x)
 		//		{
 		//			indA = j;
 		//			break;
 		//		}
 		//	}
 		//	assert(indA != -1);
 		//	if (i == indA)
 		//		continue;
 
 		//	int r = 0;
 		//	for (int j = indA; j < i; ++j)
 		//	{
 		//		swap(a[j], a[j + 1]);
 		//		++r;
 		//	}
 		//	for (int j = indA; j > i; --j)
 		//	{
 		//		swap(a[j], a[j - 1]);
 		//		++r;
 		//	}
 		//	res += r;
 		//}
 
 		//for (int i = n - 1; i > ind; --i)
 		//{
 		//	int x = d[i];
 		//	int indA = -1;
 		//	for (int j = n - 1; j > ind; --j)
 		//	{
 		//		if (a[j] == x)
 		//		{
 		//			indA = j;
 		//			break;
 		//		}
 		//	}
 		//	assert(indA != -1);
 		//	if (i == indA)
 		//		continue;
 
 		//	int r = 0;
 		//	for (int j = indA; j < i; ++j)
 		//	{
 		//		swap(a[j], a[j + 1]);
 		//		++r;
 		//	}
 		//	for (int j = indA; j > i; --j)
 		//	{
 		//		swap(a[j], a[j - 1]);
 		//		++r;
 		//	}
 		//	res += r;
 		//}
 
 		res = inf;
 		vi d = b;
 		do
 		{
 			int r = 0;
 			int ind = -1;
 
 			for (int j = 0; j < n; ++j)
 			{
 				if (d[j] == b.back())
 				{
 					ind = j;
 					break;
 				}
 			}
 
 			bool ok = true;
 			for (int i = 0; i < ind; ++i)
 			{
 				if (d[i] > d[i + 1])
 				{
 					ok = false;
 					break;
 				}
 			}
 			for (int i = ind + 1; i < n; ++i)
 			{
 				if (d[i - 1] < d[i])
 				{
 					ok = false;
 					break;
 				}
 			}
 
 			if (!ok)
 				continue;
 
 			vi e = a;
 			for (int i = 0; i <= ind; ++i)
 			{
 				int x = d[i];
 				int indA = -1;
 				for (int j = 0; j < n; ++j)
 				{
 					if (e[j] == x)
 					{
 						indA = j;
 						break;
 					}
 				}
 				assert(indA != -1);
 				if (i == indA)
 					continue;
 
 				for (int j = indA; j < i; ++j)
 				{
 					swap(e[j], e[j + 1]);
 					++r;
 				}
 				for (int j = indA; j > i; --j)
 				{
 					swap(e[j], e[j - 1]);
 					++r;
 				}
 			}
 
 			for (int i = n - 1; i > ind; --i)
 			{
 				int x = d[i];
 				int indA = -1;
 				for (int j = n - 1; j >= 0; --j)
 				{
 					if (e[j] == x)
 					{
 						indA = j;
 						break;
 					}
 				}
 				assert(indA != -1);
 				if (i == indA)
 					continue;
 
 				for (int j = indA; j < i; ++j)
 				{
 					swap(e[j], e[j + 1]);
 					++r;
 				}
 				for (int j = indA; j > i; --j)
 				{
 					swap(e[j], e[j - 1]);
 					++r;
 				}
 			}
 			assert(e == d);
 			res = min(res, r);
 
 		}
 		while (next_permutation(all(d)));
 
 		fout << "Case #" << _n << ": ";
 		fout << res;
 		fout << endl;
 	}	
 
 	return 0;
 }
