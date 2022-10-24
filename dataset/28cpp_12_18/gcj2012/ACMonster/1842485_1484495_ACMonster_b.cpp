//program B
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 const int MaxTry=20;
 
 int X[10],Y[10],R[10];
 
 int Random(int X)
 {
   long long S=0;
   for(int i=0;i<10;i++)
     S=(S*10+rand()%10)%X;
   return (int)S;
 }
 
 bool Check(int T)
 {
   for(int i=0;i<T;i++)
     if(max(abs(X[i]-X[T]),abs(Y[i]-Y[T]))<R[i]+R[T])
 	  return false;
   return true;
 }
 
 int main()
 {
   freopen("Input.txt","r",stdin);
   freopen("Output.txt","w",stdout);
   int Total,Test=0;scanf("%d",&Total);
   srand((unsigned)time(NULL));
   while(Test++<Total)
     {
 	  int N,W,H;scanf("%d%d%d",&N,&W,&H);
 	  for(int i=0;i<N;i++)scanf("%d",&R[i]);
 	  bool OK=false;
 	  while(!OK)
 	    {
 		  X[0]=0;Y[0]=0;OK=true;
 		  for(int j=1;OK&&j<N;j++)
 		    {
 			  OK=false;
 			  for(int k=0;!OK&&k<MaxTry;k++)
 			    {
 				  X[j]=Random(W+1);
 				  Y[j]=Random(H+1);
 				  OK=Check(j);
 				}
 			}
 		}
 	  printf("Case #%d:",Test);
 	  for(int i=0;i<N;i++)printf(" %d %d",X[i],Y[i]);
 	  putchar('\n');
 	}
   return 0;
 }
