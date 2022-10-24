#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cstring>
 #include <string>
 #include <deque>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 1001;
 
 typedef pair<string,int> psi;
 char SS[11];
 psi T[2005];
 int n;
 int licz(int jak)
 {
 	fru(i,2*n) if(T[i].y) T[i].y=1;
 	int ret=n;
 	if(jak==1)fru(i,2*n) if(T[i].y==0)
 	{
 		int poz=-1;
 		for(int j=i+1;j<2*n;++j) if(T[j].y==1)
 		{
 			poz=j;
 			break;
 		}
 		if(poz!=-1)
 		{
 			--ret;
 			T[poz].y=2;
 		}
 	}
 	if(jak==0)
 	{
 		deque<int> A,B;
 		fru(i,2*n) if(T[i].y) B.push_back(i);
 		else A.push_back(i);
 		fru(i,n)
 		{
 			if(A[i]>B[0]) B.pop_front();
 			else 
 			{
 				B.pop_back();
 				--ret;
 			}
 		}
 
 	}
 	return ret;
 }
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		printf("Case #%d: ",oo+1);
 		int e=0;
 		scanf("%d",&n);
 		fru(q,2){
 			fru(i,n)
 			{
 				scanf(" %s",SS);
 				int a=strlen(SS);
 				while(a<10) SS[a++]='0';
 				SS[10]=0;
 				T[e++]=psi(string(SS),q);
 			}
 		}
 		sort(T,T+e);
 //		fru(i,e) printf("%s:: %d\n",T[i].x.c_str(),T[i].y);
 		printf("%d %d\n",licz(0),licz(1));
 	}
 	return 0;
 }
