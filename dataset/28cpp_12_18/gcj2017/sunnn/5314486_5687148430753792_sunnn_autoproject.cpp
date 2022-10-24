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
 		int n = t[0], c = t[1], m = t[2];
 
 		map<int, vi> c2p; 
 		for (int i = 0; i < m; ++i)
 		{
 			getline(fin, ts);
 			vi a = split<int>(ts);
 			c2p[a[1]].push_back(a[0]);
 		}
 
 
 		int r = 1;
 		int pr = 0;
 		for (; r <= 1000; ++r)
 		{
 			bool bigOk = true;
 			vector<map<int, int>> rides(r);
 			map<int, set<int>> c2r;
 			pr = 0;
 
 			for (auto it = c2p.begin(); it != c2p.end(); ++it)
 			{
 				vi & pos = it->second;
 				for (int i = 0; i < sz(pos); ++i)
 				{
 					int P = pos[i];
 					bool ok = false;
 					while (!ok && P > 0)
 					{
 						for (int rI = 0; rI < r; ++rI)
 						{
 							if (c2r[it->first].count(rI) == 1)
 								continue;
 
 							if (rides[rI].find(P) == rides[rI].end())
 							{
 								c2r[it->first].insert(rI);
 								rides[rI][P] = it->first;
 								ok = true;
 								break;
 							}
 						}
 						if (!ok)
 						{
 							--P;
 						}
 					}
 					if (!ok)
 					{
 						bigOk = false;
 						break;
 					}
 					if (pos[i] != P)
 						++pr;
 				}
 				if (!bigOk)
 					break;
 			}
 			if (bigOk)
 				break;
 		}
 		
 		fout << "Case #" << _n << ": ";
 		fout << r << ' ' << pr;
 		fout << endl;
 	}	
 
 	return 0;
 }
