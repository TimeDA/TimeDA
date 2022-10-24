//Problem C
 
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
 
 int a[400],p[20200];
 
 int root(int x)
 {
   return (p[x]==x)?x:(p[x]=root(p[x]));
 }
 
 int getnum(int x,int n,int m)
 {
   if(x<m)
     return x; 
   if(x>=m&&x<n+m)
     {
       x-=m;
       return (n+1)*m+x*(m+1)+m;
     }
   if(x>=n+m&&x<n+m*2)
     {
       x-=n+m;
       x=m-1-x;
       return n*m+x;
     }
   x-=n+m*2;
   x=n-1-x;
   return (n+1)*m+x*(m+1);
 }
 
 void connect(int x,int y)
 {
   p[root(x)]=root(y);
 }
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get(),m=get();
       for(int i=0;i<(n+m)*2;i++)
         a[i]=get()-1;
       printf("Case #%d:\n",test);
       bool sol=false;
       for(int mask=0;!sol&&mask<(1<<(n*m));mask++)
         {
           int total=n*m*2+n+m;
           for(int i=0;i<total;i++)
             p[i]=i;
           for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
               {
                 int A=i*m+j;
                 int B=(i+1)*m+j;
                 int C=(n+1)*m+i*(m+1)+j;
                 int D=(n+1)*m+i*(m+1)+j+1;
                 if(mask&(1<<(i*m+j)))
                   {
                     connect(A,C);
                     connect(B,D);
                   }
                 else
                   {
                     connect(A,D);
                     connect(B,C);
                   }
               }
           sol=true;
           for(int i=0;sol&&i<n+m;i++)
             {
               int x=getnum(a[i*2],n,m),y=getnum(a[i*2+1],n,m);
               if(root(x)!=root(y))
                 sol=false;
             }
           if(!sol)
             continue;
           for(int i=0;i<n;i++)
             {
               for(int j=0;j<m;j++)
                 if(mask&(1<<(i*m+j)))
                   putchar('/');
                 else
                   putchar('\\');
               putchar('\n');
             }
         }
       if(!sol)
         printf("IMPOSSIBLE\n");
     }
   return 0;
 }
