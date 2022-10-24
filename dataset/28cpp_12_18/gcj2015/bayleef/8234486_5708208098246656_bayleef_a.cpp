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
 
 int T,i,j,k,ii,jj,n,m,ts,sm,ok,ans;
 int di[]={1,0,-1,0};
 int dj[]={0,1,0,-1};
 int u[200][200][10];
 char s[200][200];
 char dir[]="v>^<";
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%d",&n,&m);
 		for(i=0;i<n;i++)
 			scanf("%s",&s[i]);
 		memset(u,0,sizeof(u));
 		for(i=0;i<n;i++)
 			for(j=0;j<m;j++)
 				if(s[i][j]!='.')
 					for(k=0;k<4;k++)
 					{
 						for(ii=i+di[k],jj=j+dj[k];ii>=0 && jj>=0 && ii<n && jj<m && s[ii][jj]=='.';ii+=di[k],jj+=dj[k]);
 						u[i][j][k]=!(ii>=0 && jj>=0 && ii<n && jj<m);
 					}
 		sm=0;
 		ans=0;
 		for(i=0;i<n && sm!=4;i++)
 			for(j=0;j<m;j++)
 			{
 				sm=0;
 				ok=0;
 				for(k=0;k<4;k++)
 				{
 					sm+=u[i][j][k];
 					if(s[i][j]==dir[k])
 						ok=u[i][j][k];
 				}
 				if(sm==4)
 					break;
 				if(ok)
 					ans++;
 			}
 		if(sm==4)
 			printf("Case #%d: IMPOSSIBLE\n",++ts);
 		else printf("Case #%d: %d\n",++ts,ans);
 	}
 	return 0;
 }