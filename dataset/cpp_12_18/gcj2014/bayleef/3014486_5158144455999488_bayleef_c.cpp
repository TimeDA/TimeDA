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
 #pragma comment(linker, "/STACK:1000000000")
 
 using namespace std;
 
 int di[]={-1,0,0,1};
 int dj[]={0,1,-1,0};
 
 bool u[101][501],v[101][501];
 int b,i,j,k,l,m,n,o,p,ans,T,ts,ma,a[4];
 
 bool dfs(int i,int j,int l)
 {
 	u[i][j]=1;
 	if(j==m-1)return true;
 	int k,ii,jj;
 	for(k=0;k<4;k++)
 	{
 		ii=i+di[a[k]];
 		jj=j+dj[a[k]];
 		if(ii>=0 && jj>=0 && ii<n && jj<m && !u[ii][jj] && dfs(ii,jj,l+1))
 			return true;
 	}
 	return false;
 }
 
 int main()
 {
 	freopen("c.in","r",stdin);	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%d%d",&n,&m,&b);
 		memset(v,0,sizeof(v));
 		while(b--)
 		{
 			scanf("%d%d%d%d",&i,&j,&k,&l);
 			for(o=i;o<=k;o++)
 				for(p=j;p<=l;p++)
 					v[o][p]=u[o][p]=1;
 		}
 		for(i=0;i<4;i++)
 			a[i]=i;
 		ma=0;
 		do
 		{
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					u[i][j]=v[i][j];
 			ans=0;
 			for(i=0;i<n;i++)
 				if(!u[i][0])
 					ans+=dfs(i,0,0);
 			if(ans>ma)
 				ma=ans;
 		}
 		while(next_permutation(a,a+4));
 		printf("Case #%d: %d\n",++ts,ma);
 	}
 	return 0;
 }