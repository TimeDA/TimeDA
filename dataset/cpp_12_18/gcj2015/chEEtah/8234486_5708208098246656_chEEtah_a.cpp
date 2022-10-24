#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 char s[200][200];
 
 int n, m;
 
 int di[200], dj[200];
 
 bool bad(int i, int j)
 {
 	if (s[i][j] == '.') return false;
 	int ii = di[s[i][j]], jj = dj[s[i][j]];
 	while(1)
 	{
 		i += ii; j += jj;
 		if (i < 0 || j < 0 || i >= n || j >= m) break;
 		if (s[i][j] != '.') return false;
 	}
 	return true;
 }
 
 int main()
 {
 	di['<'] = di['>'] = 0; di['^'] = -1; di['v'] = 1;
 	dj['^'] = dj['v'] = 0; dj['<'] = -1; dj['>'] = 1;
 
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 		
 		scanf("%d %d", &n, &m);
 		for(int i = 0; i < n; i++) scanf("%s", s[i]);
 
 		int res = 0;
 		for(int i = 0; i < n && res != -1; i++) 
 			for(int j = 0; j < m && res != -1; j++)
 				if (bad(i, j))
 				{
 					res++;
 					// check impossible
 					bool ok = false;
 					for(int k = 0; k < n; k++) 
 						if (k != i && s[k][j] != '.') { ok = true; break;}
 
 					if (!ok)
 					for(int k = 0; k < m; k++) 
 						if (k != j && s[i][k] != '.') { ok = true; break;}
 
 					if (!ok) res = -1;
 				}
 		
 		if (res == -1) puts("IMPOSSIBLE"); else printf("%d\n", res);
 	}
 	return 0;
 }