#include<cstdio>
 #include<cstring>
 #include<bitset>
 #include<algorithm>
 using namespace std;
 #define N 2010
 int n,A[N],B[N],X[N],q[N],d[N];bitset<2000> C[N];
 void chk()
 {
 	for(int i=0;i<n;i++)
 	{
 		int S=1;
 		for(int j=0;j<i;j++)if(X[j]<X[i])S=max(S,A[j]+1);
 		if(S!=A[i])puts("OHNO2");
 	}
 	for(int i=n-1;i>=0;i--)
 	{
 		int S=1;
 		for(int j=n-1;j>i;j--)if(X[j]<X[i])S=max(S,B[j]+1);
 		if(S!=B[i])puts("OHNO3");
 	}
 }
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		scanf("%d",&n);
 		for(int i=0;i<n;i++)scanf("%d",A+i);
 		for(int i=0;i<n;i++)scanf("%d",B+i);
 		for(int i=0;i<n;i++)C[i].reset();
 		for(int i=0;i<n;i++)
 			for(int j=i+1;j<n;j++)
 			{
 				if(A[i]>=A[j])C[i][j]=1;
 				if(B[i]<=B[j])C[j][i]=1;
 			}
 		for(int k=0;k<n;k++)
 			for(int i=0;i<n;i++)if(C[i][k])
 				for(int j=0;j<n;j++)if(C[k][j])C[i][j]=1;
 		X[n-1]=0;
 		for(int i=n-2;i>=0;i--)
 		{
 			int le=0,ri=n-i-1,le2=n-i-1;
 			if(B[i]==1)le2=0;
 			for(int j=i+1;j<n;j++)
 			{
 				if(C[i][j])le=max(le,X[j]+1);
 				if(C[j][i])ri=min(ri,X[j]);
 				if(B[j]==B[i]-1)le2=min(le2,X[j]+1);
 			}
 			le=max(le,le2);
 			if(le>ri)puts("OHNO");
 			X[i]=le;
 			for(int j=i+1;j<n;j++)
 			{
 				if(X[j]>=X[i])X[j]++;
 				if(X[i]>X[j])C[i][j]=1;else C[j][i]=1;
 			}
 		}
 		chk();
 		printf("Case #%d: ",__);
 		for(int i=0;i<n;i++)printf("%d%c",X[i]+1,i==n-1?'\n':' ');
 		/*
 		for(int i=0;i<n;i++)
 			for(int j=0;j<i;j++)
 				if(A[j]==A[i]-1){C[i][j]=1;break;}
 		for(int i=0;i<n;i++)
 			for(int j=n-1;j>i;j--)
 				if(B[j]==B[i]-1){C[i][j]=1;break;}
 		*/
 		/*
 		int l=0,r=0;
 		memset(d,0,sizeof d);
 		for(int i=0;i<n;i++)
 			for(int j=0;j<n;j++)
 				if(C[i][j])d[j]++;
 		for(int i=0;i<n;i++)
 			if(d[i]==0)q[r++]=i;
 		while(l<r)
 		{
 			int x=q[l++];
 			for(int i=0;i<n;i++)
 				if(C[x][i]){d[i]--;if(d[i]==0)q[r++]=i;}
 		}
 		for(int i=0;i<n;i++)X[q[i]]=n-i;
 		printf("Case #%d: ",__);
 		for(int i=0;i<n;i++)printf("%d%c",X[i],i==n-1?'\n':' ');
 		*/
 	}
 	return 0;
 }
