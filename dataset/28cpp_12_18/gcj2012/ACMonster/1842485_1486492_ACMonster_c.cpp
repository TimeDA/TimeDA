//program C
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 const int Max=6;
 
 int N;
 int X[10];
 int Ans[10];
 
 bool OK(int T,int H)
 {
   for(int i=0;i<T;i++)
     if(X[i]<T)
       {
 	    int j=T,k=X[i];//i<k<j
 		if((k-i)*H+(j-k)*Ans[i]+(i-j)*Ans[k]>0)return false;
 	  }
   for(int i=0;i<T;i++)
     if(X[i]==T)
 	  for(int j=i+1;j<T;j++)
 	    {
 		  int k=T;//i<j<k
 		  if((k-i)*Ans[j]+(j-k)*Ans[i]+(i-j)*H>=0)return false;
 		}
   return true;
 }
 
 bool DFS(int Depth)
 {
   if(Depth==N)return true;
   for(int i=1;i<N*2;i++)
     if(OK(Depth,i))
 	  {
 	    Ans[Depth]=i;
 	    if(DFS(Depth+1))return true;
 	  }
   return false;
 }
 
 int main()
 {
   freopen("Input.txt","r",stdin);
   freopen("Output.txt","w",stdout);
   int Total,Test=0;scanf("%d",&Total);
   while(Test++<Total)
     {
 	  scanf("%d",&N);
 	  for(int i=0;i<N-1;i++)
 	    {
 		  scanf("%d",&X[i]);
 		  X[i]--;
 		}
 	  bool OK=true;
 	  for(int i=0;i<N-1;i++)
 	    for(int j=i+1;j<X[i];j++)
 		  if(X[j]>X[i])
 		    OK=false;
 	  if(OK&&DFS(0))
 	    {
 		  printf("Case #%d:",Test);
 		  for(int i=0;i<N;i++)printf(" %d",Ans[i]);
 		  putchar('\n');
 		}
 	  else
 	    printf("Case #%d: Impossible\n",Test);
 	}
   return 0;
 }
