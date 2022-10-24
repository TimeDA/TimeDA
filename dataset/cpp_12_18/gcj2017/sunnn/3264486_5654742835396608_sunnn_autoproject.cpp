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
 
 inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
 template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
 template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }
 
 #define inf 2100000000
 #define eps 1e-9
 
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
 
 		ll n = t[0], k = t[1];
 
 		priority_queue<pii> pq;
 		pq.push(pii(n, 1));
 
 		ll cnt = 0;
 		while (true)
 		{
 			pii x = pq.top();
 			pq.pop();
 
 			cnt += x.second;
 
 			if (cnt >= k)
 			{
 				fout << "Case #" << _n << ": ";
 				fout << x.first / 2 << ' ' << (x.first - 1) / 2;
 				fout << endl;
 				break;
 			}
 
 			if (x.first % 2 == 0)
 			{
 				pq.push(pii((x.first - 1) / 2, x.second));
 				pq.push(pii(x.first / 2, x.second));
 			}
 			else
 			{
 				pq.push(pii((x.first - 1) / 2, 2 * x.second));
 			}
 		}
 	}	
 
 	return 0;
 }
