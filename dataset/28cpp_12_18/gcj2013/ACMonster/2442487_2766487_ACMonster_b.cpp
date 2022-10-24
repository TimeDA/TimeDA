//program B
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 int Get()
 {
   char c;
   while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
   bool Flag=(c=='-');
   if(Flag)
     c=getchar();
   int X=0;
   while(c>='0'&&c<='9')
     {
       X=X*10+c-48;
       c=getchar();
     }
   return Flag?-X:X;
 }
 
 void Output(int X)
 {
   if(X<0)
     {
       putchar('-');
       X=-X;
     }
   int Len=0,Data[10];
   while(X)
     {
       Data[Len++]=X%10;
       X/=10;
     }
   if(!Len)
     Data[Len++]=0;
   while(Len--)
     putchar(Data[Len]+48);
   putchar('\n');
 }
 
 long long Worst(long long X,int N)
 {
   long long Ans=0,Step=1LL<<(N-1),Count=X;
   while(Count)
     {
       Ans+=Step;
       Count=(Count-1)/2;
       Step/=2;
     }
   return Ans;
 }
 
 long long Best(long long X,int N)
 {
   long long Ans=0,Step=1LL<<(N-1),Count=(1LL<<N)-1-X;
   while(Step>0)
     {
       if(Count)
         Count=(Count-1)/2;
       else
         Ans+=Step;
       Step/=2;
     }
   return Ans;
 }
 
 int main()
 {
   int TotalTest=Get();
   for(int Test=1;Test<=TotalTest;Test++)
     {
       printf("Case #%d: ",Test);
       int N=Get();
       long long Rank=Get();
       long long Left=0,Right=(1LL<<N)-1;
       while(Left<Right)
         {
           long long Mid=(Left+Right+1)/2;
           if(Worst(Mid,N)<Rank)
             Left=Mid;
           else
             Right=Mid-1;
         }
       cout<<Left<<' ';
       Left=0;
       Right=(1LL<<N)-1;
       while(Left<Right)
         {
           long long Mid=(Left+Right+1)/2;
           if(Best(Mid,N)<Rank)
             Left=Mid;
           else
             Right=Mid-1;
         }
       cout<<Left<<endl;
     }
   return 0;
 }
