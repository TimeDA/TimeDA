#include <vector>
 #include <string>
 #include <queue>
 #include <list>
 #include <set>
 #include <unordered_set>
 #include <map>
 #include <unordered_map>
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
 	string _task = "D";
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
 		int m = t[0], n = t[1];
 
 		vs s;
 		for (int i = 0; i < m; ++i)
 		{
 			getline(fin, ts);
 			s.push_back(ts);
 		}
 
 		vector<vi> cur;
 		for (int i = 0; i < n; ++i)
 		{
 			vi x(1, i);
 			cur.push_back(x);
 		}
 
 		for (int i = 1; i < m; ++i)
 		{
 			vector<vi> next;
 			for (int k = 0; k < sz(cur); ++k)
 			{
 				for (int j = 0; j < n; ++j)
 				{
 					vi t = cur[k];
 					t.push_back(j);
 					next.push_back(t);
 				}
 			}
 			cur = next;
 		}
 
 		int res = -1;
 		int cnt = 0;
 
 		vector<unordered_set<string>> serv(n);
 		for (int i = 0; i < sz(cur); ++i)
 		{
 			serv.clear();
 			serv.assign(n, unordered_set<string>());
 			for (int j = 0; j < m; ++j)
 			{
 				auto & ser = serv[cur[i][j]];
 				string s1 = "";
 				ser.insert(s1);
 				for (int k = 0; k < sz(s[j]); ++k)
 				{
 					s1 += s[j][k];
 					ser.insert(s1);
 				}
 			}
 
 			int r = 0;
 			for (int j = 0; j < sz(serv); ++j)
 				r += sz(serv[j]);
 
 			if (r > res)
 			{
 				res = r;
 				cnt = 1;
 			}
 			else if (r == res)
 			{
 				++cnt;
 			}
 		}
 
 		fout << "Case #" << _n << ": ";
 		fout << res << ' ' << cnt;
 		fout << endl;
 	}	
 
 	return 0;
 }
