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

void Runner::RunTest()
{
	int R, C, H, V;
	mIn >> R >> C >> H >> V;
	vector<string> M(R);
	FORS(i, M)
		mIn >> M[i];

	int totalChips = 0;
	FORS(i, M)
		totalChips += count(M[i].begin(), M[i].end(), '@');

	int totalPieces = (H + 1) * (V + 1);

	if (totalChips % totalPieces != 0)
	{
		mOut << "Case #" << mCase << ": IMPOSSIBLE" << endl;
		return;
	}

	int inOne = totalChips / totalPieces;
	int inOneRow = inOne * (V + 1);
	int inOneCol = inOne * (H + 1);

	int cnt = 0;
	vector<int> rowCuts;
	FORS(r, M)
	{
		cnt += count(M[r].begin(), M[r].end(), '@');
		if (cnt > inOneRow)
		{
			mOut << "Case #" << mCase << ": IMPOSSIBLE" << endl;
			return;
		}
		if (cnt == inOneRow)
		{
			cnt = 0;
			rowCuts.push_back(r);
		}
	}

	cnt = 0;
	vector<int> colCuts;
	FORD(c, 0, C)
	{
		FORD(r, 0, R)
			cnt += M[r][c] == '@' ? 1 : 0;

		if (cnt > inOneCol)
		{
			mOut << "Case #" << mCase << ": IMPOSSIBLE" << endl;
			return;
		}
		if (cnt == inOneCol)
		{
			cnt = 0;
			colCuts.push_back(c);
		}
	}

	// check
	int lastRow = 0;
	FORS(rc, rowCuts)
	{
		int lastCol=0;
		FORS(cc, colCuts)
		{
			int cnt = 0;
			FORD(r, lastRow, rowCuts[rc] + 1)
			{
				FORD(c, lastCol, colCuts[cc] + 1)
				{
					cnt += M[r][c] == '@' ? 1 : 0;
				}
			}

			if(cnt != inOne)
			{
				mOut << "Case #" << mCase << ": IMPOSSIBLE" << endl;
				return;
			}

			lastCol = colCuts[cc] + 1;
		}

		lastRow = rowCuts[rc] + 1;
	}

	mOut << "Case #" << mCase << ": POSSIBLE" << endl;
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
