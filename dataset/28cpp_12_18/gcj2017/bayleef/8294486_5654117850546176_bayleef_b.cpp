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
 
 bool pr(pair<char,int>p1,pair<char,int>p2)
 {
 	return p1.second<p2.second;
 }
 
 int main()
 {
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	int T,ts,a[8],n,i,r,y,b,j,k;
 	char ans[2000];
 	pair<char,int>c[4];
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d",&n);
 		scanf("%d%d%d%d%d%d",&a[1],&a[3],&a[2],&a[6],&a[4],&a[5]);
 		printf("Case #%d: ",ts);
 		if(a[3]+a[4]==n)
 		{
 			if(a[4]!=a[3])
 			{
 				puts("IMPOSSIBLE");
 				continue;
 			}
 			printf("Case #%d: ",ts);
 			for(i=0;i<a[4];i++)
 				printf("BO");
 			puts("");
 			continue;
 		}
 		if(a[3]>=a[4] && a[3])
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 		if(a[5]+a[2]==n)
 		{
 			if(a[2]!=a[5])
 			{
 				puts("IMPOSSIBLE");
 				continue;
 			}
 			printf("Case #%d: ",ts);
 			for(i=0;i<a[2];i++)
 				printf("YV");
 			puts("");
 			continue;
 		}
 		if(a[5]>=a[2] && a[5])
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 		if(a[6]+a[1]==n)
 		{
 			if(a[1]!=a[6])
 			{
 				puts("IMPOSSIBLE");
 				continue;
 			}
 			printf("Case #%d: ",ts);
 			for(i=0;i<a[1];i++)
 				printf("RG");
 			puts("");
 			continue;
 		}
 		if(a[6]>=a[1] && a[6])
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 		r=a[1]-a[6];
 		y=a[2]-a[5];
 		b=a[4]-a[3];
 		if(y+b<r || y+r<b || b+r<y)
 		{
 			puts("IMPOSSIBLE");
 			continue;
 		}
 		c[0]=make_pair('R',r);
 		c[1]=make_pair('Y',y);
 		c[2]=make_pair('B',b);
 		sort(c,c+3,pr);
 		j=0;
 		for(i=0;i<c[2].second;i++)
 		{
 			ans[j++]=c[2].first;
 			if(i>=c[1].second)
 			{
 				ans[j++]=c[0].first;
 				continue;
 			}
 			ans[j++]=c[1].first;
 			if(i<c[0].second+c[1].second-c[2].second)
 				ans[j++]=c[0].first;
 		}
 		for(i=0;i<j;i++)
 		{
 			if(ans[i]=='R')
 			{
 				printf("R");
 				for(k=0;k<a[6];k++)
 					printf("GR");
 				a[6]=0;
 			}
 			else if(ans[i]=='Y')
 			{
 				printf("Y");
 				for(k=0;k<a[5];k++)
 					printf("VY");
 				a[5]=0;
 			}
 			else
 			{
 				printf("B");
 				for(k=0;k<a[3];k++)
 					printf("OB");
 				a[3]=0;
 			}
 		}
 		puts("");
 	}
 	return 0;
 }