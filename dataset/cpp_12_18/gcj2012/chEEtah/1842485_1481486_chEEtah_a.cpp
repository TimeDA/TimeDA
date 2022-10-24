#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 
 using namespace std;
 
 int n;
 int nt;
 
 int d[10000], l[10000], D;
 
 int done[10001];
 
 int main()
 {
 	scanf("%d", &nt);
 	
 	for(int tt = 1; tt <= nt; tt++)
 	{	
 		printf("Case #%d: ", tt);
 		
 		scanf("%d", &n);
 		for(int i = 0; i <n; i++) scanf("%d %d", &d[i], &l[i]);
 		scanf("%d", &D);
 		d[n] = D;
 		l[n] = 0;
 		n++;
 		
 		memset(done, -1, sizeof done);
 
 		done[0] = 0;
 
 		for(int i = 0; i < n; i++)
 			if (done[i] != -1)
 			{
 				int j = i + 1;
 				int to = d[i] + (d[i] - done[i]);
 
 				while(j < n)
 				{
 					if (d[j] > to) break;
 
 					int from = max(d[j] - l[j], d[i]);
 					if (done[j] == -1 || done[j] > from) done[j] = from;
 
 					j++;
 				}
 			}
 
 		if (done[n - 1] != -1) puts("YES"); else puts("NO");
 	}
 	
 	return 0;
 }
