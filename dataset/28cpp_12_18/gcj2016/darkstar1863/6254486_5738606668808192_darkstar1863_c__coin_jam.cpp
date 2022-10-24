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
 
 ll convert(int mask, int length, ll base)
 {
 	ll res = 1;
 	FORD(i, 0, length)
 	{
 		res *= base;
 		res += isbit(mask, i) ? 1 : 0;
 	}
 	res *= base;
 	res += 1;
 
 	return res;
 }
 
 bool isPrime(ll n, ll &div)
 {
 	if (n < 2) return false;
 	ll sq = ll(sqrt(n));
 	for (ll i = 2; i <= sq; i++)
 		if (!(n % i))
 		{
 			div = i;
 			return false;
 		}
 	return true;
 }
 
 bool check(int mask, int length, vector<ll> &D)
 {
 	FORD(base, 2, 11)
 	{
 		ll val = convert(mask, length, base);
 		ll div;
 		if(isPrime(val, div))
 			return false;
 		D[base-2] = div;
 	}
 
 	return true;
 }
 
 void print(ostream& mOut, int mask, int length, const vector<ll> &D)
 {
 	mOut << '1';
 	FORD(i, 0, length)
 	{
 		mOut << (isbit(mask, i) ? '1' : '0');
 	}
 	mOut << '1' << " ";
 	
 	FORS(i, D)
 		mOut << D[i] << " ";
 	mOut << endl;
 }
 
 void Runner::Run()
 {
 	int N, J;
 	mIn >> N >> J;
 
 	N-=2;
 	int maxMask = two(N);
 	vector<pair<int, vector<ll> > > R; // mask, divs
 	int found = 0;
 	vector<ll> D(9);
 	FORD(mask, 0, maxMask)
 	{
 		if(!check(mask, N, D))
 			continue;
 
 		R.push_back(MP(mask, D));
 		if(SIZE(R) == J)
 			break;
 	}
 
 	mOut << "Case #" << mCase << ":" << endl;
 	FORS(i, R)
 		print(mOut, R[i].first, N, R[i].second);
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
