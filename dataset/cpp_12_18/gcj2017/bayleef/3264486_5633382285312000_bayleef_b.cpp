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
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	long long n,cur;
 	int m,T,ts,i,j;
 	char s[100];
 	int ans[100];
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%s",&s);
 		n=0;
 		for(i=0;s[i];i++)
 		{
 			s[i]-='0';
 			n=n*10+s[i];
 		}
 		m=i;
 		for(i=0;i<m;i++)
 		{
 			for(ans[i]=i?ans[i-1]:0;ans[i]<10;ans[i]++)
 			{
 				for(j=i+1;j<m;j++)
 					ans[j]=ans[j-1];
 				cur=0;
 				for(j=0;j<m;j++)
 					cur=cur*10+ans[j];
 				if(cur>n)
 				{
 					ans[i]--;
 					break;
 				}
 			}
 			ans[i]=min(ans[i],9);
 		}
 		cur=0;
 		for(j=0;j<m;j++)
 			cur=cur*10+ans[j];
 		printf("Case #%d: %lld\n",ts,cur);
 	}
 	return 0;
 }