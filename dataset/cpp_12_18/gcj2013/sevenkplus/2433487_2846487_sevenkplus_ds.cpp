#include<cstdio>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 #define pct __builtin_popcount
 double f[1<<20],g[1<<20];char s[22];int n,m,p[22];
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%s",s);
 		n=strlen(s);m=0;
 		for(int i=0;i<n;i++)
 			if(s[i]=='.')p[m++]=i;
 		for(int w=0;w<(1<<m);w++)f[w]=g[w]=0.0;
 		g[0]=1.0;
 		double in=1.0/n;
 		for(int w=0;w<(1<<m)-1;w++)
 		{
 			for(int i=0;i<m;i++)
 				if((w>>i)&1)s[p[i]]='X';else s[p[i]]='.';
 			for(int i=0;i<n;i++)
 			{
 				int j=i;
 				while(s[j]=='X')j=(j+1)%n;
 				for(int k=0;k<m;k++)
 					if(p[k]==j)
 					{
 						f[w^(1<<k)]=f[w^(1<<k)]+(f[w]+(n-(j-i+n)%n)*g[w])*in;
 						g[w^(1<<k)]=g[w^(1<<k)]+g[w]*in;
 						break;
 					}
 			}
 		}
 		//for(int i=0;i<(1<<m);i++)printf("%d %.9lf %.9lf\n",i,f[i],g[i]);
 		printf("Case #%d: %.9lf\n",__,f[(1<<m)-1]);
 	}
 	return 0;
 }