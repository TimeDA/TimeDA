#include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <queue>
 #include <map>
 #include <string>
 #define M 1000002013
 
 using namespace std;
 
 int T,n,m,bb,nn,ee,ans,k,i,ts;
 
 int f(int b,int e,int nn)
 {
 	long long k=e-b;
 	return (k*n-k*(k-1)/2)%M*nn%M;
 }
 
 struct TT
 {
 	int pos,n,open;
 }a[10000],b[10000];
 
 bool operator <(TT t1,TT t2)
 {
 	if(t1.pos!=t2.pos)
 		return t1.pos<t2.pos;
 	return t1.open>t2.open;
 }
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%d",&n,&m);
 		ans=0;
 		k=0;
 		while(m--)
 		{
 			scanf("%d%d%d",&bb,&ee,&nn);
 			a[k].n=nn;
 			a[k].pos=bb;
 			a[k].open=1;
 			k++;
 			a[k].n=nn;
 			a[k].pos=ee;
 			a[k].open=0;
 			k++;
 			ans=(ans+f(bb,ee,nn))%M;
 		}
 		sort(a,a+k);
 		m=0;
 		for(i=0;i<k;i++)
 			if(a[i].open)
 			{
 				b[m]=a[i];
 				m++;
 			}
 			else
 				while(a[i].n)
 				{
 					nn=min(a[i].n,b[m-1].n);
 					ans=(ans+M-f(b[m-1].pos,a[i].pos,nn))%M;
 					a[i].n-=nn;
 					b[m-1].n-=nn;
 					if(!b[m-1].n)m--;
 				}		
 				printf("Case #%d: %d\n",++ts,ans);
 	}
 	return 0;
 }