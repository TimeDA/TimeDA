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
 
 int minGaps(const vector<int> &G, int F)
 {
 	int save = 0;
 	FORS(i, G)
 	{
 		if (G[i] <= F)
 		{
 			F -= G[i];
 			++save;
 		}
 	}
 
 	return SIZE(G) - save;
 }
 
 void Runner::Run()
 {
 	int C, J;
 	mIn >> C >> J;
 
 	int FreeC = 720, FreeJ = 720;
 	vector<pair<pair<int, int>, bool>> A; // Start, End, isCameron
 	FORD(i, 0, C)
 	{
 		int s, e;
 		mIn >> s >> e;
 		A.push_back(MP(MP(s, e), true));
 
 		int len = e - s;
 		FreeC -= len;
 	}
 	FORD(i, 0, J)
 	{
 		int s, e;
 		mIn >> s >> e;
 		A.push_back(MP(MP(s, e), false));
 
 		int len = e - s;
 		FreeJ -= len;
 	}
 	sort(A.begin(), A.end());
 
 	const int DAY = 24 * 60;
 	vector<int> Gdif, Gcam, Gjan; // len
 	FORD(i, 0, SIZE(A))
 	{
 		int nextI = i + 1;
 		if (nextI >= SIZE(A))
 			nextI = 0;
 
 		int s = A[i].first.second;
 		int e = A[nextI].first.first;
 		if(e < s)
 			e+=DAY;
 		int len = e - s;
 
 		bool isSame = (A[i].second == A[nextI].second);
 		if (!isSame)
 			Gdif.push_back(len);
 		else if (A[i].second)
 			Gcam.push_back(len);
 		else
 			Gjan.push_back(len);
 	}
 	sort(Gcam.begin(), Gcam.end());
 	sort(Gjan.begin(), Gjan.end());
 
 	int restC = minGaps(Gcam, FreeC);
 	int restJ = minGaps(Gjan, FreeJ);
 
 	int res = SIZE(Gdif) + 2 * restC + 2 * restJ;
 
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
