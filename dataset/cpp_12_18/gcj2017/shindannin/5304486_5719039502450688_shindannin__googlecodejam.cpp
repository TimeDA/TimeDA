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
 
 int dp[2][130][130][130]; // [U][GHP][GU] = HP
 
 int main() {
 
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		int myhpINP, myatINP, ophpINP, opatINP, buff, debuff;
 		cin >> myhpINP >> myatINP >> ophpINP >> opatINP >> buff >> debuff;
 		memset(dp, -1, sizeof(dp));
 
 		int now = 0;
 		dp[now][myatINP][ophpINP][opatINP] = myhpINP;
 
 		int winTurn = NG;
 		for (int turn = 0; turn < 200; turn++)
 		{
 			const int next = 1 - now;
 			memset(dp[next], NG, sizeof(dp[0]));
 
 			const int N = 110;
 
 			for (int myat=0;myat<=N;myat++)
 			{
 				for (int ophp = 1; ophp <= N; ophp++)
 				{
 					for (int opat = 0; opat <= N; opat++)
 					{
 						const int& dnow = dp[now][myat][ophp][opat];
 						if(dnow>0)
 						{
 							// BEGIN CUT HERE
 //							cerr << " dnow=" << dnow << " myat=" << myat << " ophp=" << ophp << " opat=" << opat << endl;
 							// END CUT HERE
 
 
 
 							// Attack: Reduce the opponent's health by your own attack power.
 							amax(dp[next][myat][max(0,ophp-myat)][opat], max(0, dnow-opat));
 
 
 							// Buff : Increase your attack power by B for the rest of the battle.
 							amax(dp[next][min(100,myat+buff)][ophp][opat], max(0, dnow - opat));
 
 							// Cure : Your health becomes Hd.
 							amax(dp[next][myat][ophp][opat], max(0, myhpINP - opat));
 
 							// Debuff : Decrease the opponent's attack power by D for the rest of the battle. If a Debuff would cause the opponent's attack power to become less than 0, it instead sets it to 0.
 							amax(dp[next][myat][ophp][max(0,opat-debuff)], max(0, dnow - opat));
 						}
 					}
 				}
 			}
 
 			for (int myat = 0; myat <= N; myat++)
 			{
 				for (int opat = 0; opat <= N; opat++)
 				{
 					const int& dnext = dp[next][myat][0][opat];
 
 					if (dnext >= 0)
 					{
 						winTurn = turn + 1;
 						goto NUKE;
 					}
 				}
 			}
 			now = next;
 		}
 
 		NUKE:;
 
 		if (winTurn == NG)
 		{
 			PRINTF("Case #%d: IMPOSSIBLE\n", testcase + 1, winTurn);
 		}
 		else
 		{
 			PRINTF("Case #%d: %d\n", testcase + 1, winTurn);
 		}
 
 
 
 
 
 	}
 
 
 	return 0;
 }
 
 #elif 1
 
 
 int main() {
 
 	freopen("_google_code_jam_input.txt", "r", stdin);
 	freopen("_google_code_jam_output.txt", "w", stdout);
 
 	int T;
 	scanf("%d ", &T);
 
 
 	for (int testcase = 0; testcase < T; ++testcase)
 	{
 		int N, P;
 		cin >> N >> P;
 
 		vector <ll> unit(N);
 		for (int i = 0; i < N; ++i)
 		{
 			cin >> unit[i];
 		}
 
 		vector < vector <ll> > quantity(N, vector <ll>(P, 0));
 		for (int i = 0; i < N; ++i)
 		{
 			for (int k = 0; k < P; ++k)
 			{
 				cin >> quantity[i][k];
 			}
 
 			sort(quantity[i].begin(), quantity[i].end());
 		}
 
 
 		ll kit = 1;
 		vector <int> cur(N);
 		int ret = 0;
 		while (kit <= 1000000)
 		{
 			vector <int> goodCur(N);
 			// 邩`FbN
 			bool ok = true;
 			for (int i=0;i<N;i++)
 			{
 				bool found = false;
 				for(int k = cur[i];k<P;k++)
 				{
 					if (unit[i] * kit * 9 <= quantity[i][k] * 10 && quantity[i][k] * 10 <= unit[i] * kit * 11)
 					{
 						found = true;
 						goodCur[i]=k+1;
 						break;
 					}
 				}
 
 				if (!found)
 				{
 					ok = false;
 					break;
 				}
 			}
 
 			if(ok)
 			{
 				ret++;
 				cur = goodCur;
 			}
 			else
 			{
 				kit++;
 			}
 		}
 	
 
 		PRINTF("Case #%d: %d\n", testcase + 1, ret);
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
 		int R,C;
 
 		cin >> R >> C;
 		vector <string> vs(R);
 		for (int y = 0; y < R; ++y)
 		{
 			cin >> vs[y];
 		}
 
 		for (int y = 0; y < R; ++y)
 		{
 			for (int x = 0; x < C-1; ++x)
 			{
 				if (vs[y][x] != '?' && vs[y][x + 1] == '?')
 				{
 					vs[y][x + 1] = vs[y][x];
 
 				}
 
 			}
 
 			for (int x = C-1; x >= 1; --x)
 			{
 				if (vs[y][x] != '?' && vs[y][x - 1] == '?')
 				{
 					vs[y][x - 1] = vs[y][x];
 				}
 			}
 		}
 
 		for (int y = 0; y < R-1; ++y)
 		{
 			if (count(vs[y].begin(), vs[y].end(), '?')==0 && count(vs[y+1].begin(), vs[y+1].end(), '?')>0)
 			{
 				vs[y+1] = vs[y];
 			}
 		}
 
 		for (int y = R - 1; y >= 1; --y)
 		{
 			if (count(vs[y].begin(), vs[y].end(), '?') == 0 && count(vs[y - 1].begin(), vs[y - 1].end(), '?') > 0)
 			{
 				vs[y - 1] = vs[y];
 			}
 		}
 
 		PRINTF("Case #%d:\n", testcase + 1);
 
 		for (int y = 0; y < R; ++y)
 		{
 			PRINTF("%s\n", vs[y].c_str());
 		}
 	}
 
 	return 0;
 }
 
 #endif