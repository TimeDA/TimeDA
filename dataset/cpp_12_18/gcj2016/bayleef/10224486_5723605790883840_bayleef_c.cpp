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
 
 int T,ts,n,m,i,j,msk,a[100];
 vector<int>v[50];
 int h[50],u[50],g[50];
 int lf[16][16],rg[16][16],up[16][16],dn[16][16];
 
 void dfs(int i)
 {
 	u[i]=1;
 	int j;
 	for(j=0;j<v[i].size();j++)
 		if(!u[v[i][j]])
 			dfs(v[i][j]);
 }
 
 int main()
 {
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d",&n,&m);
 		for(i=0;i<2*(n+m);i++)
 		{
 			scanf("%d",&a[i]);
 			a[i]--;
 		}
 		printf("Case #%d:\n",ts);
 		for(i=0;i<n;i++)
 			for(j=0;j<m;j++)
 			{
 				up[i][j]=i*m+j;
 				dn[i][j]=(i+1)*m+j;
 				lf[i][j]=i*(m+1)+j+(n+1)*m;
 				rg[i][j]=i*(m+1)+j+1+(n+1)*m;
 			}
 		for(i=0;i<m;i++)
 			h[i]=up[0][i];
 		for(i=m;i<m+n;i++)
 			h[i]=rg[i-m][m-1];
 		for(i=m+n;i<2*m+n;i++)
 			h[i]=dn[n-1][m-1+m+n-i];
 		for(i=2*m+n;i<2*m+2*n;i++)
 			h[i]=lf[n-1+2*m+n-i][0];
 		for(i=0;i<2*m+2*n;i++)
 			g[i]=h[a[i]];
 		for(i=0;i<2*m+2*n;i++)
 			h[i]=g[i];
 		for(msk=0;msk<1<<n*m;msk++)
 		{
 			for(i=0;i<2*n*m+n+m;i++)
 				v[i].clear();
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					if(msk>>i*m+j&1)
 					{
 						v[up[i][j]].push_back(lf[i][j]);
 						v[lf[i][j]].push_back(up[i][j]);
 						v[dn[i][j]].push_back(rg[i][j]);
 						v[rg[i][j]].push_back(dn[i][j]);
 					}
 					else
 					{
 						v[up[i][j]].push_back(rg[i][j]);
 						v[rg[i][j]].push_back(up[i][j]);
 						v[dn[i][j]].push_back(lf[i][j]);
 						v[lf[i][j]].push_back(dn[i][j]);
 					}
 			memset(u,0,sizeof(u));
 			for(i=0;i<2*m+2*n;i+=2)
 			{
 				dfs(h[i]);
 				for(j=i;j<2*m+2*n;j++)
 					if(u[h[j]]!=(j>>1==i>>1))
 						break;
 				if(j<2*m+2*n)
 					break;
 			}
 			if(j==2*m+2*n)
 				break;
 		}
 		if(msk==1<<n*m)
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<m;j++)
 				printf("%c",(msk>>i*m+j&1)?'/':'\\');
 			puts("");
 		}
 	}
 	return 0;
 }