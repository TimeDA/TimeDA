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
 
 int T,n,m,ts,p,res,st;
 int ans[10][10];
 int di[]={1,0,-1,0};
 int dj[]={0,1,0,-1};
 
 bool check(int j)
 {
 	int i,k,ok,ii,jj;
 	for(i=0;i<n;i++)
 	{
 		ok=0;
 		for(k=0;k<4;k++)
 		{
 			ii=i+di[k];
 			jj=(j+dj[k]+m)%m;
 			if(ii>=0 && ii<n && ans[ii][jj]==ans[i][j])
 				ok++;
 		}
 		if(ok!=ans[i][j])
 			return 0;
 	}
 	return 1;
 }
 
 bool valid()
 {
 	int i,j;
 	int a[10];
 	for(j=0;j<m;j++)
 	{
 		a[j]=0;
 		for(i=n-1;i>=0;i--)
 			a[j]=a[j]*3+ans[i][j]-1;
 	}
 	for(j=1;j<m;j++)
 	{
 		for(i=0;i<m;i++)
 			if(a[i]<a[(i+j)%m])
 				break;
 			else if(a[i]>a[(i+j)%m])
 				return 0;
 	}
 	return 1;
 }
 
 void rec(int i)
 {
 	int x,j,k;
 	if(i==m)
 	{
 		if(check(m-1) && check(0) && valid())
 		{
 			res++;
 		}
 		return;
 	}
 	for(j=st;j<p;j++)
 	{
 		x=j;
 		for(k=0;k<n;k++)
 		{
 			ans[k][i]=x%3+1;
 			x/=3;
 		}
 		if(i==1 || check(i-1))
 			rec(i+1);
 	}
 }
 
 int main()
 {
 	freopen("d.in","r",stdin);
 	freopen("d.out","w",stdout);
 	scanf("%d",&T);
 	int i,j,x;
 	while(T--)
 	{
 		scanf("%d%d",&n,&m);
 		if(n==6)
 		{
 			res=m==3?6:m==4?4:m==5?2:19;
 			printf("Case #%d: %d\n",++ts,res);
 			continue;
 		}
 		p=1;
 		res=0;
 		for(i=0;i<n;i++)
 			p=p*3;
 		for(i=0;i<p;i++)
 		{
 			x=i;
 			for(j=0;j<n;j++)
 			{
 				ans[j][0]=x%3+1;
 				x/=3;
 			}
 			st=i;
 			rec(1);
 		}
 		printf("Case #%d: %d\n",++ts,res);
 	}
 	return 0;
 }