#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 #define N 15
 #define L 1000000
 using namespace std;
 int r, c, l, bi, bj, fi[N*N], fj[N*N], f, u[N][N], di[]={1, 0, 0}, dj[]={0, -1, 1};
 char m[N][N];
 queue <int> q;
 set <long long> s;
 void upd(int i, int j, int v)
 {
 	if(i>=0 && i<r && j>=0 && j<c && m[i][j]!='#' && v<u[i][j]) { q.push(i); q.push(j); u[i][j]=v; }
 }
 int bfs()
 {
 	int i, j, k, l;
 	for(i=0; i<r; i++)
 		for(j=0; j<c; u[i][j]=N*N, j++);
 	for(l=0, upd(bi, bj, 0); !q.empty(); )
 		for(l++, i=q.front(), q.pop(), j=q.front(), q.pop(), k=0; k<3; upd(i-di[k], j-dj[k], u[i][j]+1), k++);
 	return l;
 }
 bool sol()
 {
 	int i;
 	for(i=0; i<f; i++)
 		if(fi[i]!=bi || fj[i]!=bj) return 0;
 	return 1;
 }
 bool can()
 {
 	int i;
 	for(i=0; i<f; i++)
 		if(u[fi[i]][fj[i]]==N*N) return 0;
 	return 1;
 }
 long long hash()
 {
 	int i;
 	long long h;
 	for(h=0, i=0; i<f; h=h*257+fi[i], h=h*257+fj[i], i++);
 	return h;
 }
 bool rec(int &i, int h)
 {
 	if(sol()) return 1;
 	if(!can()) return 0;
 	if(i>=L || h>64) return 0;
 	int j, k;
 	long long w;
 	w=hash();
 	if(s.find(w)!=s.end()) return 0;
 	s.insert(w);
 	for(k=0; k<3; k++)
 	{
 		i++;
 		w=0;
 		for(j=0; j<f; j++)
 			if(m[fi[j]+di[k]][fj[j]+dj[k]]!='#') { w|=1LL<<(long long)j; fi[j]+=di[k]; fj[j]+=dj[k]; }
 		if(w)
 		{
 			if(rec(i, h+1)) return 1;
 			for(j=0; j<f; j++)
 				if((w>>j)&1) { fi[j]-=di[k]; fj[j]-=dj[k]; }
 		}
 	}
 	return 0;
 }
 int main()
 {
 	int ts, tst, i, j, b;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d:\n", ts);
 		for(scanf("%d%d", &r, &c), i=0; i<r; scanf("%s", m[i]), i++);
 		for(b=0; b<10; b++)
 		{
 			for(bi=-1, i=0; i<r; i++)
 				for(j=0; j<c; j++)
 					if(m[i][j]==b+'0') { bi=i; bj=j; }
 			if(bi!=-1)
 			{
 				printf("%d: %d", b, bfs());
 				for(f=0, i=0; i<r; i++)
 					for(j=0; j<c; j++)
 						if(u[i][j]<N*N) { fi[f]=i; fj[f]=j; f++; }
 				i=0;
 				s.clear();
 				if(rec(i, 0)) printf(" Lucky\n");
 				else printf(" Unlucky\n");
 			}
 		}
 	}
 	return 0;
 }
 /*
 10
 10 10
 ##########
 #........#
 ########.#
 #........#
 #.########
 #........#
 ########.#
 #........#
 #01234567#
 ##########
 */