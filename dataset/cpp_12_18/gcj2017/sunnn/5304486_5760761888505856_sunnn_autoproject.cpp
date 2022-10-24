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
 
 		//getline(fin, ts);
 		//int n = atoi(ts.c_str());
 
 		getline(fin, ts);
 		vi t = split<int>(ts);
 
         int n = t[0], m = t[1];
         vs a(n);
         for (int i = 0; i < n; ++i)
         {
             getline(fin, a[i]);
             assert(sz(a[i]) == m);
         }
 
 		for (int i = 0; i < n; ++i)
         {
             size_t p = a[i].find_first_not_of('?');
             if (p == string::npos)
                 continue;
 
             int j = 0;
             while (j < p)
             {
                 a[i][j] = a[i][p];
                 ++j;
             }
 
             for (int jj = p + 1; jj < m; ++jj)
             {
                 if (a[i][jj] != '?')
                 {
                     p = jj;
                 }
                 else
                     a[i][jj] = a[i][p];
             }
         }
 
         {
             int i = 0;
             while (i < n && a[i][0] == '?')
                 ++i;
 
             if (i != n)
             {
                 for (int ii = 0; ii < i; ++ii)
                     a[ii] = a[i];
 
                 for (int ii = i + 1; ii < n; ++ii)
                 {
                     if (a[ii][0] != '?')
                         i = ii;
                     else
                         a[ii] = a[i];
                 }
             }
         }
 
 		fout << "Case #" << _n << ":\n";
 		for (int i = 0; i < n; ++i)
             fout << a[i] << '\n';
 		fout << endl;
 	}	
 
 	return 0;
 }
