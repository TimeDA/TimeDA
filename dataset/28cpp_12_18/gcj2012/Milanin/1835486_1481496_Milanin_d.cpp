#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 100
 #define L 1100
 int m[N][N];
 char s[L];
 bool is(char c) { return c=='o' || c=='i' || c=='e' || c=='a' || c=='s' || c=='t' || c=='b' || c=='g'; }
 int main()
 {
 	int n, r, i, j, k, ts, tst;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		for(i=0; i<N; i++)
 			for(j=0; j<N; m[i][j]=0, j++);
 		for(scanf("%d%s", &k, s), n=0; s[n]; n++);
 		if(n==1) printf("%d\n", 1+is(s[0]));
 		else
 		{
 			for(i=0; i<n-1; i++)
 				if(is(s[i]) && is(s[i+1])) { m[s[i]-'a'][s[i+1]-'a']=1; m[s[i]-'a'][s[i+1]-'a'+26]=1; m[s[i]-'a'+26][s[i+1]-'a']=1; m[s[i]-'a'+26][s[i+1]-'a'+26]=1; }
 				else if(is(s[i])) { m[s[i]-'a'][s[i+1]-'a']=1; m[s[i]-'a'+26][s[i+1]-'a']=1; }
 				else if(is(s[i+1])) { m[s[i]-'a'][s[i+1]-'a']=1; m[s[i]-'a'][s[i+1]-'a'+26]=1; }
 				else m[s[i]-'a'][s[i+1]-'a']=1;
 			for(r=0, i=0; i<N; r+=k>0?k:0, i++)
 				for(k=0, j=0; j<N; k+=m[i][j]-m[j][i], j++);
 			if(r>0) r--;
 			for(i=0; i<N; i++)
 				for(j=0; j<N; r+=m[i][j], j++);
 			printf("%d\n", r+1);
 		}
 	}
 	return 0;
 }