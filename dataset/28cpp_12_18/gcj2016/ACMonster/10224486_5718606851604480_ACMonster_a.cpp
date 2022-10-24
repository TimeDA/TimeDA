//Problem A
 
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
 
 string solve(int n,int P,int R,int S,string p,string r,string s)
 {
   if(!n)
     {
       if(P)
         return p;
       return R?r:s;
     }
   int PR=(P+R-S)/2;
   int RS=(R+S-P)/2;
   int SP=(S+P-R)/2;
   if(PR+SP!=P||PR+RS!=R||RS+SP!=S||PR<0||RS<0||SP<0)
     return "IMPOSSIBLE";
   string pr=min(p+r,r+p);
   string rs=min(r+s,s+r);
   string sp=min(s+p,p+s);
   return solve(n-1,PR,RS,SP,pr,rs,sp);
 }
 
 int main()
 {
   int totaltest=get();
   for(int test=1;test<=totaltest;test++)
     {
       int n,R,P,S;
       cin>>n>>R>>P>>S;
       string ans=solve(n,P,R,S,"P","R","S");
       printf("Case #%d: ",test);
       cout<<ans<<endl;
     }
   return 0;
 }
