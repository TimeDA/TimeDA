#include <stdio.h>
 #include <set>
 
 std::set<int>s;
 int T,i,j,n,x,ts;
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	while(T--)
 	{
 		s.clear();
 		for(i=1;i<=16;i++)
 			s.insert(i);
 		scanf("%d",&n);
 		for(i=1;i<=4;i++)
 			for(j=1;j<=4;j++)
 			{
 				scanf("%d",&x);
 				if(i!=n) s.erase(x);
 			}
 		scanf("%d",&n);
 		for(i=1;i<=4;i++)
 			for(j=1;j<=4;j++)
 			{
 				scanf("%d",&x);
 				if(i!=n) s.erase(x);
 			}
 		printf("Case #%d: ",++ts);
 		if(s.size()==1)
 			printf("%d\n",*s.begin());
 		else if(s.size())
 			puts("Bad magician!");
 		else puts("Volunteer cheated!");
 	}
 	return 0;
 }
