//program A
 
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
 
 char a[100][100];
 set<char> forbid[100][100];
 
 bool check(char c)
 {
   return c=='v'||c=='^'||c=='<'||c=='>'||c=='.';
 }
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get(),m=get();
       for(int i=0;i<n;i++)
 	for(int j=0;j<m;j++)
 	  {
 	    while(a[i][j]=getchar(),!check(a[i][j]));
 	    forbid[i][j].clear();
 	  }
       for(int i=0;i<m;i++)
 	{
 	  int p=0;
 	  while(p<n&&a[p][i]=='.')
 	    p++;
 	  if(p<n)
 	    forbid[p][i].insert('^');
 	  p=n-1;
 	  while(p>=0&&a[p][i]=='.')
 	    p--;
 	  if(p>=0)
 	    forbid[p][i].insert('v');
 	}
       for(int i=0;i<n;i++)
 	{
 	  int p=0;
 	  while(p<m&&a[i][p]=='.')
 	    p++;
 	  if(p<m)
 	    forbid[i][p].insert('<');
 	  p=m-1;
 	  while(p>=0&&a[i][p]=='.')
 	    p--;
 	  if(p>=0)
 	    forbid[i][p].insert('>');
 	}
       bool bad=false;
       int ans=0;
       for(int i=0;i<n;i++)
 	for(int j=0;j<m;j++)
 	  if(forbid[i][j].size()==4)
 	    bad=true;
 	  else if(forbid[i][j].count(a[i][j]))
 	    ans++;
       printf("Case #%d: ",test);
       if(bad)
 	printf("IMPOSSIBLE\n");
       else
 	output(ans);
     }
   return 0;
 }
