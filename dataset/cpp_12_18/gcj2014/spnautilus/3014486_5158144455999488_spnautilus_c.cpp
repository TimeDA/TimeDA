#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXR (504)
 #define MAXC (104)
 #define MAXND (100100)
 #define MAXE (300000)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N, L;
 int R, C;
 
 int B[MAXR][MAXC];
 int bn;
 
 int V[MAXND];
 VP edge[MAXND];
 int from[MAXND];
 int rit;
 
 int cap[MAXE];
 int flow[MAXE];
 int sume[MAXE];
 int en;
 
 int source, sink;
 
 int run()
 {
 	int f = 0;
 	int i;
 
 	while(1)
 	{
 /*
 		printf("\nLoop %d\n", f);
 
 		printf("Edges\n");
 		for(i = 0; i < 2*N; ++i)
 		{
 			int sz = edge[i].size();
 			for(j = 0; j < sz; ++j)
 			{
 				int e = edge[i][j].first;
 				printf("%d -> %d   e %d  flow %d\n", i, sume[e] - i, e, flow[e]);
 			}
 		}
 		printf("\n");
 //*/
 
 		queue <int> Q;
 
 		++rit;
 
 		Q.push(source);
 		V[source] = rit;
 		from[source] = -1;
 
 		int r = -1;
 		while(!Q.empty() && r == -1)
 		{
 			int p = Q.front();
 			Q.pop();
 
 //			printf("pop %d\n", p);
 
 			int sz = edge[p].size();
 			for(i = 0; i < sz; ++i)
 			{
 				PII ee = edge[p][i];
 				int e = ee.first;
 				int s = ee.second;
 
 //				printf("%d -> %d,%d\n", p, e, s);
 
 				if((s == 0 && cap[e]) || (s == 1 && flow[e]))
 				{
 					int a = sume[e] - p;
 //					printf("%d -> %d\n", p, a);
 
 					if(a == sink)
 					{
 						from[sink] = e;
 						r = sink;
 						break;
 					}
 
 					if(V[a] != rit)
 					{
 						V[a] = rit;
 						from[a] = e;
 						Q.push(a);
 					}
 				}
 			}
 		}
 
 		if(r == -1)
 			break;
 
 //		printf("\nr %d\n", r);
 
 		while(from[r] != -1)
 		{
 //			printf("%d -- %d\n", r, from[r]);
 			int e = from[r];
 			int rr = sume[e] - r;
 
 			cap[e] = !cap[e];
 			flow[e] = !flow[e];
 
 			r = rr;
 		}
 
 //		printf("end %d\n", r);
 
 		++f;
 	}
 
 //	printf("f %d\n", f);
 
 	return f;
 }
 
 void add_edge(int a, int b)
 {
 	edge[a].push_back(PII(en, 0));
 	edge[b].push_back(PII(en, 1));
 	cap[en] = 1;
 	flow[en] = 0;
 	sume[en] = a + b;
 	++en;
 }
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i;
 		scanf("%d %d %d", &C, &R, &N);
 
 		memset(B, 0, sizeof(B));
 
 		for(i = 0; i < N; ++i)
 		{
 			int r1, c1, r2, c2;
 			scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
 
 			for(int r = r1; r <= r2; ++r)
 			{
 				for(int c = c1; c <= c2; ++c)
 				{
 					B[r][c] = 1;
 				}
 			}
 		}
 
 		int rc = R * C;
 		source = rc * 2;
 		sink = source + 1;
 		en = 0;
 		for(i = 0; i <= sink; ++i)
 			edge[i].clear();
 
 		for(int r = 0; r < R; ++r)
 		{
 			for(int c = 0; c < C; ++c)
 			{
 				if(B[r][c] == 1)
 					continue;
 
 				add_edge(r * C + c, r * C + c + rc);
 
 				if(r == 0)
 					add_edge(source, r * C + c);
 
 				if(r + 1 == R)
 					add_edge(r * C + c + rc, sink);
 
 				if(r + 1 < R && B[r + 1][c] == 0)
 				{
 					add_edge(r * C + c + rc, (r+1) * C + c);
 					add_edge((r+1) * C + c + rc, r * C + c);
 				}
 
 				if(c + 1 < C && B[r][c + 1] == 0)
 				{
 					add_edge(r * C + c + rc, r * C + c+1);
 					add_edge(r * C + c+1 + rc, r * C + c);
 				}
 			}
 		}
 
 		int sol = run();
 
 		printf("Case #%d: %d\n", TT, sol);
 	}
 
 	return 0;
 }
