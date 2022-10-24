//Problem D
 
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
 
 int n;
 int cnt[65536];
 int a[25][25],b[25][25];
 bool fx[25],fy[25];
 
 bool dfs(int depth)
 {
   if(depth==n)
     return true;
   for(int i=0;i<n;i++)
     if(!fx[i])
       {
         bool flag=false;
         for(int j=0;j<n;j++)
           if(!fy[j]&&b[i][j])
             {
               flag=true;
               fx[i]=fy[j]=true;
               if(!dfs(depth+1))
                 return false;
               fx[i]=fy[j]=false;
             }
         if(!flag)
           return false;
       }
   return true;
 }
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       n=get();
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
           {
             char c;
             while(c=getchar(),c!='0'&&c!='1');
             a[i][j]=(c=='1');
           }
       int ans=n*n;
       for(int mask=0;mask<(1<<(n*n));mask++)
         {
           cnt[mask]=mask?(cnt[mask^(mask&-mask)]+1):0;
           if(cnt[mask]>=ans)
             continue;
           for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
               b[i][j]=a[i][j]|((mask>>(i*n+j))&1);
           memset(fx,0,sizeof(fx));
           memset(fy,0,sizeof(fy));
           if(dfs(0))
             ans=cnt[mask];
         }
       printf("Case #%d: %d\n",test,ans);
     }
   return 0;
 }
