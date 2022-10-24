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
 #include <hash_set>
 
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
 
 int gnCase;
 char gStr[1024];
 ifstream gIn; ofstream gOut;
 string ReadToEndLine() { string sLine; getline(gIn, sLine); return sLine; }
 // sprintf_s(gStr, "%d", );
 
 int64 pack(int64 n, int64 m)
 {
 	int64 nRes = (n << 32) | m;
 	return nRes;
 }
 
 void unwind(int n, deque<int>& q)
 {
 	while(n>0)
 	{
 		q.push_front(n%10);
 		n /= 10;
 	}
 }
 
 int wind(const deque<int>& q)
 {
 	int nRes = 0, nDigit = 1;
 	for(deque<int>::const_reverse_iterator pIter = q.rbegin(); pIter != q.rend(); ++pIter)
 	{
 		nRes += *pIter * nDigit;
 		nDigit *= 10;
 	}
 	return nRes;
 }
 
 void run()
 {
 	int A, B;
 	gIn >> A >> B;
 
 	hash_set<int64> H;
 	FORD(n, A, B)
 	{
 		deque<int> q;
 		unwind(n, q);
 
 		int N = SIZE(q);
 		FORD(i, 1, N)
 		{
 			rotate(q.begin(), q.begin()+1, q.end());
 			int m = wind(q);
 
 			if(n == m)
 				continue;
 			if(m < A || m > B)
 				continue;
 
 			int64 nVal;
 			if(n < m)
 				nVal = pack(n, m);
 			else
 				nVal = pack(m, n);
 			H.insert(nVal);
 		}
 	}
 
   gOut << "Case #" << gnCase << ": ";
   gOut << H.size();
   gOut << endl;
 }
 
 void main(int argc, char *argv[])
 {
   string sFile(argv[1]);
   gIn.open(sFile.c_str());
   sFile.resize(SIZE(sFile)-2);
   sFile += "out";
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
