#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <string>
 #include <cstring>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <fstream>
 #include <limits>
 using namespace std;
 
 // Types
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<int,int> ipair;
 const double pi=acos(-1.0);
 const double eps=1e-11;
 const ll MOD = 1000000007;
 
 // Generic
 #define SIZE(X) ((int)(X.size()))
 #define LENGTH(X) ((int)(X.length()))
 #define MP(X,Y) make_pair(X,Y)
 #define FORD(i, a, b) for(int i=(a); i<(b); i++)
 #define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
 #define two(X) (1<<(X))
 #define twoL(X) (((ll)(1))<<(X))
 template<class T> inline T sqr(T x){return x*x;}
 
 // Bit manipulation
 template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
 template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
 template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
 template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }
 template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
 
 // Input / Output
 string ReadToEndLine(istream& s) { string sLine; getline(s, sLine); return sLine; }
 char gStr[1024];
 // sprintf_s(gStr, "%d", );
 
 struct Runner
 {
 	Runner(istream& in, ostream& out) : mIn(in), mOut(out), mCase(0) {}
 	void RunAll();
 	void Run();
 	istream& mIn; ostream& mOut;
 	size_t mCase;
 };
 
 void Runner::RunAll()
 {
     size_t caseCount;
     mIn >> caseCount;
     ReadToEndLine(mIn);
     for(size_t c=0; c<caseCount; ++c)
     {
         mCase = c + 1;
 		cout << "Case " << mCase << ": ... ";
         Run();
 		cout << "done" << endl;
     }
 }
 
 
 bool canDo(ll r, ll p, ll cnt)
 {
 	if (cnt == 0)
 		return false;
 
 	ll need = r*cnt;
 	//ll minN = need * 90 / 100;
 	//ll maxN = need * 110 / 100;
 	double minN = (double)need * 90 / 100;
 	double maxN = (double)need * 110 / 100;
 
 	return (minN <= (double)p && (double)p <= maxN);
 }
 
 /*
 bool canDo(ll r1, ll r2, ll p1, ll p2)
 {
 	ll cnt = p1 / r1;
 	return (canDo(r1, p1, cnt) && canDo(r2, p2, cnt)) || (canDo(r1, p1, cnt + 1) && canDo(r2, p2, cnt + 1)) || (canDo(r1, p1, cnt - 1) && canDo(r2, p2, cnt - 1));
 }
 
 bool canDo(ll r, ll p)
 {
 	ll cnt = p / r;
 	return canDo(r, p, cnt) || canDo(r, p, cnt + 1) || canDo(r, p, cnt - 1);
 }
 */
 
 pair<ll, ll> ran(ll r, ll p)
 {
 	double cntMin = (double)p / (double)r / 1.1;
 	double cntMax = (double)p / (double)r / 0.9;
 
 	ll cntL = (ll)cntMin;
 	if (!canDo(r, p, cntL))
 		++cntL;
 
 	ll cntR = (ll)cntMax;
 	if (canDo(r, p, cntR + 1))
 		++cntR;
 
 	return MP(cntL, cntR);
 }
 
 bool canDo(ll r1, ll r2, ll p1, ll p2)
 {
 	auto rng1 = ran(r1, p1);
 	auto rng2 = ran(r2, p2);
 	if (rng1.first > rng1.second || rng2.first > rng2.second)
 		return false;
 
 	if (rng1.first > rng2.first)
 		swap(rng1, rng2);
 
 	return rng2.first <= rng1.second;
 }
 
 bool canDo(ll r, ll p)
 {
 	FORD(cnt, 1, 1000005)
 	{
 		if (canDo(r, p, cnt))
 			return true;
 	}
 
 	return false;
 }
 
 void Runner::Run()
 {
 	int N, P;
 	mIn >> N >> P;
 
 	vector<ll> R(N);
 	FORS(i, R)
 	{
 		mIn >> R[i];
 		//R[i] *= 100;
 	}
 
 	vector<vector<ll>> Q(N, vector<ll>(P));
 	FORS(i, Q)
 	{
 		FORS(j, Q[i])
 		{
 			mIn >> Q[i][j];
 			//Q[i][j] *= 100;
 		}
 	}
 
 	int res = 0;
 
 	if (N == 1)
 	{
 		FORD(p, 0, P)
 			if (canDo(R[0], Q[0][p]))
 				++res;
 	}
 	else if (N == 2)
 	{
 		vector<int> S(P);
 		FORS(i, S)
 			S[i] = i;
 
 		do
 		{
 			int cur = 0;
 			FORD(p, 0, P)
 			{
 				if (canDo(R[0], R[1], Q[0][p], Q[1][S[p]]))
 					++cur;
 			}
 
 			res = max(res, cur);
 
 		} while (next_permutation(S.begin(), S.end()));
 	}
 	else
 	{
 		//throw std::exception();
 	}
 
 	mOut << "Case #" << mCase << ": ";
 	mOut << res;
 	mOut << endl;
 }
 
 
 string pathToCpp = __FILE__;
 #ifdef LOCAL
 #include "local_IO.cpp"
 #endif
 
 void main(int argc, char *argv[])
 {
 	string pathToFiles = pathToCpp;
 	pathToFiles.resize(pathToFiles.size() - 4);
 	string pathToInput = pathToFiles + ".in.txt";
 	if(argc >= 2)
 	{
 		pathToFiles = pathToInput = argv[1];
 	}
 
 	{
 		ifstream sIn(pathToInput);
 		ofstream sMy(pathToFiles + ".my.txt");
 		Runner runner(sIn, sMy);
 		runner.RunAll();
 	}
 
 #ifdef LOCAL
 	check_Nto1(pathToFiles + ".ok.txt", pathToFiles + ".my.txt");
 #endif
 
 	getchar();
 }
