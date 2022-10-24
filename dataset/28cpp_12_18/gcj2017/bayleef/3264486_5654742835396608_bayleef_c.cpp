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
 	freopen("c.in","r",stdin);
 	freopen("c.out","w",stdout);
 	long long n,k;
 	int T,ts;
 	map<long long,long long>m;
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)	
 	{
 		m.clear();
 		scanf("%lld%lld",&n,&k);
 		--k;
 		m[n]=1;
 		while(1)
 		{
 			auto it=m.end();
 			--it;
 			if(k<it->second)
 			{
 				printf("Case #%d: %lld %lld\n",ts,it->first/2,(it->first-1)/2);
 				break;
 			}
 			k-=it->second;
 			m[it->first/2]+=it->second;
 			m[(it->first-1)/2]+=it->second;
 			m.erase(it);
 		}
 	}
 	return 0;
 }