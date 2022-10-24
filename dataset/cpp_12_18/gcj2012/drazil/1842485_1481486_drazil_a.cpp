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
 
 int v[11000] ;
 int d[11000] ;
 int dpt[11000] ;
 
 int main(void)
 {
 	int t, T ;
 	int i, n, L, j ;
 	
 	scanf("%d",&T) ;
 	
 	for(t=1;t<=T;t++)
 	{
 		memset(dpt,0,sizeof(dpt)) ;
 		scanf("%d",&n) ;
 		
 		for(i=0;i<n;i++)
 		{
 			scanf("%d%d",&d[i],&v[i]) ;
 		}
 		scanf("%d",&L) ;
 		d[n] = L ;
 		v[n] = 0 ;
 		dpt[n] = -1 ;
 		
 		dpt[0] = d[0] ;
 		for(i=0;i<n;i++)
 		{
 			for(j=1;i+j<=n&&d[i+j]-d[i]<=dpt[i];j++)
 			{
 				int ld = d[i+j]-d[i] ;
 				if(v[i+j]<ld) ld = v[i+j] ;
 				if(ld>dpt[i+j])
 				{
 					dpt[i+j] = ld ;
 				}
 			}
 		}
 
 		if(dpt[n]==0)
 		{
 			printf("Case #%d: YES\n",t) ;
 		}
 		else
 		{
 			printf("Case #%d: NO\n",t) ;
 		}
 	}
 
 	return 0 ;
 }
