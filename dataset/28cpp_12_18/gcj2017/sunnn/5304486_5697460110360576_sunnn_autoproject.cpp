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
 
         int n = t[0], p = t[1];
 
         getline(fin, ts);
         vi r = split<int>(ts);
 
         vvi q(n);
         for (int i = 0; i < n; ++i)
         {
             getline(fin, ts);
             q[i] = split<int>(ts);
             assert(sz(q[i]) == p);
 
             sort(all(q[i]));
         }
 
         map<int, vector<pii>> range;
         for (int s = 1; ; ++s)
         {
             vector<pii> kit(n);
             for (int i = 0; i < n; ++i)
                 kit[i] = pii((9 * s *r[i] + 9) / 10, (11 * s * r[i]) / 10);
         
             if (kit.back().first > q.back().back())
                 break;
 
             range[s] = move(kit);
         }
 
         int res = 0;
         vi ind(n, 0);
 
         for (auto it = range.begin(); it != range.end(); )
         {
             int s = it->first;
             vector<pii> const & ran = it->second;
 
             bool ok = true;
             for (int i = 0; i < n; ++i)
             {
                 while (ind[i] < p && q[i][ind[i]] < ran[i].first)
                     ++ind[i];
 
                 if (ind[i] == p || q[i][ind[i]] > ran[i].second)
                 {
                     ok = false;
                     break;
                 }
             }
 
             if (!ok)
             {
                 ++it;
                 continue;
             }
 
             for (int i = 0; i < n; ++i)
                 ++ind[i];
 
             ++res;
         }
 
 		fout << "Case #" << _n << ": ";
         fout << res;
 		fout << endl;
 	}	
 
 	return 0;
 }
