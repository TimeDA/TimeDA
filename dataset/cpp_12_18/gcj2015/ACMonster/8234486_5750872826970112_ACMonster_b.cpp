//program B
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 #include<vector>
 #include<set>
 #include<queue>
 #include<bitset>
 #include<ctime>
 
 using namespace std;
 
 int get()
 {
   char c;
   while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
   bool flag=(c=='-');
   if(flag)
     c=getchar();
   int x=0;
   while(c>='0'&&c<='9')
     {
       x=x*10+c-48;
       c=getchar();
     }
   return flag?-x:x;
 }
 
 void output(int x)
 {
   if(x<0)
     {
       putchar('-');
       x=-x;
     }
   int len=0,data[10];
   while(x)
     {
       data[len++]=x%10;
       x/=10;
     }
   if(!len)
     data[len++]=0;
   while(len--)
     putchar(data[len]+48);
   putchar('\n');
 }
 
 const double eps=1e-8;
 
 double R[100],C[100];
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get();
       double V,X;
       cin>>V>>X;
       for(int i=0;i<n;i++)
         cin>>R[i]>>C[i];
       double minC=C[0],maxC=C[0];
       for(int i=1;i<n;i++)
         {
 	  minC=min(minC,C[i]);
 	  maxC=max(maxC,C[i]);
         }
       printf("Case #%d: ",test);
       if(X<minC-eps||X>maxC+eps)
 	{
 	  printf("IMPOSSIBLE\n");
 	  continue;
 	}
       if(n==1)
 	printf("%0.10lf\n",V/R[0]);
       else if(fabs(C[0]-C[1])<eps)
 	printf("%0.10lf\n",V/(R[0]+R[1]));
       else
 	{
 	  double x=(V*R[1]*C[1]-V*X*R[1])/(R[0]*R[1]*(C[1]-C[0]));
 	  double y=(V*X*R[0]-V*R[0]*C[0])/(R[0]*R[1]*(C[1]-C[0]));
 	  printf("%0.10lf\n",max(x,y));
 	}
     }
   return 0;
 }
