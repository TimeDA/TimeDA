#include <stdio.h>
 #include <string.h>
 #include <vector>
 
 using namespace std;
 
 #define MAXS (1005)
 #define MAXC (128)
 #define MAXV (36)
 
 int T;
 
 int K;
 char S[MAXS];
 
 int L;
 int lsmap[MAXC];
 
 vector <int> edge[MAXV];
 int adjm[MAXV][MAXV]; // adjacency matrix
 int indeg[MAXV];
 
 int sol; // only for small test case
 
 int add_edge(int a, int b)
 {
 	if(!adjm[a][b])
 	{
 		adjm[a][b] = 1;
 		edge[a].push_back(b);
 		++indeg[b];
 
 		return 1;
 	}
 
 	return 0;
 }
 
 int VR[MAXV];
 int vrit;
 int vb;
 
 int reachable(int a)
 {
 	if(a == vb)
 		return 1;
 
 	VR[a] = vrit;
 
 	int sz = edge[a].size();
 	for(int i = 0; i < sz; ++i)
 	{
 		int c = edge[a][i];
 		if(VR[c] != vrit)
 		{
 			if(reachable(c))
 				return 1;
 		}
 	}
 
 	return 0;
 }
 
 int main()
 {
 	lsmap['o'] = 26;
 	lsmap['i'] = 27;
 	lsmap['e'] = 28;
 	lsmap['a'] = 29;
 	lsmap['s'] = 30;
 	lsmap['t'] = 31;
 	lsmap['b'] = 32;
 	lsmap['g'] = 33;
 
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i, j;
 
 		scanf("%d %s", &K, S);
 		L = strlen(S);
 
 		int en = 0;
 
 		for(i = 1; S[i]; ++i)
 		{
 			int a1 = S[i - 1] - 'a';
 			int b1 = S[i] - 'a';
 			int a2 = lsmap[(int) S[i - 1]];
 			int b2 = lsmap[(int) S[i]];
 
 			en += add_edge(a1, b1);
 			if(b2 > 0)
 				en += add_edge(a1, b2);
 
 			if(a2 > 0)
 			{
 				en += add_edge(a2, b1);
 				if(b2 > 0)
 					en += add_edge(a2, b2);
 			}
 		}
 
 //		printf(" #edges %d\n", en);
 
 		int sol = en; // final answer = #edges + #tries (now only #edges)
 
 		while(en > 0)
 		{
 			++sol; // #tries
 
 			int st = -1;
 			for(i = 0; i < 34; ++i)
 			{
 				if((int) edge[i].size() > indeg[i])
 				{
 					st = i;
 					break;
 				}
 			}
 
 			if(st == -1)
 			{
 				for(i = 0; i < 33 && edge[i].size() == 0; ++i);
 
 				st = i;
 			}
 
 //			printf("st = %d [%c] initially\n", st, ((st < 26) ? st + 'a' : st + '0' - 26));
 
 			while(1)
 			{
 				int sz = edge[st].size();
 				for(i = 0; i < sz; ++i)
 				{
 					int a = edge[st][i];
 
 					edge[st][i] = edge[st][sz - 1];
 					edge[st].pop_back();
 					--indeg[a];
 
 					++vrit;
 					vb = st;
 					if(reachable(a))
 					{
 						st = a;
 						--en;
 						break;
 					}
 
 					edge[st].push_back(edge[st][i]);
 					edge[st][i] = a;
 					++indeg[a];
 				}
 
 				if(i == sz)
 				{
 					if(sz > 0)
 					{
 						int a = edge[st][sz - 1];
 						edge[st].pop_back();
 						--indeg[a];
 
 						st = a;
 						--en;
 					}
 					else
 						break;
 				}
 			}
 		}
 
 		printf("Case #%d: %d\n", tt, sol);
 
 		for(i = 0; i < 34; ++i)
 			edge[i].clear();
 		memset(adjm, 0, sizeof(adjm));
 	}
 
 	return 0;
 }
