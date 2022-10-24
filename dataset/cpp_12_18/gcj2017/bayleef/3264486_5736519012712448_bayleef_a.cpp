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
 	char s[2000];
 	int T,ts,i,j,k,ans;
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		ans=0;
 		scanf("%s%d",&s,&k);
 		for(i=0;s[i+k-1];i++)
 			if(s[i]=='-')
 			{
 				for(j=0;j<k;j++)
 					s[i+j]=s[i+j]=='+'?'-':'+';
 				ans++;
 			}
 		for(;s[i];i++)
 			if(s[i]=='-')
 				break;
 		printf("Case #%d: ",ts);
 		if(s[i]=='-')
 			puts("IMPOSSIBLE");
 		else
 			printf("%d\n",ans);
 	}
 	return 0;
 }