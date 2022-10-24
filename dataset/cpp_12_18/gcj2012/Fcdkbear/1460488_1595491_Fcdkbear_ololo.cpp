#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
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
 int n,s,p;
 int dp[110][110];
 int a[110];
 int r(int pos, int k)
 {
 	if (pos==n)
 	{
 		if (k==0)
 			return 0;
 		return -1000000;
 	}
 	if (dp[pos][k]!=-1)
 		return dp[pos][k];
 	int res=-1000000;
 	FOR(i,0,11)
 		FOR(j,i,11)
 		{
 			if (i+j>a[pos])
 				continue;
 			int q=a[pos]-i-j;
 			int v1=MIN(i,MIN(j,q));
 			int v2=MAX(i,MAX(j,q));
 			if (v2-v1>2)
 				continue;
 			int nk=k;
 			if (v2-v1==2)
 				nk--;
 			if (nk<0)
 				continue;
 			int res1=0;
 			if (v2>=p)
 				res1++;
 			res1+=r(pos+1,nk);
 			if (res1>=res)
 				res=res1;
 		}
 	return dp[pos][k]=res;
 }
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	int t;
 	scanf("%d",&t);
 	FOR(test,1,t+1)
 	{
 		scanf("%d%d%d",&n,&s,&p);
 		FOR(i,0,n)
 			scanf("%d",&a[i]);
 		MEMS(dp,-1);
 		int res=r(0,s);
 		printf("Case #%d: %d\n",test,res);
 	}
 	return 0;
 }
