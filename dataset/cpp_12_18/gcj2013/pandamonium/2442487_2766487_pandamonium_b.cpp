#include <cstdio>
 #include <cstring>
 using namespace std;
 int t;
 int cnt=0;
 long long n,p;
 long long best(long long r,long long num){
 	if(r==0) return 1;
 	if(r==(1<<num)-1) return (1<<num);
 	return best((r+1)/2,num-1);
 }
 long long worst(long long r,long long num){
 	if(r==0) return 1;
 	if(r==(1<<num)-1) return (1<<num);
 	return worst((r-1)/2,num-1)+(1<<(num-1));
 }
 long long searchworst(long long s, long long e){
 	if(s==e) return s;
 	long long m=(s+e)/2+1;
 	if(worst(m,n)>p) searchworst(s,m-1);
 	else return searchworst(m,e);
 }
 long long searchbest(long long s, long long e){
 	if(s==e) return s;
 	long long m=(s+e)/2+1;
 	if(best(m,n)>p) searchbest(s,m-1);
 	else return searchbest(m,e);
 }
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		scanf("%lld %lld",&n,&p);
 		cnt++;
 		printf("Case #%d: %lld %lld\n",cnt,searchworst(0,(1<<n)-1),searchbest(0,(1<<n)-1));
 	}
 	return 0;
 }
