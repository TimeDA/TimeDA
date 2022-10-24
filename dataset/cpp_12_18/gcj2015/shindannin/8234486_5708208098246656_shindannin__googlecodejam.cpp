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
 #include "assert.h"
 
 using namespace std;
 static const double EPS = 1e-9;
 int ROUND(double x) { return (int)(x+0.5); }
 bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
 bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
 double SQSUM(double x,double y) { return x*x+y*y; }
 template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
 template<class T> void amin(T &a,T v){if(a>v) a=v;}
 template<class T> void amax(T &a,T v){if(a<v) a=v;}
 #define PI	(acos(-1))
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
 
 #define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);
 
 
 
 
 // Union-Find@BOtȂB
 void union_init(vector <int>& v, int size)
 {
 	v.clear();
 	for(int i=0;i<size;i++)
 	{
 		v.push_back(i);
 	}
 }
 
 // union_connectɁAunion_getƁAv̓O[v̑\ԍBv[n]=tsB
 // 
 int union_get(vector <int>& v, int n)
 {
 	int t = n;
 	int k;
 	while(v[t]!=t)
 	{
 		t=v[t];
 	}
 
 	while(v[n]!=n)
 	{
 		k = v[n];
 		v[n] = t;
 		n = k;
 	}
 	return n;
 }
 
 
 // m[haƃm[hbȂB
 // union_connectvɂ́AO[vɓm[ĥ1̔ԍ
 bool union_connect(vector <int> & v, int a, int b)
 {
 	a = union_get(v,a);
 	b = union_get(v,b);
 	if(a==b)
 	{
 		return false;
 	}
 
 	v[a]=b;
 	return true;
 }
 
 const static int dy[] = {-1, 0, 1, 0}; // U,R,D,L
 const static int dx[] = { 0, 1, 0,-1};
 
 int getDir(char c)
 {
 	switch(c)
 	{
 	case '^':
 		return 0;
 		break;
 	case '>':
 		return 1;
 		break;
 	case 'v':
 		return 2;
 		break;
 	case '<':
 		return 3;
 		break;
 	default:
 		break;
 	}
 
 	return -1;
 }
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int R,C;
 		cin >> R >> C;
 		vector <string> vs(R);
 		for (int i = 0; i < R; ++i)
 		{
 			cin >> vs[i];
 		}
 
 		const int RC = R*C;
 		vector <bool> oob(RC);
 		vector <int> v;
 		union_init(v,RC);
 
 		int numAns = 0;
 		for (int y = 0; y < R; ++y)
 		{
 			for (int x = 0; x < C; ++x)
 			{
 				if(vs[y][x]!='.')
 				{
 					const int d = getDir(vs[y][x]);
 
 					for (int s = 1; ; ++s)
 					{
 						const int ny = y+dy[d]*s; 
 						const int nx = x+dx[d]*s;
 						if(INRANGE(ny,0,SZ(vs)-1)&&INRANGE(nx,0,SZ(vs[y])-1))
 						{
 							if(vs[ny][nx]!='.')
 							{
 								union_connect(v,y*C+x,ny*C+nx);
 								break;
 							}
 						}
 						else
 						{
 							oob[y*C+x]=true;
 							numAns++;
 							break;
 						}
 					}
 				}
 			}
 		}
 
 		vector <int> num_nodes(RC); //
 		for(int i=0;i<RC;i++)
 		{
 			num_nodes[union_get(v,i)]++;
 		}
 
 		bool possible = true;
 		for (int i = 0; i < RC; ++i)
 		{
 			if(oob[i])
 			{
 				if(num_nodes[v[i]]==1)
 				{
 					bool ok = false;
 					// ǂ̕ɕǂ΂nj
 					const int y = i/C;
 					const int x = i%C;
 					for(int d=0;d<4;++d)
 					{
 						for (int s = 1; ; ++s)
 						{
 							const int ny = y+dy[d]*s; 
 							const int nx = x+dx[d]*s;
 							if(INRANGE(ny,0,SZ(vs)-1)&&INRANGE(nx,0,SZ(vs[y])-1))
 							{
 								if(vs[ny][nx]!='.')
 								{
 									ok = true;
 									break;
 								}
 							}
 							else
 							{
 								break;
 							}
 						}
 					}
 					
 					if(ok==false)
 					{
 						possible = false;
 						break;
 					}
 				}
 			}
 		}
 
 		// ̏ꍇ̕Ԃl
 		// v[]        ={0,6,7,6,6,7,6,7} // union_getƁAO[v̑\̃m[h̔ԍ
 		// num_nodes[]={1,0,0,0,0,0,4,3} // \m[hO[vɑAm[h
 		// num_nodes[v[a]]̂悤ɂΓO[ṽm[h擾łB
 
 		if(possible)
 		{
 			PRINTF("Case #%d: %d\n",testcase+1, numAns);
 		}
 		else
 		{
 			PRINTF("Case #%d: IMPOSSIBLE\n",testcase+1);
 		}
 	}
 
 	return 0;
 }
