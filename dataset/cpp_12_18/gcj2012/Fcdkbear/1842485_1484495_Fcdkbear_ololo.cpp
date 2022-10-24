#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <memory.h>
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 using namespace std;
 int r[15];
 double eps=1e-9;
 int n,w,l;
 vector<pnt > res;
 bool rec(vector<pnt > a)
 {
 	if (a.size()==n)
 	{
 		res=a;
 		return true;
 	}
 	FOR(it,0,100)
 	{
 		int cur=a.size();
 		int x=rand();
 		x*=rand();
 		x%=w;
 		int y=rand();
 		y*=rand();
 		y%=l;
 		bool f=true;
 		FOR(i,0,a.size())
 		{
 			double d=sqrt((double)((a[i].first-x)*1ll*(a[i].first-x)+(a[i].second-y)*1ll*(a[i].second-y)));
 			if (d-eps<r[i]+r[cur])
 				f=false;
 		}
 		if (f)
 		{
 			a.push_back(mp(x,y));
 			bool f1=rec(a);
 			if (f1)
 				return true;
 		}
 		a.pop_back();
 	}
 	return false;
 }
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	//srand(time(NULL));
 	int t;
 	scanf("%d",&t);
 	FOR(it,1,t+1)
 	{
 		scanf("%d%d%d",&n,&w,&l);
 		FOR(i,0,n)
 			scanf("%d",&r[i]);
 		vector<pnt > b;
 		bool f=rec(b);
 		if (!f)
 		{
 			fprintf(stderr,"Case #%d failed!!!\n",it);
 		}
 		printf("Case #%d:",it);
 		FOR(i,0,res.size())
 			printf(" %d %d",res[i].first,res[i].second);
 		printf("\n");
 		fprintf(stderr,"Case #%d done\n",it);
 	}
 	return 0;
 }