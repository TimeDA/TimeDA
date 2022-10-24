#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <cstring>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <map>
 
 using namespace std;
 
 
 int main(void)
 {
 	int t, T ;
 	int d[1100][2] ;
 	int n ;
 	int r[1100], i, j ;
 	int valid[1100] ;
 	int cnt ;
 	
 	srand(time(0)) ;
 	
 	scanf("%d",&T) ;
 	for(t=1;t<=T;t++)
 	{
 		int mx, my ;
 		scanf("%d%d%d",&n,&mx,&my) ;
 		for(i=0;i<n;i++)
 		{
 			scanf("%d",&r[i]) ;
 		}
 		
 		cnt = 0 ;
 		memset(valid,0,sizeof(valid)) ;
 		int reset = 0 ;
 		while(cnt<n)
 		{
 			for(i=0;i<n;i++)
 			{
 				if(valid[i]==0)
 				{
 					d[i][0] = (((long long)rand())*32768+rand())%(mx+1) ;
 					d[i][1] = (((long long)rand())*32768+rand())%(my+1) ;
 				}
 			}
 			
 			for(i=0;i<n;i++)
 			{
 				if(valid[i]==1) continue ;
 				for(j=0;j<n;j++)
 				{
 					if(valid[j]==0) continue ;
 					long long dx = d[i][0]-d[j][0] ;
 					long long dy = d[i][1]-d[j][1] ;
 					long long dr = r[i]+r[j] ;
 					if(dx*dx+dy*dy<dr*dr)
 					{
 						j = -1 ;
 						break ;
 					}
 				}
 				if(j!=-1)
 				{
 					cnt++ ;
 					valid[i] = 1 ;
 				}
 			}
 			
 			reset++ ;
 
 			if(reset>n/3&&reset>30)
 			{
 				reset = 0 ;
 				cnt = 0 ;
 				memset(valid,0,sizeof(valid)) ;
 			}
 
 		}
 
 		printf("Case #%d:",t) ;
 		for(i=0;i<n;i++)
 		{
 			printf(" %d %d",d[i][0],d[i][1]) ;
 		}
 		printf("\n") ;
 	}
 
    return 0;
 }
