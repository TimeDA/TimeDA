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
 #define N 10
 
 using namespace std;
 
 map<long long,int>m;
 queue<long long>q;
 
 int a[20],b[20],c[20],T,ts,n;
 map<long long,int>::iterator it;
 
 long long hah()
 {
 	int i;
 	long long ans=0;
 	for(i=0;i<N;i++)
 		ans=ans*16+a[i];
 	return ans;
 }
 
 int main()
 {
 	int i,j,z;
 	long long h;
 	/*for(i=0;i<N;i++)
 		a[i]=i;
 	do
 	{
 		for(i=1;i<N;i++)
 			if(a[i]<a[i-1])
 				break;
 		for(j=i;j<N;j++)
 			if(a[j]>a[j-1])
 				break;
 		if(j==N)
 		{
 			h=hah();
 			m[h]=0;
 			q.push(h);
 		}
 	}
 	while(next_permutation(a,a+N));
 	while(!q.empty())
 	{
 		h=q.front();
 		q.pop();
 		z=m[h];
 		for(i=1;i<N;i++)
 		{
 			j=(h>>4*i&15)^(h>>4*(i-1)&15);
 			h^=(long long)j<<4*i;
 			h^=(long long)j<<4*(i-1);
 			if(m.find(h)==m.end())
 			{
 				m[h]=z+1;
 				q.push(h);
 			}
 			h^=(long long)j<<4*i;
 			h^=(long long)j<<4*(i-1);
 		}
 	}
 	printf("%d\n",m.size());
 	freopen("info.in","w",stdout);
 	for(it=m.begin();it!=m.end();++it)
 		printf("%lld %d\n",it->first,it->second);
 	return 0;*/
 	FILE *f=fopen("info.in","r");
 	while(~fscanf(f,"%lld%d",&h,&i))
 		m[h]=i;
 	freopen("b.in","r",stdin);
 	freopen("b.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 		{
 			scanf("%d",&b[i]);
 			c[i]=b[i];
 		}
 		for(i=0;i<10-n;i++)
 			a[i]=i;
 		sort(c,c+n);
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<n;j++)
 				if(b[j]==c[i])
 					break;
 			a[j+10-n]=i+10-n;
 		}
 		printf("Case #%d: %d\n",++ts,m[hah()]);
 	}
 	return 0;
 }