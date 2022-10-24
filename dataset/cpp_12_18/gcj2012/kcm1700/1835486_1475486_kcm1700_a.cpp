#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 struct triplet {
 	int first, second, third;
 } dat[10000];
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase ++)
 	{
 		int n;
 		scanf("%d",&n);
 		for(int i = 0;i < n;i ++)
 		{
 			scanf("%d",&dat[i].first);
 		}
 		for(int i = 0;i < n; i++)
 		{
 			scanf("%d",&dat[i].second);
 			dat[i].third = i;
 		}
 		sort(dat,dat+n,[](const triplet &a, const triplet &b) -> bool{
 			bool ret = a.first * b.second < a.second * b.first;
 			if(a.first * b.second == a.second * b.first)
 			{
 				return a.third < b.third;
 			}
 			return ret;
 		});
 
 		printf("Case #%d:", testcase);
 		for(int i = 0;i < n;i ++)
 		{
 			printf(" %d", dat[i].third);
 		}
 		printf("\n");
 	}
 	return 0;
 }