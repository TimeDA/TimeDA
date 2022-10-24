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
 
 
 #if 1
 int main(){
 
     freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int A,B;
 		cin >> A >> B;
 		ll ret = 0;
 		for (int n = A; n <= B; n++)
 		{
 			stringstream ss;
 			string s;
 			ss << n;
 			ss >> s;
 
 			set < int > st;
 			for (int k = 0; k < SZ(s); k++)
 			{
 				rotate(s.begin(),s.begin()+1,s.end());
 				int m = atoi(s.c_str());
 				if(n<m && m<=B)
 				{
 					st.insert(m);
 				}
 			}
 			ret += SZ(st);
 		}
 		printf("Case #%d: %d\n",testcase+1,ret);
 	}
 }
 
 
 
 #elif 1
 int main(){
 
     freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int N, S, p;
 		cin >> N >> S >> p;
 		vector <int> t(N);
 
 		for (int i = 0; i < N; i++)
 		{
 			cin >> t[i];
 		}
 
 		sort(t.begin(),t.end());
 
 		int b1 = 3*p-2;
 		int b2 = 3*p-4;
 		if(p==1)
 		{
 			b1 = 1;
 			b2 = 1;
 		}
 		else if (p==0)
 		{
 			b1 = 0;
 			b2 = 0;
 		}
 
 		int b1_ijyou = t.end()-lower_bound(t.begin(),t.end(),b1);
 		int b2_b1    = upper_bound(t.begin(),t.end(),b1)-lower_bound(t.begin(),t.end(),b2);
 		int ans = b1_ijyou + min(b2_b1,S);
 
 		printf("Case #%d: %d\n",testcase+1,ans);
 	}
 }
 
 
 #else
 
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
 
 #endif