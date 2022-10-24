//program C
 
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
 
 int N;
 int A[2000],B[2000],Ans[2000];
 bool Flag[2000];
 
 bool Check(int Depth)
 {
   if(Depth<0)
     return true;
   int Max=1;
   for(int i=0;i<Depth;i++)
     if(Ans[i]<Ans[Depth])
       Max=max(Max,A[i]+1);
   if(Max!=A[Depth])
     return false;
   for(int i=0;i<Depth;i++)
     if(Ans[i]>Ans[Depth]&&B[i]<B[Depth]+1)
       return false;
   return true;
 }
 
 bool DFS(int Depth)
 {
   if(!Check(Depth-1))
     return false;
   if(Depth==N)
     {
       for(int i=0;i<N;i++)
         {
           int Max=1;
           for(int j=i+1;j<N;j++)
             if(Ans[i]>Ans[j])
               Max=max(Max,B[j]+1);
           if(Max!=B[i])
             return false;
         }
       for(int i=0;i<N;i++)
         printf(" %d",Ans[i]+1);
       putchar('\n');
       return true;
     }
   for(int i=0;i<N;i++)
     if(!Flag[i])
       {
         Flag[i]=true;
         Ans[Depth]=i;
         if(DFS(Depth+1))
           return true;
         Flag[i]=false;
       }
   return false;
 }
 
 int main()
 {
   int TotalTest=Get();
   for(int Test=1;Test<=TotalTest;Test++)
     {
       printf("Case #%d:",Test);
       N=Get();
       for(int i=0;i<N;i++)
         A[i]=Get();
       for(int i=0;i<N;i++)
         B[i]=Get();
       memset(Flag,0,sizeof(Flag));
       DFS(0);
     }
   return 0;
 }
