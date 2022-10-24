// topcoder.cpp : R\[ AvP[ṼGg |Cg`܂B
 //
 
 #include <stdio.h>
 #include <tchar.h>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cfloat>
 #include <map>
 #include <utility>
 #include <set>
 #include <iostream>
 #include <memory>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <functional>
 #include <sstream>
 #include <complex>
 #include <stack>
 #include <queue>
 using namespace std;
 static const double EPS = 1e-9;
 int ROUND(double x) { return (int)(x+0.5); }
 bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
 bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
 double SQSUM(double x,double y) { return x*x+y*y; }
 template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
 #define PI	(3.14159265358979323846)
 #define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
 #define NG (-1)
 #define BIG (987654321)
 #define SZ(a) ((int)a.size())
 typedef long long ll;
 
 #define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
 // BEGIN CUT HERE
 #undef FOR
 #define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
 // END CUT HERE
 
 
 int main(){
 
     freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	string a =	"ejp mysljylc kd kxveddknmc re jsicpdrysi"
 				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
 				"de kr kd eoya kw aej tysr re ujdr lkgc jv qz";
 
 	string b  = "our language is impossible to understand"
 				"there are twenty six factorial possibilities"
 				"so it is okay if you want to just give up zq";
 
 	map <char, char> mp;
 	for (int i = 0; i < SZ(a); i++)
 	{
 		mp[a[i]] = b[i];
 	}
 
 	char str[10000];
 	gets(str);
 	int T;
 	T = atoi(str);
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		gets(str);
 		string s(str);
 		for (int k = 0; k < SZ(s); k++)
 		{
 			s[k]=mp[s[k]];
 		}
 
 		printf("Case #%d: %s\n",testcase+1,s.c_str());
 	}
 
 
 
 	return 0;
 }