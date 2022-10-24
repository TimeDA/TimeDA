#include <stdio.h>
 #include <map>
 #include <algorithm>
 
 using namespace std ;
 
 int my, mx ;
 char arr[110][110] ;
 
 bool inline IsInside(int x, int y)
 {
 	return (x>=0 && y>=0 && x<mx && y<my) ;
 }
 
 map<char, pair<int,int> > dir ;
 
 bool IsSafe(int y, int x, pair<int,int> d)
 {
 	for(;;)
 	{
 		x += d.first ;
 		y += d.second ;
 		if(!IsInside(x,y)) return false ;
 		if(arr[y][x]!='.') return true ;	
 	}
 }
 
 int main(void)
 {
 	int tc ;
 	scanf("%d", &tc) ;
 	
 	dir['^'] = {0,-1} ;
 	dir['>'] = {1,0} ;
 	dir['v'] = {0,1} ;
 	dir['<'] = {-1,0} ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		scanf("%d%d", &my, &mx) ;
 		for(int y=0;y<my;y++) scanf("%s", arr[y]) ;
 		int ans = 0 ;
 		bool isAns = true ;
 		for(int y=0;y<my && isAns;y++)
 			for(int x=0;x<mx && isAns;x++)
 				if(arr[y][x]!='.')
 				{
 					pair<int, int> d = dir[arr[y][x]] ;
 					bool isSafe = IsSafe(y,x,d) ;
 					if(!isSafe)
 					{
 						bool isOK = false ;
 						ans++ ;
 						for(auto rd: dir)
 						{
 							if(rd.second==d) continue ;
 							if(IsSafe(y,x,rd.second))
 							{
 								isOK = true ;
 								break ;
 							}
 						}
 						if(!isOK) isAns = false ;
 					}
 				}
 		printf("Case #%d: ", c) ;
 		if(isAns) printf("%d\n", ans) ;
 		else puts("IMPOSSIBLE") ;
 	}
 	
 	return 0 ;
 }
 
