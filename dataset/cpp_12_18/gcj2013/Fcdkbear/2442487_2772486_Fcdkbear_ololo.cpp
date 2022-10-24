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
 #include <memory.h>
 #include <ctime>
 
 using namespace std;
  
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
 
 int mod=1000002013;
 vector<pair<pnt,int> > a,A;
 inline LL get(int a, int b, int p)
 {
 	if (b==a)
 		return 0;
 	LL d=b-a-1;
 	LL nd=d+1;
 	if (d&1)
 		nd/=2;
 	else
 		d/=2;
 	d*=nd;
 	d%=mod;
 	d*=p;
 	d%=mod;
 	return d;
 }
 set <pair<pnt,int> > s;
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	double beg=clock();
 #else
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 #endif
 
 	int t;
 	scanf("%d",&t);
 	FOR(itt,1,t+1)
 	{
 		//printf("ok\n");
 		int n,m;
 		scanf("%d%d",&n,&m);
 		s.clear();
 		a.clear();
 		a.resize(m);
 		LL res1=0;
 		LL res2=0;
 		FOR(i,0,m)
 		{
 			scanf("%d%d%d",&a[i].first.first,&a[i].first.second,&a[i].second);
 			if (a[i].first.first>a[i].first.second)
 				throw;
 			s.insert(a[i]);
 			res1+=get(a[i].first.first,a[i].first.second,a[i].second);
 			res1%=mod;
 		}
 		while (s.size())
 		{
 			int a=s.begin()->first.first;
 			int b=s.begin()->first.second;
 			int np=s.begin()->second;
 			int wnp=np;
 			int wb=b;
 			s.erase(s.begin());
 			A.clear();
 			bool f=false;
 			while (s.size())
 			{
 				set <pair<pnt,int> > ::iterator it=s.begin();
 				int na=it->first.first;
 				int nb=it->first.second;
 				int nnp=it->second;
 				s.erase(s.begin());
 				if ((na>a) && (na<=b) && (nb>b))
 				{
 					int p=MIN(np,nnp);
 					LL val1=get(a,nb,p)+get(na,b,p)+get(a,b,np-p)+get(na,nb,nnp-p);
 					LL val2=get(a,b,np)+get(na,nb,nnp);
 					if (val1>=val2)
 					{
 						res2+=get(na,b,p);
 						res2%=mod;
 						A.push_back(mp(mp(a,nb),p));
 						//A.push_back(mp(mp(na,b),p));
 						A.push_back(mp(mp(a,b),np-p));
 						A.push_back(mp(mp(na,nb),nnp-p));
 						f=true;
 						break;
 					}
 					else
 					{
 						A.push_back(mp(mp(na,nb),nnp));
 					}
 				}
 				else
 					A.push_back(mp(mp(na,nb),nnp));
 			}
 			if (!f)
 			{
 				res2+=get(a,wb,wnp);
 
 			}
 			FOR(i,0,A.size())
 				if (A[i].second)
 					s.insert(A[i]);
 		}
 		int res=res2-res1;
 		if (res<0)
 			res+=mod;
 		printf("Case #%d: %d\n",itt,res);
 		fprintf(stderr,"Case #%d done\n",itt);
 	}
 
 #ifdef Fcdkbear
 	double end=clock();
 	fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
 #endif
 	return 0;
 }