#include <cstdio>
 #include <string>
 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 10005;
 int tab[][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
 int zn[][4]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};
 
 
 pii op(pii a, pii b){
 		return pii(tab[a.x][b.x],zn[a.x][b.x]*a.y*b.y);
 }
 
 bool solve(string S){
 	pii CO[S.size()];
 	fru(i,S.size()) CO[i]=pii(S[i]=='i'?1:(S[i]=='j'?2:3),1);
 	pii X[S.size()+1];
 	X[S.size()]=pii(0,1);
 	for(int i=S.size()-1;i>=0;--i){
 		X[i]=op(CO[i],X[i+1]);
 	}
 	pii L(0,1);
 	fru(i,S.size()){
 		L=op(L,CO[i]);
 		pii R(0,1);
 		if(L==pii(1,1))
 		for(int j=i+1;j+1<S.size();++j){
 			R=op(R,CO[j]);
 			if(R==pii(2,1) && X[j+1]==pii(3,1)) return 1;
 			}
 	}
 	return 0;
 }
 int main()
 {
 //	tab[0]={0,1,2,3};
 	int o;
 	cin>>o;
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 int X,L;
 		 string s;
 		 cin>>L>>X>>s;
 		 string S="";
 		 fru(i,X) S=S+s;
 		 printf("%s\n",solve(S)?"YES":"NO");
 	}
     return 0;
 }
