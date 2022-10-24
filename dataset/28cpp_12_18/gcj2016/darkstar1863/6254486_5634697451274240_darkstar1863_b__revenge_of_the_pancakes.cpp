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
 
 int solve(string &str)
 {
 	if(str.size() == 1)
 	{
 		return (str[0] == '-') ? 1 : 0;
 	}
 
 	if(str.back() == '+')
 	{
 		str.pop_back();
 		return solve(str);
 	}
 
 	if(str.front() == '-')
 	{
 		FORS(i, str)
 			str[i] = (str[i] == '+') ? '-' : '+';
 		reverse(str.begin(), str.end());
 	}
 	else
 	{
 		str[0] = '-';
 	}
 	return 1 + solve(str);
 }
 
 void Runner::Run()
 {
 	string str;
 	mIn >> str;
 
 	string cond;
 	cond += str[0];
 	FORD(i, 1, SIZE(str))
 	{
 		if(str[i] != cond.back())
 			cond += str[i];
 	}
 
 	int res = solve(cond);
 
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
