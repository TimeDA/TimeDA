//program C
 
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
 
 string data[10000];
 vector<string> sen[100];
 vector<int> g[100];
 bool color[10000],f0[10000],f1[10000];
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get(),total=0;
       for(int i=0;i<n;i++)
 	{
 	  char c;
 	  while(c=getchar(),c<'a'||c>'z');
 	  sen[i].clear();
 	  while(true)
 	    {
 	      string s="";
 	      while(c>='a'&&c<='z')
 		{
 		  s+=c;
 		  c=getchar();
 		}
 	      sen[i].push_back(s);
 	      data[total++]=s;
 	      if(c=='\n')
 		break;
 	      while((c<'a'||c>'z')&&c!=-1)
 		c=getchar();
 	    }
 	}
       sort(data,data+total);
       total=unique(data,data+total)-data;
       for(int i=0;i<n;i++)
 	{
 	  g[i].clear();
 	  for(int j=0;j<sen[i].size();j++)
 	    g[i].push_back(lower_bound(data,data+total,sen[i][j])-data);
 	}
       int ans=total;
       for(int mask=1;mask<(1<<n);mask+=4)
 	{
 	  for(int i=0;i<n;i++)
 	    color[i]=(mask>>i)&1;
 	  for(int i=0;i<total;i++)
 	    f0[i]=f1[i]=false;
 	  for(int i=0;i<n;i++)
 	    for(int j=0;j<g[i].size();j++)
 	      if(color[i])
 		f0[g[i][j]]=true;
 	      else
 		f1[g[i][j]]=true;
 	  int sum=0;
 	  for(int i=0;i<total;i++)
 	    sum+=f0[i]&&f1[i];
 	  ans=min(ans,sum);
 	}
       printf("Case #%d: %d\n",test,ans);
     }
   return 0;
 }
