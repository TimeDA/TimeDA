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
 /*
 bool check(int n)
 {
 	char buff[100];
 	_itoa_s(n, buff, 10);
 
 	char *cur = buff;
 	char last = *cur;
 	++cur;
 	while (*cur != '\0')
 	{
 		if (*cur < last)
 			return false;
 		last = *cur;
 		++cur;
 	}
 
 	return true;
 }
 */
 
 void Runner::Run()
 {
 	//////////////////////////////////////////////////////////
 	/*
 	ll N;
 	mIn >> N;
 
 	ll res = N;
 	while (!check((int)res))
 	{
 		--res;
 	}
 	*/
 	//////////////////////////////////////////////////////////
 
 	string N;
 	mIn >> N;
 
 	int firstBad = 0;
 	FORD(i, 1, SIZE(N))
 	{
 		if (N[i] < N[i - 1])
 		{
 			firstBad = i;
 			FORD(k, i, SIZE(N))
 				N[k] = '9';
 		}
 	}
 
 	if (firstBad > 0)
 	{
 		for (int i = firstBad - 1; i >= 0; --i)
 		{
 			if (N[i] == '1')
 			{
 				if (i == 0)
 				{
 					N.erase(N.begin());
 					break;
 				}
 				else
 				{
 					N[i] = '9';
 				}
 			}
 			else
 			{
 				--N[i];
 
 				if (i == 0 || N[i] >= N[i - 1])
 					break;
 				else
 					N[i] = '9';
 			}
 		}
 	}
 
 	mOut << "Case #" << mCase << ": ";
 	mOut << N;
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
