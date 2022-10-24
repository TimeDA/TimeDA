#define _USE_MATH_DEFINES
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <queue>
 #include <map>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	int T,ts,k,s,d,n;
 	double ans=1E18;
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		ans=1E18;
 		scanf("%d%d",&d,&n);
 		while(n--)
 		{
 			scanf("%d%d",&k,&s);
 			ans=min(ans,1.0*d*s/(d-k));
 		}
 		printf("Case #%d: %.12lf\n",ts,ans);
 	}
 	return 0;
 }