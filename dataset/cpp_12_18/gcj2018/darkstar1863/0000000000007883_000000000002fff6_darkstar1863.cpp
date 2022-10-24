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
	void Run();
	void RunTest();
	istream& mIn; ostream& mOut;
	size_t mCase;
};

void Runner::Run()
{
    size_t caseCount;
    mIn >> caseCount;
    ReadToEndLine(mIn);
    for(size_t c=0; c<caseCount; ++c)
    {
        mCase = c + 1;
#ifdef LOCAL
		cerr << "Case " << mCase << ": ... ";
#endif
        RunTest();
#ifdef LOCAL
		cerr << "done" << endl;
#endif
    }
}

struct Cashier
{
	ll MaxBits;
	ll EachTime;
	ll PayTime;
};

ll check(const vector<Cashier> &Cash, ll time, int R)
{
	vector<ll> processed;
	FORS(i, Cash)
	{
		ll timeLeft = time - Cash[i].PayTime;
		if (timeLeft < 0)
			continue;

		processed.push_back(min(timeLeft / Cash[i].EachTime, Cash[i].MaxBits));
	}

	sort(processed.begin(), processed.end(), greater<ll>());

	ll ret = 0;
	FORS(i, processed)
	{
		if (i >= R)
			break;
		ret += processed[i];
	}

	return ret;
}

void Runner::RunTest()
{
	int R, C;
	ll B;
	mIn >> R >> B >> C;

	ll maxTime = 0;
	vector<Cashier> Cash(C);
	FORS(i, Cash)
	{
		Cashier c;
		mIn >> c.MaxBits >> c.EachTime >> c.PayTime;
		Cash[i] = c;

		maxTime = max(maxTime, c.MaxBits * c.EachTime + c.PayTime);
	}
	maxTime += 10;
	R = min(R, C);

	ll l = 0, r = maxTime;
	while (l<=r)
	{
		ll m = l + (r - l) / 2;

		ll processed = check(Cash, m, R);
		if (processed >= B)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	mOut << "Case #" << mCase << ": ";
	mOut << l;
	mOut << endl;
}



#ifndef LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	Runner runner(cin, cout);
	runner.Run();
	return 0;
}
#else // Local testing. Nothing solution related
string pathToCpp = __FILE__;
#include "local_IO.cpp"
void main(int argc, char *argv[])
{
	main_1to1(argc, argv);
}
#endif
