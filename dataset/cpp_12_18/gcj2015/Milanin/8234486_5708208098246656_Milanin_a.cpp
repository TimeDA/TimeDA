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
 #define N 110
 char m[N][N];
 void solve()
 {
 	int i, j, k, l, r, c, di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
 	scanf("%d%d", &r, &c);
 	for(i=0; i<r; scanf("%s", m[i]), i++);
 	int a=0;
 	for(i=0; i<r; i++)
 		for(j=0; j<c; j++)
 			if(m[i][j]!='.')
 			{
 				if(m[i][j]=='^') k=0;
 				else if(m[i][j]=='v') k=1;
 				else if(m[i][j]=='<') k=2;
 				else k=3;
 				int ii=i+di[k];
 				int jj=j+dj[k];
 				int f=0;
 				for(; ii>=0 && ii<r && jj>=0 && jj<c; ii+=di[k], jj+=dj[k])
 				{
 					if(m[ii][jj]!='.') { f=1; break; }
 				}
 				if(!f)
 				{
 					a++;
 					f=0;
 					for(k=0; k<4; k++)
 					{
 						int ii=i+di[k];
 						int jj=j+dj[k];
 						for(; ii>=0 && ii<r && jj>=0 && jj<c; ii+=di[k], jj+=dj[k])
 						{
 							if(m[ii][jj]!='.') { f++; break; }
 						}
 					}
 					if(!f) { printf("IMPOSSIBLE\n"); return; }
 				}
 			}
 	printf("%d\n", a);
 }
 int main()
 {
 	int tst;
 	scanf("%d", &tst);
 	for(int ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		solve();
 	}
 	return 0;
 }