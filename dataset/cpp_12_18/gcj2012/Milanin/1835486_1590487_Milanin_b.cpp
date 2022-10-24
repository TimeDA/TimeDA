#pragma comment (linker, "/STACK:100000000")
 #include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 3100
 #define K 10010
 int p1[4*N*N], m1[4*N*N], p2[4*N*N], m2[4*N*N];
 int fnd1(int i) { return p1[i]=p1[i]==i?i:fnd1(p1[i]); }
 void uni1(int i, int j)
 {
 	i=fnd1(i); j=fnd1(j);
 	m1[i]|=m1[j];
 	p1[j]=i;
 }
 int fnd2(int i) { return p2[i]=p2[i]==i?i:fnd2(p2[i]); }
 void uni2(int i, int j)
 {
 	i=fnd2(i); j=fnd2(j);
 	m2[i]|=m2[j];
 	p2[j]=i;
 }
 int n, x[K], y[K], dx[]={1, 1, -1, -1, 0, 0}, dy[]={0, 1, 0, -1, 1, -1};
 char u[2*N][2*N];
 int get(int x, int y)
 {
 	if(x==0 && y==0) return 6;
 	if(x==n-1 && y==0) return 7;
 	if(x==0 && y==n-1) return 8;
 	if(x==n-1 && y==2*n-2) return 9;
 	if(x==2*n-2 && y==n-1) return 10;
 	if(x==2*n-2 && y==2*n-2) return 11;
 	if(x==0 && y<n) return 0;
 	if(x<n && y==0) return 1;
 	if(x-y==n-1 && y<n) return 2;
 	if(x<n && y-x) return 3;
 	if(x==2*n-2 && y>=n) return 4;
 	if(x>=n && y==2*n-2) return 5;
 	return -1;
 }
 int cnt(int n)
 {
 	int r;
 	for(r=0; n; r+=n&1, n>>=1);
 	return r;
 }
 int main()
 {
 	int ts, tst, f, q, i, j, k, t, xx, yy, f1, f2, f3, w[6];
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		scanf("%d%d", &n, &q);
 		for(i=0; i<2*n; i++)
 			for(j=0; j<2*n; u[i][j]=0, p1[i*2*n+j]=i*2*n+j, m1[i*2*n+j]=0, p2[i*2*n+j]=i*2*n+j, m2[i*2*n+j]=0, j++);
 		for(i=0; i<q; scanf("%d%d", &x[i], &y[i]), x[i]--, y[i]--, i++);
 		f1=q; f2=q; f3=q;
 		w[0]=0;
 		w[1]=n-1;
 		w[2]=(n-1)*2*n;
 		w[3]=(n-1)*2*n+2*n-2;
 		w[4]=(2*n-2)*2*n+n-1;
 		w[5]=(2*n-2)*2*n+2*n-2;
 		for(i=0; i<q; i++)
 		{
 			u[x[i]][y[i]]=1;
 			t=get(x[i], y[i]);
 			if(t>=0 && t<6) m1[x[i]*2*n+y[i]]=1<<t;
 			for(k=0; k<6; k++)
 			{
 				xx=x[i]+dx[k];
 				yy=y[i]+dy[k];
 				if(xx>=0 && xx<=2*n-2 && yy>=0 && yy<=2*n-2 && u[xx][yy]) uni1(x[i]*2*n+y[i], xx*2*n+yy);
 			}
 			if(f2==q)
 			{
 				for(j=0; j<6; j++)
 					for(k=j+1; k<6; k++)
 						if(fnd1(w[j])==fnd1(w[k])) f2=i;
 			}
 			if(f3==q && cnt(m1[fnd1(x[i]*2*n+y[i])])>=3) f3=i;
 		}
 		for(i=0; i<2*n-1; i++)
 			for(j=0; j<2*n-1; j++)
 				if(abs(i-j)<n && !u[i][j])
 				{
 					t=get(i, j);
 					k=fnd2(i*2*n+j);
 					if(t!=-1) m2[k]=1;
 					for(k=0; k<6; k++)
 					{
 						xx=i+dx[k];
 						yy=j+dy[k];
 						if(xx>=0 && xx<=2*n-2 && yy>=0 && yy<=2*n-2 && abs(xx-yy)<n && !u[xx][yy]) uni2(i*2*n+j, xx*2*n+yy);
 					}
 				}
 		for(i=0; i<2*n-1; i++)
 			for(j=0; j<2*n-1; j++)
 				if(abs(i-j)<n && !u[i][j])
 					if(m2[fnd2(i*2*n+j)]==0) f1=q-1;
 		for(i=q-1; i>=0; i--)
 		{
 			f=0;
 			for(k=0; k<6; k++)
 			{
 				xx=x[i]+dx[k];
 				yy=y[i]+dy[k];
 				if(xx>=0 && xx<=2*n-2 && yy>=0 && yy<=2*n-2 && abs(xx-yy)<n && !u[xx][yy]) 
 					if(m2[fnd2(xx*2*n+yy)]==0) f=1;
 			}
 			u[x[i]][y[i]]=0;
 			t=get(x[i], y[i]);
 			k=fnd2(x[i]*2*n+y[i]);
 			if(t!=-1) m2[k]=1;
 			for(k=0; k<6; k++)
 			{
 				xx=x[i]+dx[k];
 				yy=y[i]+dy[k];
 				if(xx>=0 && xx<=2*n-2 && yy>=0 && yy<=2*n-2 && abs(xx-yy)<n && !u[xx][yy]) uni2(x[i]*2*n+y[i], xx*2*n+yy);
 			}
 			k=fnd2(x[i]*2*n+y[i]);
 			if(f==1 && m2[k]==1) f1=i;
 		}
 		k=min(min(f1, f2), f3);
 		if(k==q) printf("none\n");
 		else if(f1==k && f2==k && f3==k) printf("bridge-fork-ring in move %d\n", k+1);
 		else if(f1==k && f2==k) printf("bridge-ring in move %d\n", k+1);
 		else if(f1==k && f3==k) printf("fork-ring in move %d\n", k+1);
 		else if(f2==k && f3==k) printf("bridge-fork in move %d\n", k+1);
 		else if(f1==k) printf("ring in move %d\n", k+1);
 		else if(f2==k) printf("bridge in move %d\n", k+1);
 		else if(f3==k) printf("fork in move %d\n", k+1);
 		else throw;
 	}
 	return 0;
 }