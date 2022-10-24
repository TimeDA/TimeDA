//program D
 
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
 
 int R,C,ans=0;
 int a[100][100];
 
 bool check(int x,int y)
 {
   int cnt=0;
   if(x&&a[x-1][y]==a[x][y])
     cnt++;
   if(a[x][(y+1)%C]==a[x][y])
     cnt++;
   if(a[x][(y+C-1)%C]==a[x][y])
     cnt++;
   if(x+1<R&&a[x+1][y]==a[x][y])
     cnt++;
   return cnt==a[x][y];
 }
 
 void dfs(int x,int y)
 {
   if(x==R)
     {
       bool ok=true;
       for(int i=0;ok&&i<C;i++)
 	ok=check(R-1,i);
       if(ok)
 	{
 	  string mins;
 	  for(int i=0;ok&&i<C;i++)
 	    {
 	      string s="";
 	      for(int j=0;j<R;j++)
 		for(int k=0;k<C;k++)
 		  s+=(a[j][(i+k)%C]+48);
 	      if(!i)
 		mins=s;
 	      else if(s<mins)
 		ok=false;
 	    }
 	  if(ok)
 	    ans++;
 	}
       return;
     }
   int x0=x,y0=y+1;
   if(y0==C)
     {
       x0++;
       y0=0;
     }
   for(int i=1;i<=3;i++)
     {
       a[x][y]=i;
       if(x&&!check(x-1,y))
 	continue;
       dfs(x0,y0);
     }
 }
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       R=get();C=get();
       ans=0;
       dfs(0,0);
       printf("Case #%d: %d\n",test,ans);
     }
   return 0;
 }
