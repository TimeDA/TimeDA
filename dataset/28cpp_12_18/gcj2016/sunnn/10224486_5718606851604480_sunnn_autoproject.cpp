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
 	string _task = "A";
 	string _in = _task + "-small.in", _out = _task + "-small.out";
 	//string _in = _task + "-large.in", _out = _task + "-large.out";
 	ifstream fin(_in.c_str());
 	ofstream fout(_out.c_str());
 
 	string ts;
 	getline(fin, ts);
 	int _N = atoi(ts.c_str());
 
 	for (int _n = 1; _n <= _N; ++_n)
 	{
 		// don't forget to clear all global objects!
 
 		getline(fin, ts);
 		vi t = split<int>(ts);
 
 		int n = t[0], r = t[1], p = t[2], s = t[3];
 
 		map<char, string> m;
 		m['S'] = "SP";
 		m['R'] = "RS";
 		m['P'] = "PR";
 
 		vs st = { "P", "R", "S" };
 
 		for (int i = 0; i < n; ++i)
 		{
 			vs newSt(sz(st));
 			for (int j = 0; j < sz(st); ++j)
 			{
 				for (int k = 0; k < sz(st[j]); ++k)
 					newSt[j] += m[st[j][k]];
 			}
 			st = newSt;
 		}
 
 		int x = 1;
 		for (int i = 0; i < n; ++i)
 		{
 			x *= 2;
 			for (int j = 0; j < sz(st); ++j)
 			{
 				for (int k = 0; k < sz(st[j]); k += x)
 				{
 					if (st[j].substr(k, x / 2) > st[j].substr(k + x / 2, x / 2))
 						for (int l = 0; l < x / 2; ++l)
 							swap(st[j][k + l], st[j][k + x / 2 + l]);
 				}
 			}
 		}
 
 		string res = "IMPOSSIBLE";
 		for (int j = 0; j < sz(st); ++j)
 		{
 			if (count(all(st[j]), 'P') == p && count(all(st[j]), 'R') == r && count(all(st[j]), 'S') == s)
 			{
 				if (res == "IMPOSSIBLE" || res < st[j])
 					res = st[j];
 			}
 		}
 		
 		fout << "Case #" << _n << ": ";
 		fout << res;
 		fout << endl;
 	}	
 
 	return 0;
 }
