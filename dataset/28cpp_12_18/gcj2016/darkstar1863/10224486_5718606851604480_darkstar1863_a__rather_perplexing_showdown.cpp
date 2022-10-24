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
 
 bool iter(const string &str)
 {
 	if (str.size() == 1)
 		return true;
 
 	string n;
 	for (int i = 0; i < SIZE(str); i += 2)
 	{
 		vector<char> C(2);
 		C[0] = str[i];
 		C[1] = str[i + 1];
 		sort(C.begin(), C.end());
 		if (C[0] == C[1])
 			return false;
 		if (C[0] == 'P' && C[1] == 'R')
 			n += "P";
 		else if (C[0] == 'P' && C[1] == 'S')
 			n += "S";
 		else if (C[0] == 'R' && C[1] == 'S')
 			n += "R";
 		else
 			throw exception();
 	}
 
 	return iter(n);
 }
 
 string solve(int R, int P, int S)
 {
 	string str;
 	FORD(i, 0, P)
 		str += "P";
 	FORD(i, 0, R)
 		str += "R";
 	FORD(i, 0, S)
 		str += "S";
 
 	do
 	{
 		if (iter(str))
 			return str;
 	} while (next_permutation(str.begin(), str.end()));
 
 	return string();
 }
 
 void Runner::Run()
 {
 	int N, R, P, S;
 	mIn >> N >> R >> P >> S;
 
 	string RRR = solve(R, P, S);
 	mOut << "Case #" << mCase << ": " << (RRR.size() > 0 ? RRR.c_str() : "IMPOSSIBLE") << endl;
 	return;
 	
 
 	int T = P + R + S;
 	if (P > T / 2 || R > T / 2 || S > T / 2)
 	{
 		mOut << "Case #" << mCase << ": " << "IMPOSSIBLE" << endl;
 		return;
 	}
 
 	if (N == 1)
 	{
 		string res;
 		if (P > 0)
 			res += "P";
 		if (R > 0)
 			res += "R";
 		if (S > 0)
 			res += "S";
 		mOut << "Case #" << mCase << ": " << (res.size() == 2 ? res.c_str() : "IMPOSSIBLE") << endl;
 		return;
 	}
 
 	string RR = "Z";
 	FORD(pr, 0, min(P, R) + 1)
 	{
 		int PR = pr;
 		int curP = P - PR;
 		int curR = R - PR;
 		int curS = S;
 		int PS = curP;
 		int RS = curR;
 
 		if ((PR + PS + RS) * 2 != T)
 			continue;
 
 		int maxP = max(PR, max(PS, RS));
 		int minP = min(PR, min(PS, RS));
 		if (abs(maxP - minP) > 1)
 			continue;
 
 		string res;
 		FORD(i, 0, maxP)
 		{
 			if (PR > 0 && PS > 0)
 			{
 				res += "PRPS";
 				--PR; --PS;
 			}
 			if (PR > 0 && RS > 0)
 			{
 				res += "PRRS";
 				--PR; --RS;
 			}
 			if (PS > 0 && RS > 0)
 			{
 				res += "PSRS";
 				--PS; --RS;
 			}
 		}
 
 		RR = min(RR, res);
 	}
 
 	if (RR != "Z")
 	{
 		mOut << "Case #" << mCase << ": " << RR << endl;
 		return;
 	}
 
 	mOut << "Case #" << mCase << ": ";
 	mOut << "IMPOSSIBLE";
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
