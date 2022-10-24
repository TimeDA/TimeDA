#include <stdio.h>
 #include <algorithm>
 using namespace std;
 #define N 110
 int a[N][N], h[N], v[N];
 int main()
 {
 	int t, ts, i, j, r, c, f;
 	for(scanf("%d", &ts), t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		scanf("%d%d", &r, &c);
 		for(i=0; i<r; h[i]=0, i++);
 		for(i=0; i<c; v[i]=0, i++);
 		for(i=0; i<r; i++)
 			for(j=0; j<c; scanf("%d", &a[i][j]), h[i]=max(h[i], a[i][j]), v[j]=max(v[j], a[i][j]), j++);
 		for(f=1, i=0; i<r; i++)
 			for(j=0; j<c; f&=a[i][j]==min(h[i], v[j]), j++);
 		printf("%s\n", f?"YES":"NO");
 	}
 	return 0;
 }