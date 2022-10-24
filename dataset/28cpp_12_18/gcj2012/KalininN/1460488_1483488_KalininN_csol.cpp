#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 	#define LLD "%I64d"
 #else
 	#define LLD "%lld"
 #endif
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		cerr << T << endl;
 		int a,b;
 		scanf("%d%d",&a,&b);
 		int ans=0;
 		for (int i=a;i<=b;i++)
 		{
 			int k=0;
 			int st=1;
 			int t=i;
 			while (t>0)
 			{
 				t/=10;
 				st*=10;
 				k++;
 			}
 			st/=10;
 			t=i;
 			for (int j=1;j<k;j++)
 			{
 				int last=t%10;
 				t=t/10+last*st;
 				if (last!=0 && t<i && t>=a)
 				{
 // 					cout << i << ' ' << t << endl;
 					ans++;
 				}
 			}
 		}
 		printf("Case #%d: %d\n",T,ans);
 	}
 	return 0;
 }
