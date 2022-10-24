#include<stdio.h>
 #include<algorithm>
 #include<unordered_set>
 #include<vector>
 long long get(char *s){
 	long long r=0;
 	while(*s){
 		r=(r<<5)|((*s++)-'a');
 	}
 	return r;
 }
 char s[1000001];
 std::vector<long long> x[1001];
 std::unordered_set<long long> E,F,EE,FF;
 int main(){
 	int i,j,k;
 	int T,TN;
 	
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int n,m_min,m_max,m_inc,m;
 		scanf("%d",&n);
 		E.clear();
 		F.clear();
 		
 		for(i=0;i<n;i++){
 			x[i].clear();
 			while(true){
 				scanf("%s",s);
 				int c=getchar();
 				x[i].push_back(get(s));
 				if(c=='\n')break;
 			}
 			for(j=0;j<x[i].size();j++){
 				printf("%lld ",x[i][j]);
 			}
 			puts("");	
 		}
 		for(j=0;j<x[0].size();j++){
 			E.insert(x[0][j]);
 		}
 		for(j=0;j<x[1].size();j++){
 			F.insert(x[1][j]);
 		}
 		m_min=2;
 		m_max=1<<n;
 		m_inc=4;
 		int ans=10000000;
 		for(m=m_min;m<m_max;m+=m_inc){
 			EE.clear();
 			FF.clear();
 			for(i=0;i<n;i++){
 				for(j=0;j<x[i].size();j++){
 					if(m&(1<<i)){
 						FF.insert(x[i][j]);
 					} else {
 						EE.insert(x[i][j]);
 					}
 				}
 			}
 			int cnt=0;
 			for(auto it=EE.begin();it!=EE.end();++it){
 				if(FF.find(*it)!=FF.end()){
 					cnt++;
 				}
 			}
 			printf("%d\n",cnt);
 			if(ans>cnt)ans=cnt;
 		}
 			printf("Case #%d: %d\n",T,ans);
 				fprintf(stderr,"Case #%d: %d\n",T,ans);
 	}
 }
