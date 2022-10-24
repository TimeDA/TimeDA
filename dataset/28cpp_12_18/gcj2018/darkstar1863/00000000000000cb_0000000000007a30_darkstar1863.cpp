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
	bool RunTest();
	istream& mIn; ostream& mOut;
	size_t mCase;
};

void Runner::Run()
{
    size_t caseCount;
    mIn >> caseCount;
//    ReadToEndLine(mIn);
    for(size_t c=0; c<caseCount; ++c)
    {
        mCase = c + 1;
		if (!RunTest())
		{
			return;
		}

    }
}

int calcFree(const vector<vector<bool>> &M, int r, int c)
{
	int ret = 9;
	if (M[r-1][c-1]) --ret;
	if (M[r-1][c]) --ret;
	if (M[r-1][c+1]) --ret;
	if (M[r][c-1]) --ret;
	if (M[r][c]) --ret;
	if (M[r][c+1]) --ret;
	if (M[r+1][c-1]) --ret;
	if (M[r+1][c]) --ret;
	if (M[r+1][c+1]) --ret;

	return ret;
}

bool Runner::RunTest()
{
	int A;
	mIn >> A;

	int R = 3, C = 3;
	while (R*C < A)
	{
		if (R == C)
			++R;
		else
			++C;
	}

	vector<vector<bool>> M(R, vector<bool>(C, false));
	while (true)
	{
		// Find the best spot
		int maxR = 0, maxC = 0, maxFree = 0;
		FORD(r, 1, R - 1)
		{
			FORD(c, 1, C - 1)
			{
				int curFree = calcFree(M, r, c);
				if (curFree > maxFree)
				{
					maxR = r;
					maxC = c;
					maxFree = curFree;
				}
			}
		}

		// Send request
		mOut << maxR + 1 << " " << maxC + 1 << endl;

		// Recive respond
		int actR, actC;
		mIn >> actR >> actC;

		if (actR == 0 && actC == 0)
			return true;
		if (actR == -1 && actC == -1)
			return false;

		--actR;
		--actC;
		M[actR][actC] = true;
	}
}


int main()
{
//	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	Runner runner(cin, cout);
	runner.Run();
	return 0;
}
