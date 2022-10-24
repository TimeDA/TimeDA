#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 char s[1000000];
 map<string, int> w2i;
 vector<int> a[20];
 
 int CNT;
 int L[2][20000];
 
 int nw, n;
 
 int getID(string s)
 {
 	if (w2i.count(s)) return w2i[s];
 	nw++;
 	w2i[s] = nw - 1;
 	return nw - 1;
 }
 
 int main()
 {
 	int nt;
 	gets(s);
 	sscanf(s, "%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		w2i.clear();
 		nw = 0;
 
 		gets(s);
 		sscanf(s, "%d", &n);
 		for(int i = 0; i < n; i++)
 		{
 			a[i].clear();
 			gets(s);
 			istringstream str(s);
 			string word;
 			while(str >> word)
 			{
 				a[i].push_back(getID(word));
 			}
 		}
 		
 		int res = 1000000;
 		int all = 1 << n;
 		for(int mask = 2; mask < all; mask += 4)
 		{
 			int cur = 0;
 			CNT++;
 
 			for(int i = 0; i < n; i++)
 			{
 				int lan = 0;
 				if (mask & (1 << i)) lan = 1;
 
 				for(int j = 0; j < a[i].size(); j++) L[lan][a[i][j]] = CNT;
 			}
 
 			for(int i = 0; i < nw; i++) if (L[0][i] == CNT && L[1][i] == CNT) cur++;
 
 			res = min(res, cur);
 		}
 		cout << res << endl;
 	}
 	return 0;
 }