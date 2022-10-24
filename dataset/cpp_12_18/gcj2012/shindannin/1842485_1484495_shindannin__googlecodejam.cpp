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
 
 void clamp(double& a, double lo, double hi)
 {
 	if(a<lo)
 	{
 		a = lo;
 	}
 	else if (a>hi)
 	{
 		a = hi;
 	}
 }
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int N;
 		double W, L;
 		cin >> N >> W >> L;
 
 		vector <double> r(N);
 		vector <double> x(N);
 		vector <double> y(N);
 		for (int n = 0; n < N; n++)
 		{
 			cin >> r[n];
 		}
 
 		srand(5);
 		for (int n = 0; n < N; n++)
 		{
 			x[n] = W * rand() / RAND_MAX;
 			y[n] = L * rand() / RAND_MAX;
 		}
 
 
 		while(1)
 		{
 			bool ok = true;
 			for (int i = 0; i < N; i++)
 			{
 //				fprintf(stderr,"%d = %.16f %.16f \n",i,x[i],y[i]);
 				for (int k = i+1; k < N; k++)
 				{
 					double dx = x[i]-x[k];
 					double dy = y[i]-y[k];
 					double rsum = r[i]+r[k];
 					double now_dist  = hypot(dx,dy);
 					if( now_dist<=rsum+0.0001)
 					{
 						if(now_dist==0.0)
 						{
 							x[i] += rand()%3-1;
 							y[i] += rand()%3-1;
 							x[k] += rand()%3-1;
 							y[k] += rand()%3-1;
 						}
 						else
 						{
 							double ex = dx/now_dist;
 							double ey = dy/now_dist;
 							double move_dist = 5*(rsum-now_dist)/2;
 
 							x[i] += ex * move_dist;
 							y[i] += ey * move_dist;
 							x[k] -= ex * move_dist;
 							y[k] -= ey * move_dist;
 						}
 
 						clamp(x[i],0.0,W);
 						clamp(x[k],0.0,W);
 						clamp(y[i],0.0,L);
 						clamp(y[k],0.0,L);
 						ok = false;
 					}
 				}
 			}
 
 			if(ok)
 			{
 				break;
 			}
 		}
 
 
 		fprintf(stderr,"Case #%d: ",testcase+1);
 		printf("Case #%d: ",testcase+1);
 		for (int i = 0; i < N; i++)
 		{
 			fprintf(stderr,"%.16f %.16f ",x[i],y[i]);
 			printf("%.16f %.16f ",x[i],y[i]);
 		}
 		fprintf(stderr,"\n");
 		printf("\n");
 	}
 }
 
 
 
 
 
 
 
 #else
 
 int N;
 vector <int> d;
 vector <int> l;
 int D;
 
 bool sReached;
 set <pair <int, int> > sMemo;
 
 set <int > sMemo2;
 
 void dfs2(int hold)
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
 
 	if(sMemo2.count(hold))
 	{
 		return;
 	}
 
 	sMemo2.insert(hold);
 
 	for (int next_hold = 0; next_hold < N+2; next_hold++)
 	{
 		if(next_hold!=hold)
 		{
 			if(INRANGE(d[next_hold],d[hold]-l[hold],d[hold]+l[hold]))
 			{
 				dfs2(next_hold);
 			}
 		}
 	}
 
 }
 
 
 
 
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
 
 	for (int next_hold = N+1; next_hold > hold; next_hold--)
 	{
 		int r = abs(d[hold]-current_place); 
 		if(INRANGE(d[next_hold],d[hold]-r,d[hold]+r))
 		{
 			dfs(hold,next_hold);
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
 
 		if(testcase==4 || testcase==5 || testcase==21)
 		{
 			continue;
 		}
 
 		sReached = false;
 
 		sMemo.clear();
 		dfs(0,1);
 
 
 /*
 		sMemo2.clear();
 		dfs2(1);
 */
 
 
 /*
 		int now = 0;
 		int hold = 1;
 		while(1)
 		{
 			int current_place = d[now];
 			if(current_place<d[hold]-l[hold])
 			{
 				current_place = d[hold]-l[hold];
 			}
 			if(current_place>d[hold]+l[hold])
 			{
 				current_place = d[hold]+l[hold];
 			}
 			const int r = abs(d[hold]-current_place); 
 
 			for (int next_hold = hold+1; next_hold < N+2; next_hold++)
 			{
 				if(INRANGE(d[next_hold],d[hold]-r,d[hold]+r))
 				{
 					// ͂Ă̂ŁAƉ
 					if(next_hold==N+1)
 					{
 						sReached = true;
 						goto NUKE;
 					}
 				}
 				else
 				{
 					if(next_hold==hold+1)
 					{
 						// Ƃ߂̂͂Ȃ̂ł߁B
 						goto NUKE;
 					}
 					else
 					{
 						// ͂Ȃ̂őÔxXg
 						now = hold;
 						hold = next_hold-1;
 						break;
 					}
 				}
 			}
 		}
 NUKE:;
 */
 
 
 
 
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
 
 #endif