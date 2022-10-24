//program B
 
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
 
 int main()
 {
   freopen("B.in","r",stdin);
   //freopen("B.out","w",stdout);
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get();
       static int x[1000];
       for(int i=0;i<n;i++)
         x[i]=get();
       int ans=0;
       for(int i=n;i>=1;i--)
         {
           int p=0;
           for(int j=1;j<i;j++)
             if(x[j]<x[p])
               p=j;
           ans+=min(p,i-1-p);
           while(p+1<i)
             {
               swap(x[p],x[p+1]);
               p++;
             }
         }
       printf("Case #%d: %d\n",test,ans);
     }
   return 0;
 }
