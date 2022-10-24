#include<cstdio>
 #include<set>
 #include<algorithm>
 
 using namespace std;
 
 int naomi[1010],ken[1010];
 int N;
 
 int war(){
 	set<int> se;
 	for(int i=0;i<N;i++) se.insert(ken[i]);
 	int ans=0;
 	sort(naomi,naomi+N);
 	for(int i=0;i<N;i++){
 		set<int>::iterator it=se.lower_bound(naomi[i]);
 		if(it==se.end()){
 			set<int>::iterator it=se.begin();
 			se.erase(it);
 			ans++;
 		}else{
 			se.erase(it);
 		}
 	}
 	return ans;
 }
 
 bool deceitful(int num){
 	sort(naomi,naomi+N);
 	sort(ken,ken+N);
 	for(int i=0;i<num;i++){
 		if(naomi[i]>ken[N-num+i]) return false;
 	}
 	for(int i=num;i<N;i++) if(naomi[i]<ken[i-num]) return false;
 	return true;
 }
 
 int dec(){
 	int ans=-1;
 	for(int i=0;i<=N;i++){
 		bool flg=deceitful(i);
 		if(flg) ans=max(ans,N-i);
 	}
 	return ans;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		scanf("%d",&N);
 		for(int i=0;i<N;i++){
 			double in;
 			scanf("%lf",&in);
 			in*=100000;
 			in+=(1e-8);
 			naomi[i]=in;
 		}
 		for(int i=0;i<N;i++){
 			double in;
 			scanf("%lf",&in);
 			in*=100000;
 			in+=(1e-8);
 			ken[i]=in;
 		}
 		int a=dec();
 		int b=war();
 		printf("Case #%d: %d %d\n",datano+1,a,b);
 	}
 	return 0;
 }
