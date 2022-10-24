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
 
 /// 1 -> 1
 /// i -> 5
 /// j -> 6
 /// k -> 7
 int multAbs(int x, int y)
 {
 	if (x == 1 && y == 1)
 		return 1;
 	if (x == y)
 		return -1;
 	if (x == 1 || y == 1)
 		return x * y;
 	if (x == 5 && y == 6)
 		return 7;
 	if (x == 5 && y == 7)
 		return -6;
 	if (x == 6 && y == 7)
 		return 5;
 	if (x == 6 && y == 5)
 		return -7;
 	if (x == 7 && y == 5)
 		return 6;
 	if (x == 7 && y == 6)
 		return -5;
 	return 1000;
 }
 
 int mult(int x, int y)
 {
 	if (x < 0 && y < 0)
 		return multAbs(-x, -y);
 	if (x < 0 || y < 0)
 		return -multAbs(abs(x), abs(y));
 	return multAbs(x, y);
 }
 
 int deg(int x, ll d)
 {
 	if (d == 0)
 		return 1;
 	if (d == 1)
 		return x;
 	if (d >= 4)
 		d %= 4;
 	int r = 1;
 	for (int i = 0; i < d; ++i)
 		r = mult(r, x);
 	return r;
 }
 
 int main()
 {
 	string _task = "C";
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
 		vector<ll> t = split<ll>(ts);
 
 		int L = static_cast<int>(t[0]);
 		ll X = t[1];
 
 		string s;
 		getline(fin, s);
 
 		vi a(L, 0);
 		for (int i = 0; i < L; ++i)
 		{
 			switch (s[i])
 			{
 			case 'i': a[i] = 5; break;
 			case 'j': a[i] = 6; break;
 			case 'k': a[i] = 7; break;
 			}
 		}
 
 		vvi memo(L + 1, vi(L + 1, 1));
 
 		for (int st = 0; st < L; ++st)
 		{
 			memo[st][st + 1] = a[st];
 			for (int k = st + 1; k < L; ++k)
 				memo[st][k + 1] = mult(memo[st][k], a[k]);
 		}
 
 		int R = memo[0][L];
 
 		bool ok = false;
 
 		for (int midX = 1; midX < L - 1; ++midX)
 		{
 			int beg = memo[0][midX];
 			for (int z = 0; z < 4; ++z)
 			{
 				if (X >= z + 1 && mult(deg(R, z), beg) == 5)
 				{
 					for (int midY = midX + 1; midY < L; ++midY)
 					{
 						int mid = memo[midX][midY];
 						int en = memo[midY][L];
 
 						if (mid == 6 && mult(en, deg(R, X - z - 1)) == 7)
 						{
 							ok = true;
 							break;
 						}
 					}
 				}
 				if (ok)
 					break;
 			}
 			if (ok)
 				break;
 		}
 
 		if (!ok && X >= 2)
 		{
 			for (int midX = 1; midX <= L; ++midX)
 			{
 				int beg = memo[0][midX];
 				int afterBeg = memo[midX][L];
 
 				for (int z = 0; z < 4; ++z)
 				{
 					if (X >= z + 1 && mult(deg(R, z), beg) == 5)
 					{
 						for (int midY = 0; midY < L; ++midY)
 						{
 							int en = memo[midY][L];
 							int beforeEn = memo[0][midY];
 
 							ll left = X - z - 1;
 							for (int y = 0; y < 4; ++y)
 							{
 								if (left >= y + 1 && mult(mult(afterBeg, deg(R, y)), beforeEn) == 6 && mult(en, deg(R, left - y - 1)) == 7)
 								{
 									ok = true;
 									break;
 								}
 							}
 							if (ok)
 								break;
 						}
 					}
 				}
 				if (ok)
 					break;
 			}
 		}
 		
 		fout << "Case #" << _n << ": ";
 		fout << (ok ? "YES" : "NO");
 		fout << endl;
 	}	
 
 	return 0;
 }
