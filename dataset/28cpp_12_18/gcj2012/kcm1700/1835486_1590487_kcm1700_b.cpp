#include <stdio.h>
 #include <vector>
 #include <string.h>
 #include <algorithm>
 
 using namespace std;
 
 int bsize, m;
 int barea;
 int maxCoord;
 
 int isRing[20000];
 bool isBridge;
 bool isFork;
 
 int moves[20000][2];
 
 int board[6002][8192];
 int connection[6002][8192];
 
 int bridgeCond[1<<6], forkCond[1<<6];
 
 inline int isCorner(int x, int y)
 {
 	if(x == 1 && y == 1) return 1;
 	if(x == 1 && y == bsize) return 2;
 	if(x == bsize && y == 1) return 3;
 	if(x == bsize && y == bsize*2-1) return 4;
 	if(x == bsize*2-1 && y == bsize) return 5;
 	if(x == bsize*2-1 && y == bsize*2-1) return 6;
 	return false;
 }
 
 inline int isEdge(int x, int y)
 {
 	if(isCorner(x,y)) return 0;
 	if(x == 1) return 8;
 	if(y == 1) return 9;
 	if(x-y == bsize-1) return 10;
 	if(y-x == bsize-1) return 11;
 	if(x == bsize*2-1) return 12;
 	if(y == bsize*2-1) return 13;
 	return 0;
 }
 
 inline bool isInside(int x, int y)
 {
 	if(x >= 1 && y >= 1)
 	{
 		if(x <= maxCoord && y <= maxCoord)
 		{
 			if(x-y <= bsize-1 && x-y >= 1-bsize)
 			{
 				return true;
 			}
 		}
 	}
 	return false;
 }
 
 int q[36000000];
 const int dir[6][2] = {
 	0,1,
 	1,0,
 	1,1,
 	-1,0,
 	0,-1,
 	-1,-1
 };
 
 int fillcnt;
 
 
 void tryfillconnection(int x, int y, int cnum)
 {
 	cnum = (1<<cnum);
 	if(board[x][y] != 3) return;
 	if(connection[x][y] & cnum) return;
 	int h = 0, t = 0;
 	int checkCond = (connection[x][y] |= cnum);
 	if(bridgeCond[(checkCond >> 1) & 63]) isBridge = true;
 	if(forkCond[(checkCond >> 8) & 63]) isFork = true;
 	q[t++] = ((x<<13) | y);
 	for(;h<t;h++)
 	{
 		int qh = q[h];
 		int x = qh >> 13;
 		int y = qh & 8191;
 		for(int i = 0; i < 6; i ++)
 		{
 			int nx = x + dir[i][0];
 			int ny = y + dir[i][1];
 			if(!isInside(nx,ny)) continue;
 			if(board[nx][ny] != 3) continue;
 			if(connection[nx][ny] & cnum) continue;
 			int checkCond = (connection[nx][ny] |= cnum);
 			if(bridgeCond[(checkCond >> 1) & 63]) isBridge = true;
 			if(forkCond[(checkCond >> 8) & 63]) isFork = true;
 			q[t++] = ((nx<<13)|ny);
 		}
 	}
 }
 
 void tryfill(int x,int y)
 {
 	if(board[x][y]) return;
 	int h = 0, t = 0;
 	board[x][y] = 2;
 	fillcnt ++;
 	q[t++] = ((x<<13) | y);
 	for(;h<t;h++)
 	{
 		int qh = q[h];
 		int x = qh >> 13;
 		int y = qh & 8191;
 		for(int i = 0; i < 6; i ++)
 		{
 			int nx = x + dir[i][0];
 			int ny = y + dir[i][1];
 			if(!isInside(nx,ny)) continue;
 			if(board[nx][ny]) continue;
 			board[nx][ny] = 2;
 			fillcnt ++;
 			q[t++] = ((nx<<13)|ny);
 		}
 	}
 }
 
 int main()
 {
 	for(int i = 0;i < (1<<6); i++)
 	{
 		int cnt = 0;
 		for(int j = 0;j<6;j ++)
 		{
 			if(i & (1<<j))
 			{
 				cnt ++;
 			}
 		}
 		if(cnt >= 2) bridgeCond[i] = 1;
 		if(cnt >= 3) forkCond[i] = 1;
 	}
 
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase ++)
 	{
 		scanf("%d%d",&bsize,&m);
 		barea = 1 + 3 * bsize * (bsize-1);
 		maxCoord = bsize * 2 - 1;
 		fillcnt = 0;
 		memset(board, 0, sizeof(board));
 		memset(connection, 0, sizeof(connection));
 		memset(isRing, 0, sizeof(isRing));
 		isBridge = false;
 		isFork = false;
 		for(int i = 0;i < m; i ++)
 		{
 			scanf("%d%d",&moves[i][0],&moves[i][1]);
 			board[moves[i][0]][moves[i][1]] = 1;
 			fillcnt ++;
 		}
 
 		for(int i = 1; i <= bsize;i ++)
 		{
 			tryfill(1, i);
 			tryfill(i, 1);
 			tryfill(i, bsize+i-1);
 			tryfill(bsize+i-1, i);
 			tryfill(maxCoord,bsize*2-i);
 			tryfill(bsize*2-i,maxCoord);
 		}
 
 		for(int i = m-1;i >= 0; i--)
 		{
 			if(fillcnt != barea)
 			{
 				isRing[i] = 1;
 			}
 			else
 			{
 				isRing[i] = 0;
 			}
 
 			int x = moves[i][0], y = moves[i][1];
 			board[x][y] = 0;
 			fillcnt --;
 
 			if(isEdge(x,y) || isCorner(x,y))
 			{
 				tryfill(x,y);
 			}
 			else for(int j = 0;j < 6; j ++)
 			{
 				int nx = x + dir[j][0];
 				int ny = y + dir[j][1];
 				if(!isInside(nx,ny)) continue;
 				if(board[nx][ny] == 2)
 				{
 					tryfill(x, y);
 					break;
 				}
 			}
 
 		}
 
 		bool nonnone = false;
 		printf("Case #%d: ", testcase);
 		for(int i = 0;i < m; i++)
 		{
 			int x = moves[i][0], y = moves[i][1];
 			board[x][y] = 3;
 			int corner = isCorner(x,y);
 			int edge = isEdge(x,y);
 
 			if(corner)
 			{
 				tryfillconnection(x,y,corner);
 			}
 			if(edge)
 			{
 				tryfillconnection(x,y,edge);
 			}
 			for(int k = 1; k <= 13; k ++)
 			{
 				if(k == corner || k == edge) continue;
 				for(int j = 0;j < 6; j ++)
 				{
 					int nx = x + dir[j][0];
 					int ny = y + dir[j][1];
 					if(!isInside(nx,ny)) continue;
 					if(connection[nx][ny] & (1<<k))
 					{
 						tryfillconnection(x,y,k);
 						break;
 					}
 				}
 			}
 
 			if(isRing[i] || isBridge || isFork)
 			{
 				bool printed = false;
 				if(isBridge) printf(printed?"-":""),printf("bridge"), printed = true;
 				if(isFork) printf(printed?"-":""),printf("fork"), printed = true;
 				if(isRing[i]) printf(printed?"-":""),printf("ring"), printed = true;
 				printf(" in move %d\n", i + 1);
 				nonnone = true;
 				break;
 			}
 		}
 		if(!nonnone)
 		{
 			printf("none\n");
 		}
 	}
 	return 0;
 }