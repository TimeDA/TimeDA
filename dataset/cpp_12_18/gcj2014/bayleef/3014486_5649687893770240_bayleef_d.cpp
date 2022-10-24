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
 
 using namespace std;
 
 int T,n,m,i,z,j,k,p,t,ts,x,ma,ans;
 char s[20][20];
 int trie[100][30];
 int b[20];
 
 int main()
 {
 	freopen("d.in","r",stdin);
 	freopen("d.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%d",&n,&m);
 		ma=0;
 		for(i=0;i<n;i++)
 			scanf("%s",&s[i]);
 		z=1;
 		for(i=0;i<n;i++)
 			z*=m;
 		for(i=0;i<z;i++)
 		{
 			memset(trie,0,sizeof(trie));
 			x=i;
 			p=0;
 			for(j=0;j<n;j++)
 			{
 				b[j]=x%m;
 				x/=m;
 				p=max(p,b[j]);
 
 			}
 			for(j=0;j<=p;j++)
 			{
 				for(k=0;k<n;k++)
 					if(b[k]==j)
 						break;
 				if(k==n)
 					break;
 			}
 			if(j<=p)continue;
 			p++;
 			for(j=0;j<n;j++)
 			{
 				t=b[j];
 				for(k=0;s[j][k];k++)
 				{
 					if(!trie[t][s[j][k]-'A'])
 						trie[t][s[j][k]-'A']=p++;
 					t=trie[t][s[j][k]-'A'];
 				}
 			}
 			if(p>ma)
 			{
 				ma=p;
 				ans=1;
 			}
 			else if(p==ma)
 				ans++;
 		}
 		printf("Case #%d: %d %d\n",++ts,ma,ans);
 	}
 	return 0;
 }