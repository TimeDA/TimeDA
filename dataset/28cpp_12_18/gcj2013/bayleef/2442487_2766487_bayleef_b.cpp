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
 
 int T,ts,n,i;
 long long p,cur;
 
 int main()
 {
 	freopen("b.in","r",stdin);	freopen("b.out","w",stdout);
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%lld",&n,&p);
 		printf("Case #%d: ",ts);
 		if((1LL<<n)==p)
 		{
 			printf("%lld %lld\n",(1LL<<n)-1,(1LL<<n)-1);
 			continue;
 		}
 		cur=0;
 		for(i=0;i<n;i++)
 		{
 			if(cur>=p)
 				break;
 			cur|=1LL<<n-i-1;
 		}
 		printf("%lld ",(1LL<<i)-2);
 		cur=(1LL<<n)-1;
 		for(i=n-1;i>=0;i--)
 		{
 			if(cur<p)
 				break;
 			cur^=1LL<<i;
 		}
 		printf("%lld\n",(1LL<<n)-(1LL<<n-1-i));
 	}
 	return 0;
 }