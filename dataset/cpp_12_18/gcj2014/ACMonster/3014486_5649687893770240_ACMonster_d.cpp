//program D
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 #include<vector>
 #include<cmath>
 #include<set>
 #include<queue>
 #include<bitset>
 
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
 
 int n,m,best,ways;
 string s[1000],t[1000];
 int a[1000];
 int cnt[100];
 
 void dfs(int depth)
 {
   if(depth==n)
     {
       for(int i=0;i<m;i++)
         if(!cnt[i])
           return;
       int ans=0;
       for(int i=0;i<m;i++)
         {
           int tot=0;
           for(int j=0;j<n;j++)
             if(a[j]==i)
               t[tot++]=s[j];
           sort(t,t+tot);
           ans+=t[0].size()+1;
           for(int j=1;j<tot;j++)
             {
               int p=0;
               while(p<t[j-1].size()&&p<t[j].size()&&t[j-1][p]==t[j][p])
                 p++;
               ans+=t[j].size()-p;
             }
         }
       if(ans>best)
         {
           best=ans;
           ways=0;
         }
       if(ans==best)
         ways++;
       return;
     }
   for(int i=0;i<m;i++)
     {
       cnt[i]++;
       a[depth]=i;
       dfs(depth+1);
       cnt[i]--;
     }
 }
 
 int main()
 {
   freopen("D.in","r",stdin);
   //freopen("D.out","w",stdout);
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       n=get();
       m=get();
       for(int i=0;i<n;i++)
         cin>>s[i];
       memset(cnt,0,sizeof(cnt));
       best=-1;
       dfs(0);
       printf("Case #%d: %d %d\n",test,best,ways);
     }
   return 0;
 }
