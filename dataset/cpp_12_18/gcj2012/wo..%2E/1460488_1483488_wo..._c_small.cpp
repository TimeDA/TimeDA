#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 inline int exp10(int n)
 {
 	int res=1;
 	for(int i=0;i<n;i++) res*=10;
 	return res;
 }
 
 bool check(int n,int m)
 {
 	int dig=1,ex=1;
 	for(;;)
 	{
 		ex*=10;
 		if(m<ex) break;
 		dig++;
 	}
 	for(int i=1;i<dig;i++)
 	{
 		int front=n/(exp10(i));
 		int back=n%(exp10(i));
 		int nn=front+back*(exp10(dig-i));
 		if(nn==m) return true;
 	}
 	return false;
 }
 
 int main()
 {
 	int T;
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("c_sm_out.txt","w",stdout);
 	scanf("%d",&T);
 	for(int data=1;data<=T;data++)
 	{
 		int A,B;
 		int ans=0;
 		scanf("%d%d",&A,&B);
 		for(int i=A;i<B;i++)
 		{
 			for(int j=i+1;j<=B;j++)
 			{
 				if(check(i,j)) ans++;
 			}
 		}
 		printf("Case #%d: %d\n",data,ans);
 	}
 	return 0;
 }
