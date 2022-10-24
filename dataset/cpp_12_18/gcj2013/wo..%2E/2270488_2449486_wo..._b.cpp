#include<cstdio>
 #include<cstring>
 
 using namespace std;
 
 int N,M;
 int a[110][110];
 
 int rows[110],cols[110];
 
 bool check(int h)
 {
 	memset(rows,0,sizeof(rows));
 	memset(cols,0,sizeof(cols));
 	for(int i=0;i<N;i++) for(int j=0;j<M;j++)
 	{
 		if(a[i][j]<=h)
 		{
 			rows[i]++;
 			cols[j]++;
 		}
 	}
 	for(int i=0;i<N;i++) for(int j=0;j<M;j++)
 	{
 		if(a[i][j]<=h)
 		{
 			if(rows[i]!=M&&cols[j]!=N) return false;
 		}
 	}
 	return true;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		scanf("%d%d",&N,&M);
 		for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&a[i][j]);
 		bool ok=true;
 		for(int i=1;i<=100;i++) if(check(i)==false) ok=false;
 		if(ok==true)
 		{
 			printf("Case #%d: YES\n",datano+1);
 		}
 		else
 		{
 			printf("Case #%d: NO\n",datano+1);
 		}
 	}
 	return 0;
 }
