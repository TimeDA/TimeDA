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
 
 int main() {
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		ll N, K;
 		cin >> N >> K;
 
 		ll pow2 = -1;
 		{
 			ll tmp = K;
 			while (tmp)
 			{
 				pow2++;
 				tmp /= 2;
 			}
 		}
 
 		const ll rem = K - (1LL << pow2);
 
 		map <ll, ll> kosu;
 
 		N++;
 
 		if(N/2>=1)
 		{
 			kosu[N / 2] += 1;
 		}
 
 		if (N / 2 + N % 2 >= 1)
 		{
 			kosu[N / 2 + N % 2] += 1;
 		}
 
 
 		for (ll i=0;i<pow2;i++)
 		{
 			for (const auto& a : kosu)
 			{
 				// BEGIN CUT HERE
 //				cerr << " a.first=" << a.first << " a.second=" << a.second << endl;
 				// END CUT HERE
 
 			}
 
 			map <ll, ll> newKosu;
 
 			for (const auto& a : kosu)
 			{
 				if(a.first / 2 >= 1)
 				{
 					newKosu[a.first / 2] += a.second;
 				}
 
 				if (a.first / 2 + a.first % 2 >= 1)
 				{
 					newKosu[a.first / 2 + a.first % 2] += a.second;
 				}
 			}
 
 			kosu = newKosu;
 		}
 
 		ll lo, hi;
 
 		ll lowValue = kosu.begin()->first;
 		ll hiValue =  kosu.rbegin()->first;
 		ll numLowValue = kosu.begin()->second;
 		ll numHiValue = kosu.rbegin()->second;
 
 		if (lowValue == hiValue)
 		{
 			lo = hi = lowValue;
 		}
 		else if (numLowValue < numHiValue)
 		{
 			if(rem >= (1LL << pow2) - numLowValue)
 			{
 				lo = lowValue;
 				hi = hiValue;
 			}
 			else
 			{
 				lo = hiValue;
 				hi = hiValue;
 
 			}
 		}
 		else
 		{
 			if (rem <= numHiValue)
 			{
 				lo = lowValue;
 				hi = hiValue;
 			}
 			else
 			{
 				lo = lowValue;
 				hi = lowValue;
 			}
 		}
 
 
 		PRINTF("Case #%d: %I64d %I64d\n", testcase + 1, hi-1, lo-1);
 	}
 }
 
 
 #elif 1
 
 
 int main() {
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 	ll testcase = 0;
 	for (ll N=4;N<=6;++N) for(ll K=1;K<=N;++K)
 	{
 		testcase++;
 
 		vector <int> a(N+2);
 		a[0]=1;
 		a[N+1]=1;
 
 		ll bestPos = NG;
 		ll bestMin = NG;
 		ll bestMax = NG;
 
 		for (ll turn=0;turn<K;++turn)
 		{
 			bestPos = NG;
 			bestMin = NG;
 			bestMax = NG;
 			for (ll pos = 0; pos < N+2; ++pos)
 			{
 				if(a[pos]!=1)
 				{
 					ll leftDist = 0;
 					ll rightDist = 0;
 					for (ll x = pos; x >= 0; x--)
 					{
 						if (a[x] == 1)
 						{
 							leftDist = pos - x;
 							break;
 						}
 					}
 
 					for (ll x = pos; x < N + 2; x++)
 					{
 						if (a[x] == 1)
 						{
 							rightDist = x - pos;
 							break;
 						}
 					}
 
 					const ll minDist = min(leftDist, rightDist);
 					const ll maxDist = max(leftDist, rightDist);
 
 					if (minDist > bestMin || minDist == bestMin && maxDist > bestMax)
 					{
 						bestMin = minDist;
 						bestMax = maxDist;
 						bestPos = pos;
 					}
 				}
 			}
 
 			a[bestPos] = 1;
 
 			if(turn==K-1)
 			{
 				for (ll pos = 0; pos < N + 2; ++pos)
 				{
 					if (pos == bestPos)
 					{
 						PRINTF("*");
 					}
 					else if (a[pos] == 1)
 					{
 						PRINTF("O");
 					}
 					else
 					{
 						PRINTF(".");
 					}
 				}
 				PRINTF(" turn=%4I64d bestMin=%4I64d bestMax=%4I64d\n", turn, bestMin, bestMax);
 			}
 		}
 
 //		PRINTF("Case #%d: %I64d %I64d\n", testcase + 1, bestMin, bestMax);
 	}
 
 
 
 	return 0;
 }
 
 
 #elif 1
 
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