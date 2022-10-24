#include<cstdio>
 #include<algorithm>
 using namespace std;
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		int L,R;
 		scanf("%d%d",&L,&R);
 		int S=0;
 		for(int i=L;i<=R;i++)
 		{
 			int c=0,p=i,z=1;
 			while(p)p/=10,c++,z*=10;p=i;
 			for(int k=0;k<c;k++)
 			{
 				int q=p/10+p%10*z/10;
 				if(p%10!=0&&L<=q&&q<=R&&q!=i)S++;
 				if(q==i)break;
 				p=q;
 			}
 		}
 		printf("Case #%d: %d\n",__,S/2);
 	}
 	return 0;
 }
