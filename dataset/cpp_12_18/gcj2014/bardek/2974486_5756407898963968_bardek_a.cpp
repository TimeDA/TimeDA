#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 1001;
 
 int T[4][4];
 
 int ile[17];
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		printf("Case #%d: ",oo+1);
 		fru(i,17) ile[i]=0;
 		fru(k,2)
 		{
 			int e;
 			scanf("%d",&e);
 			fru(i,4) fru(j,4) scanf("%d",&T[i][j]);
 			fru(i,4) ile[T[e-1][i]]++;
 		}
 		int res=0,g=-1;
 		fru(j,17) if(ile[j]==2) ++res,g=j;
 		if(res==0) printf("Volunteer cheated!\n");
 		else if(res==1) printf("%d\n",g);
 		else printf("Bad magician!\n");
 	}
 	return 0;
 }
