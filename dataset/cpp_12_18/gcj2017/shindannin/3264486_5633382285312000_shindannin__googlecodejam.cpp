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
 
 #if 1
 
 bool isValid(ll x)
 {
 	int right = 10;
 	while (x)
 	{
 		const int left = x%10;
 		if(left>right) return false;
 		right = left;
 		x /= 10;
 	}
 
 	return true;
 }
 
 int main() {
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		ll x;
 		cin >> x;
 		string s = to_string(x);
 
 		ll ans = 0;
 		if (isValid(x))
 		{
 			amax(ans,x);
 		}
 
 		const int N = SZ(s);
 		for (int i = 0; i < N; ++i)
 		{
 
 			const int keta = N-1-i;
 			ll ten = 1;
 			for (int k = 0; k < keta; ++k)
 			{
 				ten *= 10LL;
 			}
 
 			ll tmp = (x / ten - 1) * ten + (ten - 1);
 
 			if (isValid(tmp))
 			{
 				amax(ans, tmp);
 			}
 		}
 
 
 		PRINTF("Case #%d: %lld\n", testcase + 1, ans);
 	}
 
 	return 0;
 }
 
 #else
 
 int main() {
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		string s;
 		int K;
 		cin >> s >> K;
 
 		int ans = 0;
 		for (int i=0;i<=SZ(s)-K;++i)
 		{
 			if (s[i] == '-')
 			{
 				ans++;
 				for (int k = 0; k < K; ++k)
 				{
 					if (s[i+k] == '-')
 					{
 						s[i+k] = '+';
 					}
 					else
 					{
 						s[i + k] = '-';
 					}
 				}
 			}
 		}
 
 		bool ok = true;
 		for (int i = 0; i < SZ(s); i++)
 		{
 			if (s[i] == '-')
 			{
 				ok = false;
 			}
 		}
 
 		if (ok)
 		{
 			PRINTF("Case #%d: %d\n", testcase + 1, ans);
 		}
 		else
 		{
 			PRINTF("Case #%d: IMPOSSIBLE\n", testcase + 1);
 		}
 	}
 
 	return 0;
 }
 
 #endif