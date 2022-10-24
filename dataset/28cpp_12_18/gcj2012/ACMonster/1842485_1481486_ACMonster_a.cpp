//program A
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 int N,Final;
 int X[100],L[100];
 bool Visited[101][101];
 bool Flag[101][101];
 
 bool BFS(int Pos,int Hold)
 {
   if(Visited[Pos][Hold])return Flag[Pos][Hold];
   int Far=X[Hold]+min(X[Hold]-X[Pos],L[Hold]);
   if(Far>=Final)return true;
   if(Visited[Pos][Hold])return Flag[Pos][Hold];
   Visited[Pos][Hold]=Flag[Pos][Hold]=true;
   for(int i=Hold+1;i<=N;i++)
     if(Far>=X[i])
 	  if(BFS(Hold,i))return true;
   return Flag[Pos][Hold]=false;
 }
 
 int main()
 {
   freopen("Input.txt","r",stdin);
   freopen("Output.txt","w",stdout);
   int Total,Test=0;scanf("%d",&Total);
   while(Test++<Total)
     {
 	  scanf("%d",&N);
 	  X[0]=0;
 	  for(int i=1;i<=N;i++)
 	    scanf("%d%d",&X[i],&L[i]);
 	  scanf("%d",&Final);
 	  memset(Visited,0,sizeof(Visited));
 	  if(BFS(0,1))
 	    printf("Case #%d: YES\n",Test);
 	  else
 	    printf("Case #%d: NO\n",Test);
 	}
   return 0;
 }
