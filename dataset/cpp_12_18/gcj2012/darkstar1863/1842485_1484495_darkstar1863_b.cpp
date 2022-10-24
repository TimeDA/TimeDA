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
 
 int DIR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 int CR[3][2] = {{1, 0}, {1, 1}, {0, 1}};
 
 void run()
 {
 	int N, W, H;
 	gIn >> N >> W >> H;
 	vector<int> R(N);
 	FORS(i, R)
 	{
 		gIn >> R[i];
 	}
 
 	sort(R.begin(), R.end(), greater<int>());
 
 	vector<pair<int, int>> Res(N);
 	int w=0, h=0;
 	int d = 0;
 	FORS(i, R)
 	{
 		if(i==0)
 		{
 			Res[i] = MP(w, h);
 			continue;
 		}
 
 		l1:
 		int curMove = R[i-1] + R[i]; 
 		int curW = w + curMove*DIR[d][0];
 		int curH = h + curMove*DIR[d][1];
 
 		if(curW < 0 || curW > W || curH < 0 || curH > H)
 		{
 			w = W * CR[d][0];
 			h = H * CR[d][1];
 			++d;
 			goto l1;
 		}
 		else
 		{
 			w = curW;
 			h = curH;
 			Res[i] = MP(w, h);
 		}
 	}
 
   gOut << "Case #" << gnCase << ":";
   FORS(i, Res)
   {
 	  gOut << " " << Res[i].first << " " << Res[i].second;
   }
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
