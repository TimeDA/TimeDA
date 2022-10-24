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
 
 bool v[2000][2000];
 int T,ts,n,i,j,a[2000],b[2000],ok,k;
 vector<int>w[2000];
 int u[2000];
 int ans[2000];
 
 struct TT
 {
 	int i;
 }t;
 
 bool operator <(TT t1, TT t2)
 {
 	return t1.i>t2.i;
 }
 
 priority_queue<TT>q;
 
 int main()
 {
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 			scanf("%d",&a[i]);
 		for(i=0;i<n;i++)
 			scanf("%d",&b[i]);
 		for(i=0;i<n;i++)
 			for(j=0;j<n;j++)
 				v[i][j]=0;
 		for(i=0;i<n;i++)
 		{
 			ok=0;
 			for(j=i-1;j>=0;j--)
 			{
 				if(a[j]+1==a[i] && !ok)
 				{
 					ok=1;
 					v[j][i]=1;
 				}
 				if(a[j]>=a[i])
 					v[i][j]=1;
 			}
 			ok=0;
 			for(j=i+1;j<n;j++)
 			{
 				if(b[j]+1==b[i] && !ok)
 				{
 					ok=1;
 					v[j][i]=1;
 				}
 				if(b[j]>=b[i])
 					v[i][j]=1;
 			}
 		}
 		for(i=0;i<n;i++)
 			u[i]=0;
 		for(i=0;i<n;i++)
 			for(w[i].clear(),j=0;j<n;j++)
 				if(v[i][j])
 				{
 					w[i].push_back(j);
 					u[j]++;
 				}
 		for(t.i=0;t.i<n;t.i++)
 			if(!u[t.i])
 				q.push(t);
 		k=1;
 		while(!q.empty())
 		{
 			t=q.top();
 			ans[t.i]=k++;
 			q.pop();
 			i=t.i;
 			for(j=0;j<w[i].size();j++)
 			{
 				u[w[i][j]]--;
 				if(!u[w[i][j]])
 				{
 					t.i=w[i][j];
 					q.push(t);
 				}
 			}
 		}
 		printf("Case #%d:",++ts);
 		for(i=0;i<n;i++)
 			printf(" %d",ans[i]);
 		puts("");
 	}
 	return 0;
 }