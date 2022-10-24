#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
 #include <queue>
 
 using namespace std;
 
 #define	sqr(a)		((a)*(a))
 #define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
 #define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
 #define	PER(i,n)	per(i,n,0)
 #define	REP(i,n)	rep(i,0,n)
 #define	clr(a)		memset((a),0,sizeof (a))
 #define	SZ(a)		((int)((a).size()))
 #define	ALL(x)		x.begin(),x.end()
 #define	mabs(a)		((a)>0?(a):(-(a)))
 #define	inf			(0x7fffffff)
 #define	eps			1e-6
 
 #define	MAXN		
 #define MODN		(1000000007)
 
 typedef long long ll;
 
 char s[100][100];
 
 class A
 {
 public:
 	A()
 	{
 		REP(i,26)
 		{
 			next[i] = NULL;
 		}
 	}
 	A* next[26];
 };
 
 A* root[4];
 
 void init()
 {
 	REP(i,4)
 	{
 		root[i] = new A();
 	}
 }
 
 void clear(A* a)
 {
 	REP(i,26)
 	{
 		if (a->next[i] != NULL)
 		{
 			clear(a->next[i]);
 			delete a->next[i];
 			a->next[i] = NULL;
 		}
 	}
 }
 
 void insert(A* a,char* s)
 {
 	int x = s[0] - 'A';
 
 	if (a->next[x] == NULL)
 	{
 		a->next[x] = new A;
 	}
 	if (s[1] != '\0')
 	{
 		insert(a->next[x],s + 1);
 	}
 }
 
 int count(A* a)
 {
 	int ret = 1;
 	REP(i,26)
 	{
 		if (a->next[i] != NULL)
 		{
 			ret += count(a->next[i]);
 		}
 	}
 
 	return ret;
 }
 
 int main()
 {
 #if 1
 	freopen("data.in","r",stdin);
 	freopen("data.out","w",stdout);
 #endif
 
 	int CASE;
 	scanf("%d",&CASE);
 
 	init();
 	rep(K,1,CASE + 1)
 	{
 		int m,n;
 		scanf("%d %d",&m,&n);
 		REP(i,m)
 		{
 			scanf("%s",s[i]);
 		}
 
 		long long cc = 1;
 		REP(i,m)
 		{
 			cc *= 1LL * n;
 		}
 
 		int maxc = 0;
 		int maxi = 0;
 		for (long long i = 0;i < cc;i++)
 		{
 			REP(j,4)
 			{
 				clear(root[j]);
 			}
 			
 			long long temp = i;
 			int r = 0;
 			REP(j,m)
 			{
 				int x = temp % n;
 
 				insert(root[x],s[j]);
 				r |= 1 << x;
 
 				temp /= n;
 			}
 			if (r != (1 << n) - 1)
 			{
 				continue;
 			}
 			int tt = 0;
 			REP(j,n)
 			{
 				tt += count(root[j]);
 			}
 
 			if (tt > maxc)
 			{
 				maxc = tt;
 				maxi = 1;
 			}
 			else if (tt == maxc)
 			{
 				maxi++;
 			}
 		}
 
 		printf("Case #%d: ",K);
 		printf("%d %d\n",maxc,maxi);
 	}
 
 	return 0;
 }
