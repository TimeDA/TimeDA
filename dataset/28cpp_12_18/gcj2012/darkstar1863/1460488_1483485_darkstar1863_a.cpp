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
 
 int gnCase;
 char gStr[1024];
 ifstream gIn; ofstream gOut;
 string ReadToEndLine() { string sLine; getline(gIn, sLine); return sLine; }
 // sprintf_s(gStr, "%d", );
 
 void run()
 {
 	string G("zq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv");
 	string E("qz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up");
 
 	map<char, char> M;
 	FORS(i, G)
 		M[G[i]] = E[i];
 
 	string sLine = ReadToEndLine();
 	string sRes;
 	FORS(i, sLine)
 		sRes.push_back(M[sLine[i]]);
 
   gOut << "Case #" << gnCase << ": ";
   gOut << sRes;
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
