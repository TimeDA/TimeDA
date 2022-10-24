#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 using namespace std;
 #define N 20
 #define K 1010
 #define L 11
 #define M (1<<16)
 #define mod 1000000007
 int h[N], g[N][K];
 char w[N][K][L], s[K*(L+1)];
 int v1[N*K], v2[N*K];
 int n, hs[M+1000], h1[M+1000], h2[M+1000], h12[M+1000], s1, s2, s12, r;
 int fnd(int x)
 {
 	int i;
 	for(i=x%M; hs[i] && hs[i]!=x; i++);
 	if(!hs[i]) hs[i]=x;
 	return i;
 }
 void rec(int i)
 {
 	if(i==n)
 	{
 		r=min(r, s1+s2-s12);
 	}
 	else
 	{
 		int j;
 		if(i!=1)
 		{
 			for(j=0; j<h[i]; j++)
 			{
 				int k=fnd(g[i][j]);
 				if(!h1[k]) s1++;
 				if(!h12[k]) s12++; 
 				h1[k]++; 
 				h12[k]++;
 			}
 			rec(i+1);
 			for(j=0; j<h[i]; j++)
 			{
 				int k=fnd(g[i][j]);
 				h1[k]--; 
 				h12[k]--;
 				if(!h1[k]) s1--;
 				if(!h12[k]) s12--;
 			}
 		}
 		if(i!=0)
 		{
 			for(j=0; j<h[i]; j++)
 			{
 				int k=fnd(g[i][j]);
 				if(!h2[k]) s2++;
 				if(!h12[k]) s12++; 
 				h2[k]++; 
 				h12[k]++;
 			}
 			rec(i+1);
 			for(j=0; j<h[i]; j++)
 			{
 				int k=fnd(g[i][j]);
 				h2[k]--; 
 				h12[k]--;
 				if(!h2[k]) s2--;
 				if(!h12[k]) s12--;
 			}
 		}
 	}
 }
 void solve()
 {
 	int i, j, k, m;
 	for(i=0; i<M+1000; i++)
 	{
 		hs[i]=0;
 		h1[i]=0;
 		h2[i]=0;
 		h12[i]=0;
 	}
 	gets(s);
 	sscanf(s, "%d", &n);
 	for(i=0; i<n; i++)
 	{
 		gets(s);
 		h[i]=0;
 		int x=1;
 		for(j=0; s[j]; j++)
 		{
 			if(s[j]!=' ') x=((long long)x*123771+s[j])%mod;
 			else { g[i][h[i]]=x; x=1; h[i]++; }
 		}
 		g[i][h[i]]=x;
 		h[i]++;
 	}
 	r=1000000;
 	rec(0);
 	printf("%d\n", r);
 }
 int main()
 {
 	int tst;
 	gets(s);
 	sscanf(s, "%d", &tst);
 	long long tm=clock();
 	for(int ts=1; ts<=tst; ts++)
 	{
 		fprintf(stderr, "%d\n", ts);
 		printf("Case #%d: ", ts);
 		solve();
 	}
 	fprintf(stderr, "time: %lf\n", (clock()-tm)*0.001);
 	return 0;
 }