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
 #define pii pair<ll, ll>
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
 
 inline ll abs(ll a) { return (a < 0) ? -a : a; }
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
 		ll W = t[1], H = t[2];
 		bool rev = false;
 		if (W < H)
 		{
 			swap(W, H);
 			rev = true;
 		}
 
 		
 		getline(fin, ts);
 		vi rt = split<int>(ts);
 		assert(n == sz(rt));
 		
 		vp r;
 		for (int i = 0; i < n; ++i)
 		{
 			r.push_back(pii(rt[i], i));
 		}
 		sort(all(r), greater<pii>());
 		vector<double> x(n, -1), y(n, -1);
 		
 		x[r[0].second] = 0.0;
 		y[r[0].second] = 0.0;
 		if (n > 1)
 		{
 			x[r[1].second] = W;
 			y[r[1].second] = H;
 		}
 		if (n > 2)
 		{
 			if (r[0].first + r[2].first <= H)
 			{
 				x[r[2].second] = 0;
 				y[r[2].second] = H;
 				if (n > 3)
 				{
 					x[r[3].second] = W;
 					y[r[3].second] = 0;
 					int x1 = r[0].first, x2 = W - r[3].first;
 					int y1 = r[2].first, y2 = W - r[1].first;
 					for (int i = 4; i < n; ++i)
 					{
 						if (x2 - x1 >= r[i].first)
 						{
 							x[r[i].second] = x1 + r[i].first;
 							y[r[i].second] = 0;
 							x1 += r[i].first * 2;
 						}
 						else if (y2 - y1 >= r[i].first)
 						{
 							x[r[i].second] = y1 + r[i].first;
 							y[r[i].second] = H;
 							y1 += r[i].first * 2;
 						}
 						else
 							assert(!"logic_error");
 					}
 				}
 			}
 			else
 			{
 				x[r[2].second] = r[0].first + r[2].first;
 				y[r[2].second] = 0;
 				if (n > 3)
 				{
 					x[r[3].second] = W - r[1].first - r[3].first;
 					y[r[3].second] = H;
 					
 					int x1 = r[0].first + 2 * r[2].first, x2 = W;
 					int y1 = 0, y2 = W - r[1].first - 2 * r[3].first;
 					for (int i = 4; i < n; ++i)
 					{
 						if (x2 - x1 >= r[i].first)
 						{
 							x[r[i].second] = x1 + r[i].first;
 							y[r[i].second] = 0;
 							x1 += r[i].first * 2;
 						}
 						else if (y2 - y1 >= r[i].first)
 						{
 							x[r[i].second] = y2 - r[i].first;
 							y[r[i].second] = H;
 							y1 -= r[i].first * 2;
 						}
 						else
 							assert(!"logic_error");
 					}
 				}
 			}
 		}
 
 		fout << "Case #" << _n << ": ";		
 		if (rev)
 			swap(x, y);
 		for (int i = 0; i < n; ++i)
 		{
 			if (i != 0)
 				fout << " ";
 			fout << fixed << setprecision(7) << x[i] << " " << y[i];
 		}
 		fout << endl;
 	}	
 
 	return 0;
 }
