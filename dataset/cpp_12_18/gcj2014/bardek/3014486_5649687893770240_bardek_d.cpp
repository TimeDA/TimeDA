#include <cstdio>
 #include <algorithm>
 #include <string>
 #include <iostream>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 1001;
 vector<string> V;
 
 
 int n,m;
 int mask[20];
 int temp,bestans,sposobow;
 
 struct node
 {
 	node *N[26];
 	node ()	{fru(i,26) N[i]=NULL;}
 	~node () 
 	{
 		fru(i,26) if(N[i]) delete(N[i]);
 	}
 	bool ktos()
 	{
 		fru(i,26) if(N[i]) return 1;
 		return 0;
 	}
 	void insert(string &A, int p)
 	{
 		if(p==A.size()) return;
 		if(N[A[p]-'A']==NULL) 
 		{
 			N[A[p]-'A']=new node();
 			++temp;
 		}
 		N[A[p]-'A']->insert(A,p+1);
 	}
 };
 
 node *T[4];
 void go(int p)
 {
 	if(p==m)
 	{
 		temp=0;
 		fru(i,n) T[i]=new node();
 		fru(i,m) T[mask[i]]->insert(V[i],0);
 		fru(i,n) if(T[i]->ktos()) ++temp;
 		if(temp>bestans)
 		{
 			bestans=temp;
 			sposobow=0;
 		}
 		if(temp==bestans) sposobow++;
 		fru(i,n) delete(T[i]);
 		return;
 	}
 	fru(i,n)
 	{
 		mask[p]=i;
 		go(p+1);
 	}
 }
 int main()
 {
 	int o;
 	cin>>o;
 	fru(oo,o)
 	{
 		 sposobow=0;
 	  	 bestans=-1;
 		 printf("Case #%d: ",oo+1);
 		 cin>>m>>n;
 		 V.resize(m);
 		 fru(i,m) cin>>V[i];
 		 go(0);
 		 printf("%d %d\n",bestans,sposobow);
 	}
     return 0;
 }
