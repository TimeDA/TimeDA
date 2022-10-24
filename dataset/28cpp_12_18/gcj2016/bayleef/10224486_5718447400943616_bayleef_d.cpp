#define _USE_MATH_DEFINES
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
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 int bits[1<<16],b[1<<16],c[5],masks[1<<4];
 int T,ts,i,j,k,l,m,n,ok,bad;
 char a[5][5];
 
 bool pr(int i,int j)
 {
 	return bits[i]<bits[j];
 }
 
 int main()
 {
 	freopen("d.in","r",stdin);
 	freopen("d.out","w",stdout);
 	scanf("%d",&T);
 	for(i=1;i<65536;i++)
 		bits[i]=bits[i>>1]+(i&1);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 		{
 			scanf("%s",&a[i]);
 			for(j=0;j<n;j++)
 				a[i][j]-='0';
 		}
 		m=1<<n*n;
 		for(i=0;i<m;i++)
 			b[i]=i;
 		sort(b,b+m,pr);
 		for(k=0;k<m;k++)
 		{
 			ok=0;
 			for(i=0;i<n;i++)
 				for(j=0;j<n;j++)
 					ok|=a[i][j] && (b[k]>>i*n+j&1);
 			if(ok)
 				continue;
 			for(i=0;i<n;i++)
 				for(j=0;j<n;j++)
 					if(b[k]>>i*n+j&1)
 						a[i][j]=1;
 			for(i=0;i<n;i++)
 				c[i]=i;
 			bad=0;
 			do
 			{
 				memset(masks,0,sizeof(masks));
 				masks[0]=1;
 				for(i=0;i<n;i++)
 					for(j=0;j<1<<n;j++)
 						if(masks[j] && bits[j]==i)
 						{
 							ok=0;
 							for(l=0;l<n;l++)
 								if(a[c[i]][l] && !(j>>l&1))
 									ok=masks[j|1<<l]=1;
 							if(!ok)
 							{
 								i=41;
 								break;
 							}
 						}
 				if(i>n)
 				{
 					bad=1;
 					break;
 				}
 			}
 			while(next_permutation(c,c+n));
 			if(!bad)
 				break;
 			for(i=0;i<n;i++)
 				for(j=0;j<n;j++)
 					if(b[k]>>i*n+j&1)
 						a[i][j]=0;
 		}
 		printf("Case #%d: %d\n",ts,bits[b[k]]);
 	}
 	return 0;
 }