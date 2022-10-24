#include <stdio.h>
 #include <math.h>
 #include <iostream>
 #include <sstream>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <vector>
 #include <set>
 #include <algorithm>
 #include <map>
 #include <queue>
 #include <string>
 
 using namespace std;
 
 int n,m,i,d[20000],l[20000],T,ts,ma[20000],j;
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		memset(ma,-1,sizeof(ma));
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 			scanf("%d%d",&d[i],&l[i]);
 		scanf("%d",&m);
 		ma[0]=d[0];
 		for(i=1;i<n;i++)
 			for(j=0;j<i;j++)
 				if(d[j]+ma[j]>=d[i])
 					ma[i]=max(ma[i],min(d[i]-d[j],l[i]));
 		for(i=0;i<n;i++)
 			if(ma[i]!=-1 && d[i]+ma[i]>=m)
 				break;
 		printf("Case #%d: %s\n",++ts,i!=n?"YES":"NO");
 	}
 	return 0;
 }