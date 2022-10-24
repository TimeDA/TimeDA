//program A
 
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
 
 const int Mod=1000002013;
 
 long long Cost(long long N,long long X)
 {
   return X*N-X*(X-1)/2;
 }
 
 int main()
 {
   int TotalTest=Get();
   for(int Test=1;Test<=TotalTest;Test++)
     {
       printf("Case #%d: ",Test);
       int N=Get(),M=Get();
       static int X[100000],Y[100000],P[100000];
       long long Ans=0;
       for(int i=0;i<M;i++)
         {
           X[i]=Get();
           Y[i]=Get();
           P[i]=Get();
           Ans=(Ans+Cost(N,Y[i]-X[i])%Mod*P[i])%Mod;
         }
       bool Flag=true;
       while(Flag)
         {
           Flag=false;
           for(int i=0;i<M;i++)
             for(int j=i+1;j<M;j++)
               if(X[i]<=Y[j]&&X[j]<=Y[i]&&Cost(N,Y[j]-X[i])+Cost(N,Y[i]-X[j])<Cost(N,Y[i]-X[i])+Cost(N,Y[j]-X[j]))
                 {
                   if(P[i]>P[j])
                     {
                       X[M]=X[i];
                       Y[M]=Y[i];
                       P[M]=P[i]-P[j];
                       M++;
                       P[i]=P[j];
                     }
                   if(P[j]>P[i])
                     {
                       X[M]=X[j];
                       Y[M]=Y[j];
                       P[M]=P[j]-P[i];
                       M++;
                       P[j]=P[i];
                     }
                   swap(Y[i],Y[j]);
                   Flag=true;
                 }
         }
       for(int i=0;i<M;i++)
         Ans=(Ans-Cost(N,Y[i]-X[i])%Mod*P[i])%Mod;
       if(Ans<0)
         Ans+=Mod;
       cout<<Ans<<endl;
     }
   return 0;
 }
