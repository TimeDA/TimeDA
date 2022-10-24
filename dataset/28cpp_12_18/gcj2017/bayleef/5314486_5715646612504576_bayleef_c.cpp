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
 
 char s[100][100];
 int ind[100][100];
 int ans[10001];
 int n,m,k;
 vector<int>v[100][100];
 vector<int>g[5010],gt[5010];
 vector<int>temp;
 
 bool process(int i,int j,int di,int dj)
 {
 	int z=ind[i][j];
 	if(dj)
 		z+=k;
 	bool res=true;
 	while(true)
 	{
 		i+=di;
 		j+=dj;
 		if(i<0 || j<0 || i>=n || j>=m || s[i][j]=='#')
 			return res;
 		else if(s[i][j]=='-' || s[i][j]=='|')
 			res=false;
 		else if(s[i][j]=='\\')
 			swap(di,dj);
 		else if(s[i][j]=='/')
 		{
 			swap(di,dj);
 			di=-di;
 			dj=-dj;
 		}
 		else
 			v[i][j].push_back(z);
 	}
 }
 
 bool used[5010];
 vector<int>order;
 int comp[5010];
 
 void dfs1 (int v) 
 {
 	used[v] = true;
 	for (size_t i=0; i<g[v].size(); ++i) {
 		int to = g[v][i];
 		if (!used[to])
 			dfs1 (to);
 	}
 	order.push_back (v);
 }
 
 void dfs2 (int v, int cl) {
 	comp[v] = cl;
 	for (size_t i=0; i<gt[v].size(); ++i) {
 		int to = gt[v][i];
 		if (comp[to] == -1)
 			dfs2 (to, cl);
 	}
 }
 
 int main()
 {
 	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
 	int T,ts,i,j,l,z;
 	bool left,right,up,down;
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d",&n,&m);
 		for(i=0;i<n;i++)
 			scanf("%s",&s[i]);
 		k=0;
 		for(i=0;i<n;i++)
 			for(j=0;j<m;j++)
 			{
 				if(s[i][j]=='-' || s[i][j]=='|')
 					ind[i][j]=k++;
 				v[i][j].clear();
 			}
 		for(i=0;i<k;i++)
 			ans[i]=-1;
 		for(i=0;i<2*k;i++)
 		{
 			g[i].clear();
 			gt[i].clear();
 		}
 		order.clear();
 		bool bad=false;
 		for(i=0;i<n && !bad;i++)
 			for(j=0;j<m && !bad;j++)
 				if(s[i][j]=='-' || s[i][j]=='|')
 				{
 					right=process(i,j,0,1);
 					left=process(i,j,0,-1);
 					up=process(i,j,-1,0);
 					down=process(i,j,1,0);
 					if((!right || !left) && (!up || !down))
 					{
 						bad=true;
 						break;
 					}
 					if(!right || !left)
 						ans[ind[i][j]]=1;
 					if(!up || !down)
 						ans[ind[i][j]]=0;
 				}
 		for(i=0;i<n && !bad;i++)
 			for(j=0;j<m && !bad;j++)
 				if(s[i][j]=='.')
 				{
 					if(v[i][j].empty())
 					{
 						bad=true;
 						break;
 					}
 					temp.clear();
 					for(l=0;l<v[i][j].size();l++)
 					{
 						z=v[i][j][l];
 						if(z>=k)z-=k;
 						if(ans[z]!=-1)
 						{
 							if((ans[z]==1) == (z==v[i][j][l]))
 							{
 								temp.clear();
 								temp.push_back(-1);
 								break;
 							}
 						}
 						else
 							temp.push_back(v[i][j][l]);
 					}
 					if(temp.empty())
 					{
 						bad=true;
 						break;
 					}
 					if(temp[0]==-1)
 						continue;
 					if(temp.size()==1)
 					{
 						z=temp[0];
 						if(z>=k)
 							ans[z-k]=0;
 						else
 							ans[z]=1;
 					}
 					else
 					{
 						g[(temp[0]+k)%(2*k)].push_back(temp[1]);
 						g[(temp[1]+k)%(2*k)].push_back(temp[0]);
 
 						gt[temp[0]].push_back((temp[1]+k)%(2*k));
 						gt[temp[1]].push_back((temp[0]+k)%(2*k));
 					}
 				}
 		for(i=0;i<k;i++)
 			if(ans[i]==1)
 			{
 				g[i+k].push_back(i);
 				gt[i].push_back(i+k);
 			}
 			else if(ans[i]==0)
 			{
 				gt[i+k].push_back(i);
 				g[i].push_back(i+k);
 			}
 		for(i=0;i<2*k;i++)
 		{
 			used[i]=false;
 			comp[i]=-1;
 		}
 		for(i=0;i<2*k;i++)
 			if(!used[i])
 				dfs1(i);
 		for (i=0, j=0; i<2*k; ++i) 
 			if (comp[order[2*k-i-1]] == -1)
 				dfs2 (order[2*k-i-1], j++);
 		for (i=0; i<k; ++i)
 			if (comp[i] == comp[i+k])
 				bad=true;
 		printf("Case #%d: %sPOSSIBLE\n",ts,bad?"IM":"");
 		if(!bad)
 		{
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					if(s[i][j]=='-' || s[i][j]=='|')
 					{
 						if(ans[ind[i][j]]!=-1)
 							s[i][j]=ans[ind[i][j]]?'|':'-';
 						else
 							s[i][j]=comp[ind[i][j]]>comp[ind[i][j]+k]?'|':'-';
 					}
 			for(i=0;i<n;i++)
 				puts(s[i]);
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					v[i][j].clear();
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					if(s[i][j]=='|')
 					{
 						left=process(i,j,-1,0);
 						right=process(i,j,1,0);
 						if(!left || !right)
 							throw;
 					}
 					else if(s[i][j]=='-')
 					{
 						left=process(i,j,0,-1);
 						right=process(i,j,0,1);
 						if(!left || !right)
 							throw;
 					}
 			for(i=0;i<n;i++)
 				for(j=0;j<m;j++)
 					if(s[i][j]=='.' && v[i][j].empty())
 						throw;
 		}
 	}
 	return 0;
 }