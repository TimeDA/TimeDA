#include <algorithm>
 #include <stdio.h>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 using namespace std;
 #define R 510
 #define C 110
 #define N 100100
 #define K 1000010
 #define M 1000001000
 int n, l, e[2*K], a[2*K], u[N], p[N];
 vector <int> m[N];
 queue <int> q;
 int dfs(int i, int l, int f)
 {
 	int j, k, r;
 	if(!f || i==l) return f;
 	for(r=0; p[i]<m[i].size(); p[i]++)
 		if(u[e[j=m[i][p[i]]]]==u[i]+1) { k=dfs(e[j], l, min(f, a[j])); a[j]-=k; a[j^1]+=k; f-=k; r+=k; if(!f) break; }
 	return r;
 }
 bool bfs(int b, int l)
 {
 	int i, j;
 	for(i=0; i<n; u[i]=0, p[i]=0, i++);
 	for(q.push(b), u[b]=1; !q.empty(); )
 		for(i=q.front(), q.pop(), j=0; j<m[i].size(); j++)
 			if(a[m[i][j]] && !u[e[m[i][j]]]) { u[e[m[i][j]]]=u[i]+1; q.push(e[m[i][j]]); }
 	return u[l]>0;
 }
 int mxfl(int b, int e)
 {
 	int f;
 	for(f=0; bfs(b, e); f+=dfs(b, e, M));
 	return f;
 }
 void add(int i, int j, int c)
 {
 	e[l]=j; a[l]=c; m[i].push_back(l++);
 	e[l]=i; a[l]=0; m[j].push_back(l++);
 }
 int g[R][C];
 int main()
 {
 	int nts;
 	scanf("%d", &nts);
 	for(int ts=1; ts<=nts; ts++)
 	{
 		int di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
 		printf("Case #%d: ", ts);
 		int r, c, i, j;
 		scanf("%d%d%d", &c, &r, &n);
 		for(i=0; i<r; i++)
 			for(j=0; j<c; g[i][j]=0, j++);
 		for(; n--; )
 		{
 			int i1, j1, i2, j2;
 			scanf("%d%d%d%d", &j1, &i1, &j2, &i2);
 			for(i=i1; i<=i2; i++)
 				for(j=j1; j<=j2; g[i][j]=1, j++);
 		}
 		l=0;
 		for(i=0; i<r*c*2+2; m[i].clear(), i++);
 		for(i=0; i<r; i++)
 			for(j=0; j<c; j++)
 				if(!g[i][j])
 				{
 					add((i*c+j)*2, (i*c+j)*2+1, 1);
 					for(int k=0; k<4; k++)
 					{
 						int ii=i+di[k], jj=j+dj[k];
 						if(ii>=0 && ii<r && jj>=0 && jj<c && !g[ii][jj]) add((i*c+j)*2+1, (ii*c+jj)*2, 1);
 					}
 				}
 		for(j=0; j<c; j++)
 		{
 			if(!g[0][j]) add(r*c*2, j*2, 1);
 			if(!g[r-1][j]) add(((r-1)*c+j)*2+1, r*c*2+1, 1);
 		}
 		n=r*c*2+2;
 		printf("%d\n", mxfl(r*c*2, r*c*2+1));
 	}
 	return 0;
 }
