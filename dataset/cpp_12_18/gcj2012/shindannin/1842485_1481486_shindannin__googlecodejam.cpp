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
 
 
 int N;
 vector <int> d;
 vector <int> l;
 int D;
 
 bool sReached;
 set <pair <int, int> > sMemo;
 
 void dfs(int now, int hold)
 {
 	if(sReached)
 	{
 		return;
 	}
 
 	if(hold==N+1)
 	{
 		sReached = true;
 		return;
 	}
 
 	if(sMemo.count(make_pair(now,hold)))
 	{
 		return;
 	}
 
 	sMemo.insert(make_pair(now,hold));
 	// BEGIN CUT HERE
 //	cout << " now=" << now << " hold=" << hold << endl;
 	// END CUT HERE
 
 
 	// ɂ߂Ƃ
 	
 	int current_place = d[now];
 	if(current_place<d[hold]-l[hold])
 	{
 		current_place = d[hold]-l[hold];
 	}
 	if(current_place>d[hold]+l[hold])
 	{
 		current_place = d[hold]+l[hold];
 	}
 
 	for (int next_hold = 0; next_hold < N+2; next_hold++)
 	{
 		if(next_hold!=hold)
 		{
 			int r = abs(d[hold]-current_place); 
 			if(INRANGE(d[next_hold],d[hold]-r,d[hold]+r))
 			{
 				dfs(hold,next_hold);
 			}
 		}
 	}
 
 }
 
 int main(){
 
     freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		scanf("%d ",&N);
 
 		d.resize(N+2);
 		l.resize(N+2);
 
 		d[0]=0,l[0]=-1;
 		for (int n = 1; n <= N; n++)
 		{
 			scanf("%d %d",&d[n],&l[n]);
 		}
 		scanf("%d ",&D);
 		d[N+1]=D,l[N+1]=D+1;
 
 		sMemo.clear();
 		sReached = false;
 		dfs(0,1);
 
 		if(sReached)
 		{
 			fprintf(stderr,"Case #%d: YES\n",testcase+1);
 			printf("Case #%d: YES\n",testcase+1);
 		}
 		else
 		{
 			fprintf(stderr,"Case #%d: NO\n",testcase+1);
 			printf("Case #%d: NO\n",testcase+1);
 		
 		}
 
 	}
 }
