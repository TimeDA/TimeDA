// topcoder.cpp : R\[ AvP[ṼGg |Cg`܂B
 //
 
 #include <stdio.h>
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
 #include <numeric>
 #include <unordered_map>
 #include "assert.h"
 
 using namespace std;
 
 static const double EPS = 1e-9;
 template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b || b<=x&&x<=a;}
 template<class T> void amin(T &a,T v){if(a>v) a=v;}
 template<class T> void amax(T &a,T v){if(a<v) a=v;}
 int ROUND(double x) { return (int)(x+0.5); }
 bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
 bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
 
 #define PI  (acos(-1))
 #define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
 #define NG (-1)
 #define BIG ((int)1e9)
 #define BIGLL ((ll)4e18)
 #define SZ(a) ((int)(a).size())
 #define SQ(a) ((a)*(a))
 
 typedef unsigned long long ull;
 typedef long long ll;
 
 ll SQSUM(ll x,ll y) { return x*x+y*y; }
 
 #define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);
 
 // őlBv҂
 static const int MAX_p1 = 100;
 static const int MAX_p2 = 100;
 static const int MAX_p3 = 100;
 
 int P;
 int mMemo[MAX_p1 + 1][MAX_p2 + 1][MAX_p3 + 1];
 
 struct Tri
 {
 	int d1;
 	int d2;
 	int d3;
 };
 
 vector <Tri> vtri;
 
 
 int dfs(int p1, int p2, int p3)
 {
 	int& memo = mMemo[p1][p2][p3];
 
 	if (memo != NG)
 	{
 		return memo;
 	}
 
 	int ret = 1;
 	if (p1 == 0 && p2 == 0 && p3 == 0)
 	{
 		ret = 0;
 	}
 
 	switch(P)
 	{
 	case 2:
 		if (p1 >= 2)
 		{
 			amax(ret, dfs(p1 - 2, p2, p3) + 1);
 		}
 		if (p2 >= 1)
 		{
 			amax(ret, dfs(p1, p2-1, p3) + 1);
 		}
 		break;
 
 	case 3:
 		if (p1 >= 3)
 		{
 			amax(ret, dfs(p1 - 3, p2 , p3) + 1);
 		}
 		if (p1 >= 1 && p2 >= 1)
 		{
 			amax(ret, dfs(p1 - 1, p2 - 1, p3) + 1);
 		}
 		if (p2 >= 3)
 		{
 			amax(ret, dfs(p1, p2 - 3, p3) + 1);
 		}
 		if (p1 >= 2 && p2 >= 2)
 		{
 			amax(ret, dfs(p1 - 2, p2 - 2, p3) + 1);
 		}
 		break;
 
 	case 4:
 
 		for (const Tri& t : vtri)
 		{
 			if (p1 >= t.d1 && p2 >= t.d2 && p3 >= t.d3)
 			{
 				amax(ret, dfs(p1 - t.d1, p2 - t.d2, p3- t.d3) + 1);
 			}
 		}
 		break;
 	}
 
 	// BEGIN CUT HERE
 //	cout << " p1=" << p1 << " p2=" << p2 << " p3=" << p3 << " ret=" << ret << endl;
 	// END CUT HERE
 
 	return memo = ret;
 }
 
 
 int main() {
 
 	for (int d1=0;d1<=16;d1++)
 	{
 		for (int d2 = 0; d2 <= 16; d2++)
 		{
 			for (int d3 = 0; d3 <= 16; d3++)
 			{
 				int sum = d1 + 2*d2 + 3*d3;
 				if (sum % 4 == 0 && INRANGE(sum, 1, 16))
 				{
 					Tri t;
 					t.d1 = d1;
 					t.d2 = d2;
 					t.d3 = d3;
 					vtri.push_back(t);
 				}
 			}
 		}
 	}
 
 
 
 
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		int N;
 		cin >> N >> P;
 
 		int num[4]={};
 		for (int i = 0; i < N; ++i)
 		{
 			int g;
 			cin >> g;
 			num[g%P]++;
 		}
 
 
 
 
 
 		for (int p1 = 0; p1 <= MAX_p1; p1++)
 		{
 			for (int p2 = 0; p2 <= MAX_p2; p2++)
 			{
 				for (int p3 = 0; p3 <= MAX_p3; p3++)
 				{
 					mMemo[p1][p2][p3] = NG;
 				}
 			}
 		}
 
 		int ans = dfs(num[1],num[2],num[3]) + num[0];
 		PRINTF("Case #%d: %d\n", testcase + 1, ans);
 
 	}
 
 	return 0;
 }
