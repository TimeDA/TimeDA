//Problem B
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 #include<ctime>
 #include<vector>
 #include<set>
 #include<queue>
 #include<bitset>
 #include<map>
 
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
 
 double p[200],q[200];
 int cnt[65536];
 double dp[100][100];
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get(),k=get();
       for(int i=0;i<n;i++)
         scanf("%lf",&p[i]);
       double ans=0;
       for(int mask=0;mask<(1<<n);mask++)
         {
           cnt[mask]=mask?(cnt[mask^(mask&-mask)]+1):0;
           if(cnt[mask]!=k)
             continue;
           int m=0;
           for(int i=0;i<n;i++)
             if(mask&(1<<i))
               q[m++]=p[i];
           memset(dp,0,sizeof(dp));
           dp[0][0]=1;
           for(int i=1;i<=k;i++)
             for(int j=0;j<=i;j++)
               {
                 dp[i][j]=(1-q[i-1])*dp[i-1][j];
                 if(j)
                   dp[i][j]+=q[i-1]*dp[i-1][j-1];
               }
           ans=max(ans,dp[k][k/2]);
         }
       printf("Case #%d: %0.10lf\n",test,ans);
     }
   return 0;
 }
