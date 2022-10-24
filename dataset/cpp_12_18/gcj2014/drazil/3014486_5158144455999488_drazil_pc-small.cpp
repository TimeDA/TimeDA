#include <iostream>
 #include <string>
 #include <cstdio>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cstring>
 #include <stack>
 #include <queue>
 
 using namespace std ;
 
 int fmap[510][110] ;
 int used[510][110] ;
 
 int mx, my ;
 
 int dfs(int y, int x)
 {
 	used[y][x] = 1 ;
 	if(y==my-1)
 	{
 		fmap[y][x] = 1 ;
 		return 1 ;
 	}
 	if(x>0&&fmap[y][x-1]==0&&used[y][x-1]==0)
 		if(dfs(y,x-1)==1)
 		{
 			fmap[y][x] = 1 ;
 			return 1 ;
 		}
 	if(fmap[y+1][x]==0&&used[y+1][x]==0)
 		if(dfs(y+1,x)==1)
 		{
 			fmap[y][x] = 1 ;
 			return 1 ;
 		}
 	if(x+1<mx&&fmap[y][x+1]==0&&used[y][x+1]==0)
 		if(dfs(y,x+1)==1)
 		{
 			fmap[y][x] = 1 ;
 			return 1 ;
 		}
 	if(y-1>=0&&fmap[y-1][x]==0&&used[y-1][x]==0)
 		if(dfs(y-1,x)==1)
 		{
 			fmap[y][x] = 1 ;
 			return 1 ;
 		}
 	return 0 ;
 }
 
 int main(void)
 {
 	int tc ;
 	cin >> tc ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		int bn ;
 		cin >> mx >> my >> bn ;
 		memset(fmap,0,sizeof(fmap)) ;
 		for(int i=0;i<bn;i++)
 		{
 			int x0, y0, x1, y1 ;
 			cin >> x0 >> y0 >> x1 >> y1 ;
 			for(int y=y0;y<=y1;y++)
 				for(int x=x0;x<=x1;x++)
 					fmap[y][x] = 1 ;
 		}
 		
 		int ans = 0 ;
 		
 		for(;;)
 		{
 			int cx = -1 ;
 			for(int x=0;x<mx;x++)
 				if(fmap[0][x]==0)
 				{
 					cx = x ;
 					break ;
 				}
 			memset(used,0,sizeof(used)) ;
 			if(cx==-1 || dfs(0,cx)==0)
 				break ;
 			ans++ ;
 		}
 		
 		printf("Case #%d: %d\n",c,ans) ;
 	}
 	
 	return 0 ;
 }
