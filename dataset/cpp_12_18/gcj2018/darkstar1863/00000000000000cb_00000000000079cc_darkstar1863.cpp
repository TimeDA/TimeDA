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

void rotate_p(double &x, double &y, double angle)
{
	double s = sin(angle);
	double c = cos(angle);

	// rotate point
	double xnew = x * c - y * s;
	double ynew = x * s + y * c;

	x = xnew;
	y = ynew;
}

void Runner::RunTest()
{
	double A;
	mIn >> A;

	double angle = acos(A / sqrt(2.));
	double aDig = angle * 180 / pi;

	double angle2 = angle + pi / 4.;
	double aDig2 = angle2 * 180 / pi;

	double x1 = 0.5, y1 = 0, x2 = 0, y2 = 0.5;
	rotate_p(x1, y1, angle2);
	rotate_p(x2, y2, angle2);


	mOut << "Case #" << mCase << ": " << endl;
	mOut << fixed << setprecision(16) << x1 << " " << fixed << setprecision(16) << y1 << " 0" << endl;
	mOut << fixed << setprecision(16) << x2 << " " << fixed << setprecision(16) << y2 << " 0" << endl;
	mOut << "0 0 0.5" << endl;
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
