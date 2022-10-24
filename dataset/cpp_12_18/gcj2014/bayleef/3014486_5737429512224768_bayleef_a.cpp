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
 
 using namespace std;
 
 int u[20000],n,x,i,j,ans,a[20000],T,ts;
 multiset<int>s;
 multiset<int>::iterator it,jt;
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		scanf("%d%d",&n,&x);
 		s.clear();
 		while(n--)
 		{
 			scanf("%d",&i);
 			s.insert(i);
 		}
 		ans=0;
 		while(!s.empty())
 		{
 			it=s.end();
 			--it;
 			i=*it;
 			s.erase(it);
 			jt=s.upper_bound(x-i);
 			if(jt!=s.begin())
 			{
 				--jt;
 				s.erase(jt);
 			}
 			ans++;
 		}
 		printf("Case #%d: %d\n",++ts,ans);
 	}
 	return 0;
 }