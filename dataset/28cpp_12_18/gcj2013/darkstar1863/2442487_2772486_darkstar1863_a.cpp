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
 
 using namespace std;
 
 #define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
 #define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
 #define MP(X,Y) make_pair(X,Y)//NOTES:MP(
 #define FORD(i, a, b) for(int i=(a); i<(b); i++)
 #define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
 typedef long long int64;//NOTES:int64
 typedef unsigned long long uint64;//NOTES:uint64
 #define two(X) (1<<(X))//NOTES:two(
 #define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
 #define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
 #define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
 const double pi=acos(-1.0);//NOTES:pi
 const double eps=1e-11;//NOTES:eps
 template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
 typedef pair<int,int> ipair;//NOTES:ipair
 template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
 template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
 
 template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
 template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
 template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
 template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }
 
 int gnCase;
 char gStr[1024];
 ifstream gIn; ofstream gOut;
 string ReadToEndLine() { string sLine; getline(gIn, sLine); return sLine; }
 // sprintf_s(gStr, "%d", );
 
 int64 norm(int64 n)
 {
 	return n % 1000002013;
 }
 
 int64 price(int64 o, int64 e, int64 p, int64 N)
 {
 	int64 delta = e-o;
 	return norm( norm( (norm(2*N) - (delta - 1)) * delta / 2 ) * p );
 }
 
 void run()
 {
 	int64 N, M;
 	gIn >> N >> M;
 
 	int64 total = 0, res = 0;
 	set<int64> S;
 	map<int64, int64> O, E;
 	FORD(i, 0, M)
 	{
 		int64 o, e, p;
 		gIn >> o >> e >> p;
 
 		total = norm(total + price(o, e, p, N));
 		S.insert(o);
 		S.insert(e);
 		O[o] += p;
 		E[e] += p;
 	}
 
 	vector<pair<int64, int64>> C;
 	for(set<int64>::iterator iter=S.begin(); iter != S.end(); ++iter)
 	{
 		int64 station = *iter;
 		if(O.find(station) != O.end())
 			C.push_back(MP(station, O[station]));
 
 		if(E.find(station) != E.end())
 		{
 			int64 pass = E[station];
 			while(pass > 0)
 			{
 				size_t i = C.size()-1;
 				int64 toExit = min(pass, C[i].second);
 				res = norm(res + price(C[i].first, station, toExit, N));
 
 				int64 rest = C[i].second - toExit;
 				if(rest == 0)
 				{
 					C.pop_back();
 				}
 				else
 				{
 					C[i].second = rest;
 				}
 
 				pass -= toExit;
 			}
 		}
 	}
 
 	if(total < res)
 		total += 1000002013;
 
     gOut << "Case #" << gnCase << ": ";
     gOut << total - res;
     gOut << endl;
 }
 
 void main(int argc, char *argv[])
 {
     string sFile(__FILE__);
     sFile.resize(SIZE(sFile)-4);
 	sFile += "-test.in";
 	if(argc >= 2)
 	{
 		sFile = argv[1];
 	}
     gIn.open(sFile.c_str());
 
     sFile += ".out";
     gOut.open(sFile.c_str());
 
     int CASES;
     gIn >> CASES;
     ReadToEndLine();
     FORD(i, 0, CASES)
     {
         gnCase=i+1;
         run();
     }
 
     if(gOut.tellp() < 1000)
     {
         gOut.close();
         ifstream fOut(sFile.c_str());
         cout << fOut.rdbuf();
     }
     cout << "Ok" << endl;
     getchar();
 }
