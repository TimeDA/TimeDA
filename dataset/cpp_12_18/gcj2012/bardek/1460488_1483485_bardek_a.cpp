#include <cstdio>
 #include <algorithm>
 #include <string>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 1001;
 char M[300];
 #include <set>
 string A = 
 "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvazo",B=
 "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upyqe";
 char lit(char a)
 {
 	fru(i,A.size()) if(A[i]==a) return B[i];
 	return 'z';
 }
 int main()
 {
 	int o;
 	scanf("%d\n",&o);
 	fru(oo,o)
 	{
 		 printf("Case #%d: ",oo+1);
 		 while(1)
 		 {
 			 char c;
 			 scanf("%c",&c);
 			 if(c=='\n') break;
 			 printf("%c",lit(c));
 		 }
 		 printf("\n");
 
 
 	}
     return 0;
 }
