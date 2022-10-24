//program C
 
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
 
 struct Event
 {
   int time,l,r,delta;
 };
 
 bool operator <(Event a,Event b)
 {
   return a.time<b.time;
 }
 
 struct Edge
 {
   int data,weight,next;
 };
 
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
 
 const int maxn=4002002;
 const int maxe=20014000;
 
 int g[maxn];
 Edge e[maxe];
 
 void add(int num,int x,int y)
 {
   e[num*2]=(Edge){y,1,g[x]};
   g[x]=num*2;
   e[num*2+1]=(Edge){x,0,g[y]};
   g[y]=num*2+1;
 }
 
 int SAP(int s,int t,int n)
 {
   static int start[maxn],dist[maxn],cnt[maxn+1],pre[maxn];
   memset(dist,0,sizeof(dist));
   memset(cnt,0,sizeof(cnt));
   cnt[0]=n;
   for(int i=0;i<n;i++)
     start[i]=g[i];
   int v=s,ans=0;
   while(dist[s]<n)
     {
       int p=start[v];
       while(p!=-1)
         {
           if(e[p].weight&&dist[v]==dist[e[p].data]+1)
             break;
           p=e[p].next;
         }
       if(p!=-1)
         {
           start[v]=p;
           v=e[p].data;
           pre[v]=p;
           if(v==t)
             {
               ans++;
               while(v!=s)
                 {
                   e[pre[v]].weight--;
                   e[pre[v]^1].weight++;
                   v=e[pre[v]^1].data;
                 }
             }
         }
       else
         {
           int mind=n,p=g[v];
           while(p!=-1)
             {
               if(e[p].weight&&dist[e[p].data]+1<mind)
                 {
                   mind=dist[e[p].data]+1;
                   start[v]=p;
                 }
               p=e[p].next;
             }
           if(!--cnt[dist[v]])
             break;
           cnt[dist[v]=mind]++;
           if(v!=s)
             v=e[pre[v]^1].data;
         }
     }
   return ans;
 }
 
 int main()
 {
   freopen("C.in","r",stdin);
   //freopen("C.out","w",stdout);
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n=get(),h=get(),m=get();
       static bool a[2002][1000];
       memset(a,0,sizeof(a));
       while(m--)
         {
           int x0=get(),y0=get(),x1=get(),y1=get();
           for(int i=y0;i<=y1;i++)
             for(int j=x0;j<=x1;j++)
               a[i][j]=true;
         }
       m=h;
       int s=m*n*2,t=m*n*2+1,counter=0;
       memset(g,-1,sizeof(g));
       for(int i=0;i<n;i++)
         {
           if(!a[0][i])
             add(counter++,s,i*2);
           if(!a[m-1][i])
             add(counter++,((m-1)*n+i)*2+1,t);
         }
       for(int i=0;i<m*n;i++)
         add(counter++,i*2,i*2+1);
       for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
           {
             if(a[i][j])
               continue;
             if(i+1<m&&!a[i+1][j])
               {
                 add(counter++,(i*n+j)*2+1,((i+1)*n+j)*2);
                 add(counter++,((i+1)*n+j)*2+1,(i*n+j)*2);
               }
             if(j+1<n&&!a[i][j+1])
               {
                 add(counter++,(i*n+j)*2+1,(i*n+(j+1))*2);
                 add(counter++,(i*n+(j+1))*2+1,(i*n+j)*2);
               }
           }
       printf("Case #%d: %d\n",test,SAP(s,t,m*n*2+2));
     }
   return 0;
 }
