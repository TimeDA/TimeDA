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
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	int T,n,p,i,u[5],ts,ans;
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d",&n,&p);
 		for(i=0;i<p;i++)
 			u[i]=0;
 		while(n--)
 		{
 			scanf("%d",&i);
 			u[i%p]++;
 		}
 		printf("Case #%d: ",ts);
 		if(p==2)
 		{
 			printf("%d\n",u[0]+(u[1]+1)/2);
 			continue;
 		}
 		if(p==3)
 		{
 			ans=u[0];
 			i=min(u[1],u[2]);
 			ans+=i;
 			u[1]-=i;
 			u[2]-=i;
 			printf("%d\n",ans+(u[1]+2)/3+(u[2]+2)/3);
 			continue;
 		}
 	}
 	return 0;
 }