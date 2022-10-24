#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <iostream>
 #include <map>
 #include <set>
 
 using namespace std;
 
 int S, m, T;
 int nt;
 
 int a[6001][6001];
 char v[6001][6001];
 
 vector<int> cx, cy;
 
 int mark;
 
 void go(int x, int y)
 {
 	if (x < 1 || y < 1 || x >= 2 * S || y >= 2 * S) return;
 	if (x - y >= S) return;
 	if (y - x >= S) return;
 
 	if (!a[x][y] || a[x][y] > T) return;
 	if (v[x][y] & mark) return;
 
 	v[x][y] |= mark;
 
 	go(x, y + 1);
 	go(x + 1, y);
 	go(x + 1, y + 1);
 
 	go(x, y - 1);
 	go(x - 1, y);
 	go(x - 1, y - 1);
 }
 
 
 void go2(int x, int y)
 {
 	if (x < 1 || y < 1 || x >= 2 * S || y >= 2 * S) return;
 	if (x - y >= S) return;
 	if (y - x >= S) return;
 
 	if (a[x][y] && a[x][y] <= T) return;
 	if (v[x][y]) return;
 
 	v[x][y] = 1;
 
 	go2(x, y + 1);
 	go2(x + 1, y);
 	go2(x + 1, y + 1);
 
 	go2(x, y - 1);
 	go2(x - 1, y);
 	go2(x - 1, y - 1);
 }
 
 int count(int x)
 {
 	int res = 0;
 	while(x)
 	{
 		x &= x - 1;
 		res++;
 	}
 	return res;
 }
 
 int check()
 {
 	int res = 0;
 
 	// check bridge
 
 	for(int i = 0; i < 6; i++)
 	{
 		memset(v, 0, sizeof v);
 		mark = 1;
 		go(cx[i], cy[i]);
 		for(int j = i + 1; j < 6; j++) if (v[cx[j]][cy[j]]) res |= 1;
 	}
 
 	// check fork
 
 	memset(v, 0, sizeof v);
 	for(int i = 0; i < S - 2; i++)
 	{
 		mark = 1;	go(1, i + 2);
 		mark = 2; go(2 + i, S + 1 + i);
 		mark = 4; go(S + 1 + i, 2 * S - 1);
 
 		mark = 8; go(2 * S - 1, S + 1 + i);
 		mark = 16; go(S + 1 + i, 2 + i);
 		mark = 32; go(i + 2, 1);
 	}
 
 	for(int x = 1; x < 2 * S; x++)
 		for(int y = 1; y < 2 * S; y++) if (count(v[x][y]) > 2) res |= 2;
 
 	// check ring
 
 	memset(v, 0, sizeof v);
 	for(int i = 0; i < S - 2; i++)
 	{
 		go2(1, i + 2);
 		go2(2 + i, S + 1 + i);
 		go2(S + 1 + i, 2 * S - 1);
 
 		go2(2 * S - 1, S + 1 + i);
 		go2(S + 1 + i, 2 + i);
 		go2(i + 2, 1);
 	}
 	for(int i = 0; i < 6; i++) go2(cx[i], cy[i]);
 
 	for(int x = 1; x < 2 * S; x++)
 			for(int y = 1; y < 2 * S; y++)
 			{
 				if (x - y >= S) continue;
 				if (y - x >= S) continue;
 
 				if (!a[x][y] || a[x][y] > T)
 				{
 					if (!v[x][y]) res |= 4;
 				}
 
 				if (a[x][y] && a[x][y] <= T)
 				{
 					// perhaps (x,y) was put after ring formation?
 					int last = 0;
 
 					last = max(last, a[x - 1][y]); if (!a[x - 1][y]) continue;
 					last = max(last, a[x + 1][y]); if (!a[x + 1][y]) continue;
 					last = max(last, a[x][y - 1]); if (!a[x - 1][y - 1]) continue;
 					last = max(last, a[x][y + 1]); if (!a[x][y - 1]) continue;
 					last = max(last, a[x - 1][y - 1]); if (!a[x][y + 1]) continue;
 					last = max(last, a[x + 1][y + 1]); if (!a[x + 1][y + 1]) continue;
 
 					if (last > T) continue;
 
 					if (last < a[x][y]) res |= 4;
 				}
 			}
 
 	return res;
 }
 
 //extern ostream cerr;
 
 int main()
 {
 	scanf("%d", &nt);
 	
 	for(int tt = 1; tt <= nt; tt++)
 	{	
 		printf("Case #%d: ", tt);
 		
 		scanf("%d %d", &S, &m);
 		
 		cx.clear(); cy.clear();
 		cx.push_back(1); cy.push_back(1);
 		cx.push_back(1); cy.push_back(S);
 		cx.push_back(S); cy.push_back(1);
 		cx.push_back(S); cy.push_back(2 * S - 1);
 		cx.push_back(2 * S - 1); cy.push_back(S);
 		cx.push_back(2 * S - 1); cy.push_back(2 * S - 1);
 
 		memset(a, 0, sizeof a);
 		for(int i = 0; i < m; i++)
 		{
 			int x, y;
 			scanf("%d %d", &x, &y);
 			a[x][y] = i + 1;
 		}
 
 		int L = 0, R = m + 1;
 		while(L != R - 1)
 		{
 			T = (L + R) / 2;
 			if (!check()) L = T; else R = T;
 		}
 		//R = 1; T = 1;
 		//while(!check() && R < m) T++, R++;
 
 		if (R == m + 1) puts("none");
 		else
 		{
 			T = R;
 			int res = check();
 			switch(res)
 			{
 			case 0: puts("none"); break;
 
 			case 1: printf("bridge in move %d\n", T); break;
 			case 2: printf("fork in move %d\n", T); break;
 			case 4: printf("ring in move %d\n", T); break;
 
 			case 3: printf("bridge-fork in move %d\n", T); break;
 			case 5: printf("bridge-ring in move %d\n", T); break;
 			case 6: printf("fork-ring in move %d\n", T); break;
 			case 7: printf("bridge-fork-ring in move %d\n", T); break;
 			}
 		}
 		cerr << tt << " done.\n";
 	}
 	
 	return 0;
 }
