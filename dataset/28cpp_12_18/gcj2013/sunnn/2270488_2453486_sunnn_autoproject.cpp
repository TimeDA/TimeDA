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
 
 inline void repl(string & s, string const & oldStr, string const & newStr) { int pos = 0; while ((pos = (int)s.find(oldStr, pos)) != -1) { s.replace(pos, sz(oldStr), newStr); pos += sz(newStr); } }
 
 #define inf 2100000000
 #define eps 1e-9
 
 bool won(vs b, string const & c)
 {
 	for (int i = 0; i < sz(b); ++i)
 		repl(b[i], "T", c);
 
 	string good(4, c[0]);
 	for (int i = 0; i < 4; ++i)
 		if (b[i] == good)
 			return true;
 
 	for (int j = 0; j < 4; ++j)
 	{
 		string t;
 		for (int i = 0; i < 4; ++i)
 			t += b[i][j];
 		if (t == good)
 			return true;
 	}
 
 	string t, s;
 	for (int i = 0; i < 4; ++i)
 	{
 		t += b[i][i];
 		s += b[i][3 - i];
 	}
 	if (t == good || s == good)
 		return true;
 
 	return false;
 }
 
 string solve(vs const & b)
 {
 	if (won(b, "X"))
 		return "X won";
 
 	if (won(b, "O"))
 		return "O won";
 
 	bool draw = true;
 	for (int i = 0; i < sz(b); ++i)
 		if (b[i].find('.') != string::npos)
 			draw = false;
 
 	return draw ? "Draw" : "Game has not completed";
 }
 
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
 		
 		vs b(4);
 		for (int i = 0; i < 4; ++i)
 			getline(fin, b[i]);
 
 		getline(fin, ts);
 		
 		string res = solve(b);
 
 		fout << "Case #" << _n << ": ";
 		fout << res;
 		fout << endl;
 	}	
 
 	return 0;
 }
